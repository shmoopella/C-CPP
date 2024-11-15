#include "parcer.h"

queue *make_list(char *str, queue *first, double x_value) {
  int i = 0;
  double number = 0;
  while (str[i] != '\0') {
    switch (str[i]) {
      case t_open_bracket:
        first = push_q(first, 0, -1, t_open_bracket);
        i++;
        break;
      case t_close_braket:
        first = push_q(first, 0, -1, t_close_braket);
        i++;
        break;
      case t_plus:
        if (str[i - 1] == '(') {
          first = push_q(first, 0, 0, t_number);
        }
        first = push_q(first, 0, 1, t_plus);
        i++;
        break;
      case t_minus:
        if (str[i - 1] == '(') {
          first = push_q(first, 0, 0, t_number);
        }
        first = push_q(first, 0, 1, t_minus);
        i++;
        break;
      case t_mul:
        first = push_q(first, 0, 2, t_mul);
        i++;
        break;
      case t_div:
        first = push_q(first, 0, 2, t_div);
        i++;
        break;
      case t_mod:
        first = push_q(first, 0, 2, t_mod);
        i += 3;
        break;
      case t_pow:
        first = push_q(first, 0, 3, t_pow);
        i++;
        break;
      case 'c':
        first = push_q(first, 0, 4, t_cos);
        i += 3;
        break;
      case 's':
        if (str[i + 1] == 'i') {
          first = push_q(first, 0, 4, t_sin);
          i += 3;
        } else if (str[i + 1] == 'q') {
          first = push_q(first, 0, 4, t_sqrt);
          i += 4;
        }
        break;
      case t_tan:
        first = push_q(first, 0, 4, t_tan);
        i += 3;
        break;
      case 'l':
        if (str[i + 1] == 'n') {
          first = push_q(first, 0, 4, t_ln);
          i += 2;
        } else if (str[i + 1]) {
          first = push_q(first, 0, 4, t_log);
          i += 3;
        }
        break;
      case 'a':
        if (str[i + 1] == 'c') {
          first = push_q(first, 0, 4, t_acos);
          i += 4;
        } else if (str[i + 1] == 's') {
          first = push_q(first, 0, 4, t_asin);
          i += 4;
        } else if (str[i + 1] == 't') {
          first = push_q(first, 0, 4, t_atan);
          i += 4;
        }
        break;
      case 'x':
        first = push_q(first, x_value, 0, t_x);
        i++;
        break;
      default:
        sscanf(str + i, "%lf", &number);
        first = push_q(first, number, 0, t_number);
        i = i + num_len(str + i);
        break;
    }
  }
  return first;
}

int num_len(char *str) {
  int len = 0;
  while ((*str >= '0' && *str <= '9') || *str == '.') {
    len++;
    str++;
  }
  return len;
}
