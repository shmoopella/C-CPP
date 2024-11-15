#ifndef STACK_SRC
#define STACK_SRC

#include <stdlib.h>

enum lexeme_type {
  t_sin,
  t_sqrt,
  t_acos,
  t_asin,
  t_atan,
  t_ln,
  t_log,
  t_tan = 't',
  t_cos = 'c',
  t_x = 'x',
  t_open_bracket = '(',
  t_close_braket = ')',
  t_plus = '+',
  t_minus = '-',
  t_mul = '*',
  t_div = '/',
  t_mod = 'm',
  t_pow = '^',
  t_number
};

typedef struct que {
  double value;
  int priority;
  enum lexeme_type type;
  struct que *next;
} queue;

typedef struct st {
  double value;
  int priority;
  enum lexeme_type type;
  struct st *next;
} stack;

stack *push_s(stack *first, double value, int priority, enum lexeme_type type);
stack *pop_s(stack *first, double *value, int *priority,
             enum lexeme_type *type);
queue *push_q(queue *first, double value, int priority, enum lexeme_type type);
queue *pop_q(queue *first, double *value, int *priority,
             enum lexeme_type *type);

#endif
