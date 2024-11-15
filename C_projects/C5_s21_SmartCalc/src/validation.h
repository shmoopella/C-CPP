#ifndef VALIDATION_SRC
#define VALIDATION_SRC

#include <stdlib.h>
#include <string.h>

int validation_str(char *str);
void delete_spaces(char *str);
int valid_mod(char *str, int i);
int len_validation(char *str, int *len_str);
int brackets_validation(char *str);
int point_validation(char *str, int i, int len_str, int float_point);
int number_validation(char *str, int i);
int x_validation(char *str, int i);
int operator_validation(char *str, int i);
int check_on_number(char symbol);
int check_on_operator(char symbol);
int check_on_mod(char *str, int i);
int valid_function(char *str, int *i, int *error);
int microvalid_function(char *str, int i);
int graphic_valid(double xMin, double xMax, double yMin, double yMax);

#endif
