#include "main_calc.h"

int main_calc(char *input_string, double x_value, double *res) {
  queue *input_que = NULL;
  queue *output_que = NULL;
  int error = 1;
  if (!validation_str(input_string)) {
    input_que = make_list(input_string, input_que, x_value);
    output_que = polish_notation(input_que);
    *res = calculation(output_que);
    error = 0;
  }
  return error;
}
