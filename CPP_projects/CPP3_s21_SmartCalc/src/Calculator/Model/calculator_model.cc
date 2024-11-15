#include "calculator_model.h"

using namespace s21;

double CalculatorModel::GetResult(std::string &str, double x_value) {
  std::queue<s21::lexeme> input_que;
  std::queue<s21::lexeme> output_que;
  MakeLexemeQue(str, x_value, input_que);
  PolishNotation(input_que, output_que);
  Calculation(output_que);
  return this->res;
}

void CalculatorModel::Calculation(std::queue<s21::lexeme> &polish_que) {
  std::stack<s21::lexeme> stack;
  lexeme elem;
  double res = 0;
  double num1 = 0;
  double num2 = 0;
  while (!polish_que.empty()) {
    elem = polish_que.front();
    polish_que.pop();
    if (elem.type == t_number || elem.type == t_x) {
      stack.push(elem);
    } else if (IsOperator(elem.type)) {
      num1 = stack.top().value;
      stack.pop();
      num2 = stack.top().value;
      stack.pop();
      switch (elem.type) {
        case t_plus:
          res = num2 + num1;
          break;
        case t_minus:
          res = num2 - num1;
          break;
        case t_mul:
          res = num2 * num1;
          break;
        case t_div:
          res = num2 / num1;
          break;
        case t_mod:
          res = fmod(num2, num1);
          break;
        case t_pow:
          res = pow(num2, num1);
          break;
        default:
          break;
      }
      stack.push(lexeme{res, 0, t_number});
    } else if (IsFunction(elem.type)) {
      num1 = stack.top().value;
      stack.pop();
      switch (elem.type) {
        case t_cos:
          res = cos(num1);
          break;
        case t_sin:
          res = sin(num1);
          break;
        case t_sqrt:
          res = sqrt(num1);
          break;
        case t_tan:
          res = tan(num1);
          break;
        case t_acos:
          res = acos(num1);
          break;
        case t_asin:
          res = asin(num1);
          break;
        case t_atan:
          res = atan(num1);
          break;
        case t_ln:
          res = log(num1);
          break;
        case t_log:
          res = log10(num1);
          break;
        default:
          break;
      }
      stack.push(lexeme{res, 0, t_number});
    }
  }
  res = stack.top().value;
  stack.pop();
  this->res = res;
}

void CalculatorModel::PolishNotation(std::queue<s21::lexeme> &input_que,
                                     std::queue<s21::lexeme> &output_que) {
  std::stack<s21::lexeme> stack;
  lexeme elem;
  while (!input_que.empty()) {
    if (input_que.front().type == t_open_bracket ||
        IsFunction(input_que.front().type)) {
      elem = input_que.front();
      stack.push(elem);
      input_que.pop();
    } else if (input_que.front().type == t_number ||
               input_que.front().type == t_x) {
      elem = input_que.front();
      output_que.push(elem);
      input_que.pop();
    } else if (input_que.front().type == t_close_braket) {
      input_que.pop();
      while (stack.top().type != t_open_bracket) {
        elem = stack.top();
        stack.pop();
        output_que.push(elem);
      }
      stack.pop();
      if (!stack.empty() && IsFunction(stack.top().type)) {
        elem = stack.top();
        stack.pop();
        output_que.push(elem);
      }
    } else if (IsOperator(input_que.front().type)) {
      while (!stack.empty() && IsOperator(stack.top().type) &&
             stack.top().priority >= input_que.front().priority) {
        elem = stack.top();
        output_que.push(elem);
        stack.pop();
      }
      elem = input_que.front();
      stack.push(elem);
      input_que.pop();
    }
  }
  while (!stack.empty()) {
    elem = stack.top();
    output_que.push(elem);
    stack.pop();
  }
}

bool CalculatorModel::IsOperator(enum lexeme_type type) {
  return type == t_minus || type == t_plus || type == t_div || type == t_mul ||
         type == t_mod || type == t_pow;
}

bool CalculatorModel::IsFunction(enum lexeme_type type) {
  return type == t_cos || type == t_sin || type == t_tan || type == t_acos ||
         type == t_asin || type == t_atan || type == t_sqrt || type == t_log ||
         type == t_ln;
}

void CalculatorModel::MakeLexemeQue(std::string &str, double x_value,
                                    std::queue<s21::lexeme> &que) {
  std::size_t i = 0;
  double number = 0;
  while (i < str.length()) {
    switch (str[i]) {
      case t_open_bracket:
        que.push(lexeme{0, -1, t_open_bracket});
        ++i;
        break;
      case t_close_braket:
        que.push(lexeme{0, -1, t_close_braket});
        ++i;
        break;
      case t_plus:
        if (str[i - 1] == '(') {
          que.push(lexeme{0, 0, t_number});
        }
        que.push(lexeme{0, 1, t_plus});
        ++i;
        break;
      case t_minus:
        if (str[i - 1] == '(') {
          que.push(lexeme{0, 0, t_number});
        }
        que.push(lexeme{0, 1, t_minus});
        ++i;
        break;
      case t_mul:
        que.push(lexeme{0, 2, t_mul});
        ++i;
        break;
      case t_div:
        que.push(lexeme{0, 2, t_div});
        ++i;
        break;
      case t_mod:
        que.push(lexeme{0, 2, t_mod});
        i += 3;
        break;
      case t_pow:
        que.push(lexeme{0, 3, t_pow});
        ++i;
        break;
      case 'c':
        que.push(lexeme{0, 4, t_cos});
        i += 3;
        break;
      case 's':
        if (str[i + 1] == 'i') {
          que.push(lexeme{0, 4, t_sin});
          i += 3;
        } else if (str[i + 1] == 'q') {
          que.push(lexeme{0, 4, t_sqrt});
          i += 4;
        }
        break;
      case t_tan:
        que.push(lexeme{0, 4, t_tan});
        i += 3;
        break;
      case 'l':
        if (str[i + 1] == 'n') {
          que.push(lexeme{0, 4, t_ln});
          i += 2;
        } else if (str[i + 1] == 'o') {
          que.push(lexeme{0, 4, t_log});
          i += 3;
        }
        break;
      case 'a':
        if (str[i + 1] == 'c') {
          que.push(lexeme{0, 4, t_acos});
          i += 4;
        } else if (str[i + 1] == 's') {
          que.push(lexeme{0, 4, t_asin});
          i += 4;
        } else if (str[i + 1] == 't') {
          que.push(lexeme{0, 4, t_atan});
          i += 4;
        }
        break;
      case 'x':
        que.push(lexeme{x_value, 0, t_x});
        ++i;
        break;
      default:
        sscanf(str.c_str() + i, "%lf", &number);
        que.push(lexeme{number, 0, t_number});
        i = i + NumLen(str.c_str() + i);
        break;
    }
  }
}

std::size_t CalculatorModel::NumLen(const char *str) {
  std::size_t len = 0;
  while ((*str >= '0' && *str <= '9') || *str == '.') {
    ++len;
    ++str;
  }
  return len;
}

void CalculatorModel::XStringValidation(std::string x_val) {
  std::size_t float_point = 0;
  std::size_t x_max_len = 16;
  DeleteSpaces(x_val);
  if (x_val.length() > x_max_len) {
    throw std::invalid_argument("Input error!");
  }
  for (std::size_t i = 0; i < x_val.length(); ++i) {
    if (x_val[i] == '.') {
      PointValidation(x_val, i, float_point);
      float_point = 1;
    } else if (x_val[i] == '-') {
      if (i != 0 || !CheckOnNumber(x_val[i + 1])) {
        throw std::invalid_argument("Input error!");
      }
    } else if (!CheckOnNumber(x_val[i])) {
      throw std::invalid_argument("Input error!");
    } else if (CheckOnNumber(x_val[i])) {
      if (i != 0 && !CheckOnNumber(x_val[i - 1]) && x_val[i - 1] != '.' &&
          x_val[i - 1] != '-') {
        throw std::invalid_argument("Input error!");
      }
      if (i != x_val.length() - 1 && !CheckOnNumber(x_val[i + 1]) &&
          x_val[i + 1] != '.') {
        throw std::invalid_argument("Input error!");
      }
    }
  }
}

void CalculatorModel::StrValidation(std::string &str) {
  std::size_t float_point = 0;
  DeleteSpaces(str);   //удаление пробельных символов
  LenValidation(str);  // проверка длины строки
  BracketsValidation(str);  //проверка скобок
  for (std::size_t i = 0; i < str.length(); ++i) {
    if (str[i] == '.') {  //проверка точки
      PointValidation(str, i, float_point);
      float_point = 1;
    } else if (CheckOnOperator(str[i])) {  // проверка оператора
      float_point = 0;
      OperatorValidation(str, i);
    } else if (CheckOnNumber(str[i])) {  // проверка числа
      NumberValidation(str, i);
    } else if (str[i] == 'x') {  // проверка x
      XValidation(str, i);
    } else if (ValidFunction(str, i)) {  // проверка функции
      float_point = 0;
    } else if (CheckOnMod(str, i)) {  // проверка mod
      ValidMod(str, i);
      i += 2;
      float_point = 0;
    } else if (str[i] != '(' && str[i] != ')') {
      throw std::invalid_argument("Input error!");
    }
  }
}

void CalculatorModel::DeleteSpaces(std::string &str) {
  std::string new_str;
  for (std::string::iterator start = str.begin(); start != str.end(); ++start) {
    if (*start != '\n' && *start != ' ' && *start != '\t') {
      new_str += *start;
    }
  }
  str = new_str;
}

void CalculatorModel::LenValidation(std::string &str) {
  std::size_t len = str.length();
  if (len > 255 || len < 3) {
    throw std::invalid_argument("Input error!");
  }
}

void CalculatorModel::BracketsValidation(std::string &str) {
  int brackets = 0;
  for (std::size_t i = 0; i < str.length() /*&&!error*/; ++i) {
    if (str[i] == '(') {
      ++brackets;
      if (str[i + 1] == ')') {
        throw std::invalid_argument("Input error!");
      }
    }
    if (str[i] == ')') {
      --brackets;
    }
    if (brackets < 0) {
      throw std::invalid_argument("Input error!");
    }
  }
  if (brackets) {
    throw std::invalid_argument("Input error!");
  }
}

void CalculatorModel::PointValidation(std::string &str, std::size_t i,
                                      std::size_t float_point) {
  if (i == 0 || i == str.length() - 1) {
    throw std::invalid_argument("Input error!");
  }
  if (float_point) {
    throw std::invalid_argument("Input error!");
  } else if (!(str[i + 1] >= '0' && str[i + 1] <= '9') ||
             !(str[i - 1] >= '0' && str[i - 1] <= '9')) {
    throw std::invalid_argument("Input error!");
  }
}

int CalculatorModel::CheckOnOperator(char symbol) {
  return symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
         symbol == '^';
}

void CalculatorModel::OperatorValidation(std::string &str, std::size_t i) {
  std::size_t i_for_check_func = i + 1;
  if (str[i + 1] != '(' && !CheckOnNumber(str[i + 1]) && str[i + 1] != 'x' &&
      !ValidFunction(str, i_for_check_func)) {
    throw std::invalid_argument("Input error!");
  }
  if (str[i] == '+' || str[i] == '-') {
    if (str[i - 1] != '(' && str[i - 1] != ')' && !CheckOnNumber(str[i - 1]) &&
        str[i - 1] != 'x') {
      throw std::invalid_argument("Input error!");
    }
  } else {
    if (str[i - 1] != ')' && !CheckOnNumber(str[i - 1]) && str[i - 1] != 'x') {
      throw std::invalid_argument("Input error!");
    }
  }
}

int CalculatorModel::CheckOnNumber(char symbol) {
  return (symbol >= '0' && symbol <= '9');
}

void CalculatorModel::NumberValidation(std::string &str, std::size_t i) {
  if (!CheckOnOperator(str[i + 1]) && i != str.length() - 1 &&
      !CheckOnMod(str, i + 1) && str[i + 1] != '.' &&
      !CheckOnNumber(str[i + 1]) && str[i + 1] != ')') {
    throw std::invalid_argument("Input error!");
  }
  if (i != 0 && !CheckOnOperator(str[i - 1]) && !CheckOnMod(str, i - 1) &&
      str[i - 1] != '.' && !CheckOnNumber(str[i - 1]) && str[i - 1] != '(') {
    throw std::invalid_argument("Input error!");
  }
}

void CalculatorModel::XValidation(std::string &str, std::size_t i) {
  if (!CheckOnOperator(str[i + 1]) && i != str.length() - 1 &&
      !CheckOnMod(str, i + 1) && str[i + 1] != ')') {
    throw std::invalid_argument("Input error!");
  }
  if (i != 0 && !CheckOnOperator(str[i - 1]) && !CheckOnMod(str, i - 1) &&
      !CheckOnNumber(str[i - 1]) && str[i - 1] != '(') {
    throw std::invalid_argument("Input error!");
  }
}

int CalculatorModel::ValidFunction(std::string &str, std::size_t &i) {
  int flag = 0;
  switch (str[i]) {
    case 'c':
      if (str[i + 1] == 'o' && str[i + 2] == 's' && str[i + 3] == '(') {
        flag = 1;
        MicrovalidFunction(str, i);
        i += 3;
      }
      break;
    case 's':
      if (str[i + 1] == 'i' && str[i + 2] == 'n' && str[i + 3] == '(') {
        flag = 1;
        MicrovalidFunction(str, i);
        i += 3;
      }
      if (str[i + 1] == 'q' && str[i + 2] == 'r' && str[i + 3] == 't' &&
          str[i + 4] == '(') {
        flag = 1;
        MicrovalidFunction(str, i);
        i += 4;
      }
      break;
    case 't':
      if (str[i + 1] == 'a' && str[i + 2] == 'n' && str[i + 3] == '(') {
        flag = 1;
        MicrovalidFunction(str, i);
        i += 3;
      }
      break;

    case 'l':
      if (str[i + 1] == 'n' && str[i + 2] == '(') {
        flag = 1;
        MicrovalidFunction(str, i);
        i += 2;
      }
      if (str[i + 1] == 'o' && str[i + 2] == 'g' && str[i + 3] == '(') {
        flag = 1;
        MicrovalidFunction(str, i);
        i += 3;
      }
      break;
    case 'a':
      if (str[i + 1] == 'c' && str[i + 2] == 'o' && str[i + 3] == 's' &&
          str[i + 4] == '(') {
        flag = 1;
        MicrovalidFunction(str, i);
        i += 4;
      }
      if (str[i + 1] == 's' && str[i + 2] == 'i' && str[i + 3] == 'n' &&
          str[i + 4] == '(') {
        flag = 1;
        MicrovalidFunction(str, i);
        i += 4;
      }
      if (str[i + 1] == 't' && str[i + 2] == 'a' && str[i + 3] == 'n' &&
          str[i + 4] == '(') {
        flag = 1;
        MicrovalidFunction(str, i);
        i += 4;
      }
      break;
  }
  return flag;
}

void CalculatorModel::MicrovalidFunction(std::string &str, std::size_t i) {
  if (i != 0 && !CheckOnOperator(str[i - 1]) && !CheckOnMod(str, i - 1) &&
      str[i - 1] != '(') {
    throw std::invalid_argument("Input error!");
  }
}

int CalculatorModel::CheckOnMod(std::string &str, std::size_t i) {
  int yes_mod = 0;
  if (str[i] == 'm') {
    yes_mod = (str[i + 1] == 'o' && str[i + 2] == 'd');
  } else if (str[i] == 'd') {
    yes_mod = (str[i - 1] == 'o' && str[i - 2] == 'm');
  }
  return yes_mod;
}

void CalculatorModel::ValidMod(std::string &str, int i) {
  std::size_t i_for_check_func = i + 3;
  if (str[i - 1] != ')' && !CheckOnNumber(str[i - 1]) && str[i - 1] != 'x') {
    throw std::invalid_argument("Input error!");
  }
  if (str[i + 3] != '(' && !CheckOnNumber(str[i + 3]) && str[i + 3] != 'x' &&
      !ValidFunction(str, i_for_check_func)) {
    throw std::invalid_argument("Input error!");
  }
}

void CalculatorModel::GraphicValid(double xMin, double xMax, double yMin,
                                   double yMax) {
  if (xMin >= xMax || yMin >= yMax) {
    throw std::invalid_argument("Input error!");
  }
  if (xMin < -1000000 || xMax > 1000000 || yMin < -1000000 || yMax > 1000000) {
    throw std::invalid_argument("Input error!");
  }
}
