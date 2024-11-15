#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#define s21_PI 3.14159265358979323846264338327950288
#define s21_LN10 2.30258509299404568401799145468436421
#define s21_NAN  __builtin_nanf("0x7fc00000")
#define s21_INFINITY __builtin_huge_valf()
#define s21_DBL_MAX ((double)1.79769313486231570814527423731704357e+308L)

int s21_abs(int x);
long double s21_fabs(double x);
long double s21_sqrt(double x);
long double s21_fmod(double x, double y);
long double s21_ceil(double x);
long double s21_floor(double x);
long double s21_exp(double x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_asin(double x);
long double s21_cos(double x);
long double s21_acos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_merkator(double x);
double s21_xcorrect(double x);
int s21_isinf(double x);

#endif  // SRC_S21_MATH_H_
