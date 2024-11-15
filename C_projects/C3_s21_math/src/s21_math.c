#include "s21_math.h"

int s21_abs(int x) {
    return x < 0 ? (x *= -1) : x;
}

long double s21_fabs(double x) {
    return x < 0 ? (x *= -1) : x;
}

long double s21_sqrt(double x) {
    long double res = 1;
    long double dif = 1;
    long double prev = 1;
    if (!s21_isinf(x)) {
        if (x < 0) {
            res = s21_NAN;
        } else {
            while (dif > 1E-15) {
                res = (res + x / res) / 2;
                dif = s21_fabs((double)(res - prev));
                prev = res;
            }
        }
    } else {
        if (x > 0)
            res = s21_INFINITY;
        else
            res = s21_NAN;
    }
    return res;
}

long double s21_fmod(double x, double y) {
    long double res;
    if (!s21_isinf(x)) {
        if (y == 0) {
            res = s21_NAN;
        } else if (s21_fabs(x) < s21_fabs(y)) {
            res = x;
        } else {
            res = (long)(x/y);
            res = res * y;
            res = x - res;
        }
    } else {
        res = s21_NAN;
    }
    return res;
}

long double s21_ceil(double x) {
    long double res = (long)x;
    if (!s21_isinf(x)) {
        if (x != x) {
            res = s21_NAN;
        } else if (x > 0) {
            if (x - res != 0)
                res += 1;
        }
    } else {
        if (x > 0)
            res = s21_INFINITY;
        else
            res = -s21_INFINITY;
    }
    return res;
}

long double s21_floor(double x) {
    long double res = (long)x;
    if (!s21_isinf(x)) {
        if (x != x) {
            res = s21_NAN;
        } else if (x < 0) {
            if (x - res != 0)
                res -=  1;
        }
    } else {
        if (x > 0)
            res = s21_INFINITY;
        else
            res = -s21_INFINITY;
    }
    return res;
}

long double s21_exp(double x) {
    long double term = 1;
    long double sum = 1;
    if (!s21_isinf(x)) {
        for (int n = 1; s21_fabs(term) > 1E-15; n++) {
            term = term * x / n;
            sum += term;
        }
    } else {
        if (x > 0)
            sum = s21_INFINITY;
        else
            sum = 0;
    }
    return sum;
}

long double s21_log(double x) {
    long double sum;
    if (!s21_isinf(x)) {
        if (x == 0) {
            sum = -s21_INFINITY;
        } else {
            if (x < 0) {
                sum = s21_NAN;
            } else {
                int count = 0;
                while (x > 1) {
                    x = x / 10;
                    count++;
                }
                sum = count * s21_LN10 + s21_merkator(x - 1);
            }
        }
    } else {
        if (x > 0)
            sum = s21_INFINITY;
        else
            sum = s21_NAN;
    }
    return sum;
}

long double s21_pow(double base, double exp)  {
    long double res = 0;
    int flag = 0;
    if (exp == 0) {
        res = 1;
    } else if (base != base) {
        res = s21_NAN;
    } else if (exp != exp) {
        if (base == 1)
            res = 1;
        else
            res = s21_NAN;
    } else if (base == 0 && exp > 0) {
        res = 0;
    } else if (base == 1) {
        res = 1;
    } else if (s21_isinf(base)) {
        if (s21_isinf(exp)) {
            if (exp > 0)
                res = s21_INFINITY;
            else
                res = 0;
        } else if (exp > 0) {
            if (base > 0)
                res = s21_INFINITY;
            else
                res = -s21_INFINITY;
        } else {
            res = 0;
        }
    } else if (s21_isinf(exp)) {
        if (base == -1 || base == -1) {
            res = 1;
        } else if (base > -1 && base < 1) {
            if (exp > 0)
                res = 0;
            else
                res = s21_INFINITY;
        } else if (base != base) {
            res = s21_NAN;
        } else if (exp > 0) {
            res = s21_INFINITY;
        } else {
            res = 0;
        }
    } else {
        if (exp == 0) {
            res = 1;
        } else if (exp != (int)exp) {
            res = s21_exp(exp * s21_log(base));
        } else {
            res = base;
            if (exp < 0) {
                exp *= -1;
                flag = 1;
            }
            for (int count = 2; count <= exp; count++) {
                res = res * base;
            }
            if (flag) {
                res = 1 / res;
            }
        }
    }
    return res;
}

long double s21_sin(double x) {
    long double s, res;
    if (!s21_isinf(x)) {
        x = s21_xcorrect(x);
        s = x, res = x;
        for (int n = 1; s21_fabs(s) > 1E-15; n++) {
            s = s * -1 * x * x / (2 * n * (2 * n + 1));
            res += s;
        }
    } else {
        res = s21_NAN;
    }
    return res;
}

long double s21_asin(double x) {
    long double term = x;
    long double sum = x;
    if (x < -1 || x > 1) {
        sum = s21_NAN;
    } else  if (x == 1 || x == -1) {
        sum = s21_PI / 2 * x;
    } else {
        long double first_term = 1;
        for (int count = 1; s21_fabs(term) > 1E-15; count++) {
            first_term *= (double)(2 * count - 1) / (2 * count);
            term *= (double)(2 * count - 1) / (2 * count) * x * x * (2 * count - 1) / (2 * count + 1);
            sum += term;
        }
    }
    return sum;
}

long double s21_cos(double x) {
    long double res = 0;
    if (!s21_isinf(x)) {
        x = s21_xcorrect(x);
        res =  s21_sin(s21_PI / 2 - x);
    } else {
        res = s21_NAN;
    }
    return res;
}

long double s21_acos(double x) {
    long double res = 0;
    if (x < -1 || x > 1) {
        res = s21_NAN;
    } else {
        res = s21_PI / 2 - s21_asin(x);
    }
    return res;
}

long double s21_tan(double x) {
    return s21_sin(x)/s21_cos(x);
}

long double s21_atan(double x) {
    long double res = 0;
    if (!s21_isinf(x)) {
        res = s21_asin(x / s21_sqrt(1 + x * x));
    } else {
        if (x > 0)
            res = s21_PI/2;
        else
            res = -s21_PI/2;
    }
    return res;
}

long double s21_merkator(double x) {
    long double sum = x;
    long double term = x;
    for (int n = 2; s21_fabs(term) > 1E-15; n++) {
        term = term * x / n * (n-1) * (-1);
        sum += term;
    }
    return sum;
}

double s21_xcorrect(double x) {
    while (x < -s21_PI || x > s21_PI)
        x < -s21_PI ? (x += 2 * s21_PI) : (x -= 2 * s21_PI);
    return x;
}

int s21_isinf(double x) {
    return (x >= s21_DBL_MAX || x <= -s21_DBL_MAX);
}
