#ifndef POLISH_SRC
#define POLISH_SRC

#include "stack.h"

int is_operator(enum lexeme_type type);
int is_function(enum lexeme_type type);
queue *polish_notation(queue *input_que);

#endif
