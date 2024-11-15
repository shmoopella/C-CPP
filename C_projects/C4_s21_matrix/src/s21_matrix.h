#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SUCCESS 1
#define FAILURE 0
#define EPS 1E-7

typedef struct matrix_struct {
    double **matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *a);
int s21_eq_matrix(matrix_t *a, matrix_t *b);
int s21_sum_matrix(matrix_t *a, matrix_t *b, matrix_t *result);
int s21_sub_matrix(matrix_t *a, matrix_t *b, matrix_t *result);
int s21_mult_number(matrix_t *a, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *a, matrix_t *b, matrix_t *result);
int s21_transpose(matrix_t *a, matrix_t *result);
int s21_determinant(matrix_t *a, double *result);
int s21_calc_complements(matrix_t *a, matrix_t *result);
matrix_t s21_matrix_for_minor(matrix_t a, int rows, int columns);
int s21_inverse_matrix(matrix_t *a, matrix_t *result);
void s21_fill_matrix(matrix_t *result, double num);

#endif  // SRC_S21_MATRIX_H_
