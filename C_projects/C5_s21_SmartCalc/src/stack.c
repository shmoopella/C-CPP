#include "stack.h"

stack *push_s(stack *first, double value, int priority, enum lexeme_type type) {
  stack *new_first = malloc(sizeof(stack));
  new_first->value = value;
  new_first->priority = priority;
  new_first->type = type;
  new_first->next = first;
  return new_first;
}

stack *pop_s(stack *first, double *value, int *priority,
             enum lexeme_type *type) {
  stack *new_first = NULL;
  if (first) {
    new_first = first->next;
    *value = first->value;
    *priority = first->priority;
    *type = first->type;
    free(first);
  }
  return new_first;
}

queue *push_q(queue *first, double value, int priority, enum lexeme_type type) {
  queue *new_elem = malloc(sizeof(queue));
  new_elem->value = value;
  new_elem->priority = priority;
  new_elem->type = type;
  new_elem->next = NULL;
  if (first) {
    queue *tmp = first;
    while (tmp->next) {
      tmp = tmp->next;
    }
    tmp->next = new_elem;
  } else {
    first = new_elem;
  }
  return first;
}

queue *pop_q(queue *first, double *value, int *priority,
             enum lexeme_type *type) {
  queue *new_first = NULL;
  if (first) {
    *value = first->value;
    *priority = first->priority;
    *type = first->type;
    new_first = first->next;
    free(first);
  }
  return new_first;
}
