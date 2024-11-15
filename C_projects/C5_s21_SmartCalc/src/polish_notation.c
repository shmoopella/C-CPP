#include "polish_notation.h"

#include <stdio.h>

queue *polish_notation(queue *input_que) {
  queue *output_que = NULL;
  stack *first_stack = NULL;
  double value = 0;
  int priority = 0;
  enum lexeme_type type = 0;
  while (input_que) {
    if (input_que->type == t_open_bracket || is_function(input_que->type)) {
      input_que = pop_q(input_que, &value, &priority, &type);
      first_stack = push_s(first_stack, value, priority, type);
    } else if (input_que->type == t_number || input_que->type == t_x) {
      input_que = pop_q(input_que, &value, &priority, &type);
      output_que = push_q(output_que, value, priority, type);
    } else if (input_que->type == t_close_braket) {
      input_que = pop_q(input_que, &value, &priority, &type);
      while (first_stack->type != t_open_bracket) {
        first_stack = pop_s(first_stack, &value, &priority, &type);
        output_que = push_q(output_que, value, priority, type);
      }
      first_stack = pop_s(first_stack, &value, &priority, &type);
      if (first_stack && is_function(first_stack->type)) {
        first_stack = pop_s(first_stack, &value, &priority, &type);
        output_que = push_q(output_que, value, priority, type);
      }
    } else if (is_operator(input_que->type)) {
      while (first_stack && is_operator(first_stack->type) &&
             first_stack->priority >= input_que->priority) {
        first_stack = pop_s(first_stack, &value, &priority, &type);
        output_que = push_q(output_que, value, priority, type);
      }
      input_que = pop_q(input_que, &value, &priority, &type);
      first_stack = push_s(first_stack, value, priority, type);
    }
  }
  while (first_stack) {
    first_stack = pop_s(first_stack, &value, &priority, &type);
    output_que = push_q(output_que, value, priority, type);
  }
  return output_que;
}

int is_operator(enum lexeme_type type) {
  return type == t_minus || type == t_plus || type == t_div || type == t_mul ||
         type == t_mod || type == t_pow;
}

int is_function(enum lexeme_type type) {
  return type == t_cos || type == t_sin || type == t_tan || type == t_acos ||
         type == t_asin || type == t_atan || type == t_sqrt || type == t_log ||
         type == t_ln;
}
