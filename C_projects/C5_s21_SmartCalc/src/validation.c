#include "validation.h"

int validation_str(char *str) {
  int error = 0;
  int len_str = 0;
  int float_point = 0;
  delete_spaces(str);
  error = len_validation(str, &len_str);  // проверка длины строки
  if (!error) {
    error = brackets_validation(str);  //проверка скобок
  }
  for (int i = 0; str[i] != '\0' && !error; i++) {
    if (str[i] == '.') {  //проверка точки
      error = point_validation(str, i, len_str, float_point);
      float_point = 1;
    } else if (check_on_number(str[i])) {  // проверка числа
      error = number_validation(str, i);
      // fprintf(stderr, "error in number == %d\n", error);
    } else if (check_on_operator(str[i])) {  // проверка оператора
      float_point = 0;
      error = operator_validation(str, i);
      // fprintf(stderr, "error in oper == %d\n", error);
    } else if (str[i] == 'x') {  //проверка на х
      error = x_validation(str, i);
      // fprintf(stderr, "error in x == %d\n", error);
    } else if (valid_function(str, &i, &error)) {  // проверка функции
      float_point = 0;
      // fprintf(stderr, "error in func == %d\n", error);
    } else if (check_on_mod(str, i)) {  // проверка mod
      error = valid_mod(str, i);
      // fprintf(stderr, "str[i] == %c error in mod == %d\n", str[i], error);
      i += 2;
      float_point = 0;
    } else if (str[i] != '(' && str[i] != ')') {
      error = 1;
      // fprintf(stderr, "error in last == %d\n", error);
    }
  }
  return error;
}

int valid_mod(char *str, int i) {
  int error = 0;
  int i_for_check_func = i + 3;
  if (str[i - 1] != ')' && !check_on_number(str[i - 1]) && str[i - 1] != 'x') {
    // fprintf(stderr, "we are in first if\n");
    error = 1;
  }
  if (str[i + 3] != '(' && !check_on_number(str[i + 3]) && str[i - 1] != 'x' &&
      !valid_function(str, &i_for_check_func, &error)) {
    error = 1;
    // fprintf(stderr, "we are in 2 if\n");
  }
  return error;
}

void delete_spaces(char *str) {
  int i = 0;
  int shift = 0;
  while (str[i] != '\0') {
    if (str[i] == '\n' || str[i] == ' ' || str[i] == '\t') {
      shift++;
    } else {
      str[i - shift] = str[i];
    }
    i++;
  }
  str[i - shift] = '\0';
}

int len_validation(char *str, int *len_str) {
  int error = 0;
  *len_str = strlen(str);
  if (*len_str > 255 || *len_str < 3) {
    error = 1;
  }
  return error;
}

int brackets_validation(char *str) {
  int error = 0;
  int brackets = 0;
  for (int i = 0; str[i] != '\0' && !error; i++) {
    if (str[i] == '(') {
      brackets++;
      if (str[i + 1] == ')') {
        error = 1;
      }
    }
    if (str[i] == ')') {
      brackets--;
    }
    if (brackets < 0) {
      error = 1;
    }
  }
  if (brackets) {
    error = 1;
  }
  return error;
}

int point_validation(char *str, int i, int len_str, int float_point) {
  int error = 0;
  if (i == 0 || i == len_str - 1) {
    error = 1;
  }
  if (float_point) {
    error = 1;
  } else if (!(str[i + 1] >= '0' && str[i + 1] <= '9') ||
             !(str[i - 1] >= '0' && str[i - 1] <= '9')) {
    error = 1;
  }
  return error;
}

int number_validation(char *str, int i) {
  int error = 0;
  if (!check_on_operator(str[i + 1]) && str[i + 1] != '\0' &&
      !check_on_mod(str, i + 1) && str[i + 1] != '.' &&
      !check_on_number(str[i + 1]) && str[i + 1] != ')') {
    error = 1;
  }
  if (i != 0 && !check_on_operator(str[i - 1]) && !check_on_mod(str, i - 1) &&
      str[i - 1] != '.' && !check_on_number(str[i - 1]) && str[i - 1] != '(') {
    error = 1;
  }
  return error;
}

int x_validation(char *str, int i) {
  int error = 0;
  if (!check_on_operator(str[i + 1]) && str[i + 1] != '\0' &&
      !check_on_mod(str, i + 1) && str[i + 1] != ')') {
    error = 1;
  }
  if (i != 0 && !check_on_operator(str[i - 1]) && !check_on_mod(str, i - 1) &&
      !check_on_number(str[i - 1]) && str[i - 1] != '(') {
    error = 1;
  }
  return error;
}

int operator_validation(char *str, int i) {
  int error = 0;
  int i_for_check_func = i + 1;
  if (str[i + 1] != '(' && !check_on_number(str[i + 1]) && str[i + 1] != 'x' &&
      !valid_function(str, &i_for_check_func, &error)) {
    error = 1;
  }
  if (str[i] == '+' || str[i] == '-') {
    if (str[i - 1] != '(' && str[i - 1] != ')' &&
        !check_on_number(str[i - 1]) && str[i - 1] != 'x') {
      error = 1;
    }
  } else {
    if (str[i - 1] != ')' && !check_on_number(str[i - 1]) &&
        str[i - 1] != 'x') {
      error = 1;
    }
  }
  return error;
}

int check_on_number(char symbol) { return (symbol >= '0' && symbol <= '9'); }

int check_on_operator(char symbol) {
  return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
         symbol == '^';
}

int check_on_mod(char *str, int i) {
  int yes_mod = 0;
  if (str[i] == 'm') {
    yes_mod = (str[i + 1] == 'o' && str[i + 2] == 'd');
  } else if (str[i] == 'd') {
    yes_mod = (str[i - 1] == 'o' && str[i - 2] == 'm');
  }
  return yes_mod;
}

int valid_function(char *str, int *i, int *error) {
  int flag = 0;
  switch (str[*i]) {
    case 'c':
      if (str[*i + 1] == 'o' && str[*i + 2] == 's' && str[*i + 3] == '(') {
        flag = 1;
        *error = microvalid_function(str, *i);
        *i += 3;
      }
      break;
    case 's':
      if (str[*i + 1] == 'i' && str[*i + 2] == 'n' && str[*i + 3] == '(') {
        flag = 1;
        *error = microvalid_function(str, *i);
        *i += 3;
      }
      if (str[*i + 1] == 'q' && str[*i + 2] == 'r' && str[*i + 3] == 't' &&
          str[*i + 4] == '(') {
        flag = 1;
        *error = microvalid_function(str, *i);
        *i += 4;
      }
      break;
    case 't':
      if (str[*i + 1] == 'a' && str[*i + 2] == 'n' && str[*i + 3] == '(') {
        flag = 1;
        *error = microvalid_function(str, *i);
        *i += 3;
      }
      break;

    case 'l':
      if (str[*i + 1] == 'n' && str[*i + 2] == '(') {
        flag = 1;
        *error = microvalid_function(str, *i);
        *i += 2;
      }
      if (str[*i + 1] == 'o' && str[*i + 2] == 'g' && str[*i + 3] == '(') {
        flag = 1;
        *error = microvalid_function(str, *i);
        *i += 3;
      }
      break;
    case 'a':
      if (str[*i + 1] == 'c' && str[*i + 2] == 'o' && str[*i + 3] == 's' &&
          str[*i + 4] == '(') {
        flag = 1;
        *error = microvalid_function(str, *i);
        *i += 4;
      }
      if (str[*i + 1] == 's' && str[*i + 2] == 'i' && str[*i + 3] == 'n' &&
          str[*i + 4] == '(') {
        flag = 1;
        *error = microvalid_function(str, *i);
        *i += 4;
      }
      if (str[*i + 1] == 't' && str[*i + 2] == 'a' && str[*i + 3] == 'n' &&
          str[*i + 4] == '(') {
        flag = 1;
        *error = microvalid_function(str, *i);
        *i += 4;
      }
      break;
  }
  return flag;
}

int microvalid_function(char *str, int i) {
  return i != 0 && !check_on_operator(str[i - 1]) &&
         !check_on_mod(str, i - 1) && str[i - 1] != '(';
}

int graphic_valid(double xMin, double xMax, double yMin, double yMax) {
  int error = 0;
  if (xMin >= xMax || yMin >= yMax) {
    error = 1;
  }
  if (xMin < -1000000 || xMax > 1000000 || yMin < -1000000 || yMax > 1000000) {
    error = 1;
  }
  return error;
}
