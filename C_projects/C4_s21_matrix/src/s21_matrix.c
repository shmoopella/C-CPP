#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int res = 0;
    if (rows <= 0 || columns <= 0 || result == NULL) {
        res = 1;
    } else {
        result->rows = rows;
        result->columns = columns;
        result->matrix =  malloc(rows * sizeof(double*));
        for (int i = 0; i < rows; i++) {
            result->matrix[i] = malloc(columns * sizeof(double));
        }
    }
    return res;
}

void s21_remove_matrix(matrix_t *a) {
    if (a && a->matrix) {
        for (int i = 0; i < a->rows; i++) {
            free(a->matrix[i]);
        }
        free(a->matrix);
    }
}

int s21_eq_matrix(matrix_t *a, matrix_t *b) {
    int res = SUCCESS;
    if (!a || !b || a->rows <= 0 || a->columns <= 0 || b->rows <= 0 \
    || b->columns <= 0 || !(a->matrix) || !(b->matrix)) {
        res = FAILURE;
    } else {
        if (a->rows == b->rows && a->columns == b->columns) {
            for (int i = 0; i < a->rows && res; i++) {
                for (int j = 0; j < a->columns && res; j++) {
                    if (fabs(a->matrix[i][j] - b->matrix[i][j]) > EPS) {
                        res = FAILURE;
                    }
                }
            }
        } else {
            res = FAILURE;
        }
    }
    return res;
}

int s21_sum_matrix(matrix_t *a, matrix_t *b, matrix_t *result) {
    int res = 0;
    if (!a || !b || !result || a->rows <= 0 || a->columns <= 0 \
    || b->rows <= 0 || b->columns <= 0 || !(a->matrix) || !(b->matrix)) {
        res = 1;
    } else {
        if (a->rows == b->rows && a->columns == b->columns) {
            s21_create_matrix(a->rows, a->columns, result);
            for (int i = 0; i < a->rows; i++) {
                for (int j = 0; j < a->columns; j++) {
                    result->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
                }
            }
        } else {
            res = 2;
        }
    }
    return res;
}

int s21_sub_matrix(matrix_t *a, matrix_t *b, matrix_t *result) {
    int res = 0;
    if (!a || !b || !result || a->rows <= 0 || a->columns <= 0 || \
    b->rows <= 0 || b->columns <= 0 || !(a->matrix) || !(b->matrix)) {
        res = 1;
    } else {
        if (a->rows == b->rows && a->columns == b->columns) {
            s21_create_matrix(a->rows, a->columns, result);
            for (int i = 0; i < a->rows; i++) {
                for (int j = 0; j < a->columns; j++) {
                    result->matrix[i][j] = a->matrix[i][j] - b->matrix[i][j];
                }
            }
        } else {
            res = 2;
        }
    }
    return res;
}

int s21_mult_number(matrix_t *a, double number, matrix_t *result) {
    int res = 0;
    if (!a || !result || a->rows <= 0 || a->columns <= 0 || !(a->matrix)) {
        res = 1;
    } else {
        s21_create_matrix(a->rows, a->columns, result);
        for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
                result->matrix[i][j] = number * a->matrix[i][j];
            }
        }
    }
    return res;
}

int s21_mult_matrix(matrix_t *a, matrix_t *b, matrix_t *result) {
    int res = 0;
    if (!a || !b || !result || a->rows <= 0 || a->columns <= 0 \
    || b->rows <= 0 || b->columns <= 0 || !(a->matrix) || !(b->matrix)) {
        res = 1;
    } else if (a->columns != b ->rows) {
            res = 2;
    } else {
        s21_create_matrix(a->rows, b->columns, result);
        for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
                result->matrix[i][j] = 0;
                for (int k = 0; k < a->columns; k++) {
                    result->matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
                }
            }
        }
    }
    return res;
}

int s21_transpose(matrix_t *a, matrix_t *result) {
int res = 0;
    if (!a || !result || a->rows <= 0 || a->columns <= 0 || !(a->matrix)) {
        res = 1;
    } else {
        s21_create_matrix(a->columns, a->rows, result);
        for (int i = 0; i < result->rows; i++) {
            for (int j = 0; j < result->columns; j++) {
                result->matrix[i][j] = a->matrix[j][i];
            }
        }
    }
    return res;
}

matrix_t s21_matrix_for_minor(matrix_t a, int row, int column) {
    matrix_t res;
    int i_res = 0;
    int j_res = 0;
    s21_create_matrix(a.rows - 1, a.columns - 1, &res);
    for (int i = 0; i < a.rows; i++) {
        if (i == row) {
            continue;
        }
        for (int j = 0; j < a.columns; j++) {
            if (j == column) {
                continue;
            } else {
                res.matrix[i_res][j_res] = a.matrix[i][j];
                j_res++;
            }
        }
        j_res = 0;
        i_res++;
    }
    return res;
}

int s21_determinant(matrix_t *a, double *result) {
    int error = 0;
    matrix_t tmp_s21_matrix_for_minor;
    double minor = 0;
    double algeb_compl = 0;
    if (!a || !result || a->rows <= 0 || a->columns <= 0 || !(a->matrix)) {
        error = 1;
    } else if (a->rows != a->columns) {
        error = 2;
    } else {
        if (a->rows == 1) {
            *result = **(a->matrix);
        } else if (a->rows == 2) {
            *result = (a->matrix[0][0] * a->matrix[1][1]) + (a->matrix[0][1] * (-a->matrix[1][0]) );
        } else {
            *result = 0;
            for (int j = 0; j < a->columns; j++) {
                tmp_s21_matrix_for_minor = s21_matrix_for_minor(*a, 0, j);
                s21_determinant(&tmp_s21_matrix_for_minor, &minor);
                s21_remove_matrix(&tmp_s21_matrix_for_minor);
                algeb_compl = pow(-1, 0 + j) * minor;
                *result += a->matrix[0][j] * algeb_compl;
            }
        }
    }
    return error;
}

int s21_calc_complements(matrix_t *a, matrix_t *result) {
    int error = 0;
    if (!a || !result || a->rows <= 0 || a->columns <= 0 || !(a->matrix)) {
        error = 1;
    } else if (a->rows != a->columns || a->rows == 1) {
        error = 2;
    } else {
        matrix_t tmp_s21_matrix_for_minor;
        double algeb_compl = 0;
        double minor = 0;
        s21_create_matrix(a->rows, a->columns, result);
        for (int i = 0; i < a->rows; i++) {
            for (int j = 0; j < a->columns; j++) {
                tmp_s21_matrix_for_minor = s21_matrix_for_minor(*a, i, j);
                s21_determinant(&tmp_s21_matrix_for_minor, &minor);
                s21_remove_matrix(&tmp_s21_matrix_for_minor);
                algeb_compl = pow(-1, i + j) * minor;
                result->matrix[i][j] = algeb_compl;
            }
        }
    }
    return error;
}

int s21_inverse_matrix(matrix_t *a, matrix_t *result) {
    int error = 0;
    double determ = 0;
    matrix_t result_compl;
    matrix_t result_transp;
    if (!a || !result || a->rows <= 0 || a->columns <= 0 || !(a->matrix)) {
        error = 1;
    } else if (a->rows != a->columns || a->rows == 1) {
        error = 2;
    } else {
        s21_determinant(a, &determ);
        if (fabs(determ) < 1E-10) {
            error = 2;
        } else {
            s21_calc_complements(a, &result_compl);
            s21_transpose(&result_compl, &result_transp);
            s21_mult_number(&result_transp, 1 / determ, result);
            s21_remove_matrix(&result_compl);
            s21_remove_matrix(&result_transp);
        }
    }
    return error;
}

void s21_fill_matrix(matrix_t *result, double num) {
    for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = num;
            num++;
        }
    }
}
