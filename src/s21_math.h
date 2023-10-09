#ifndef SRC_S21_MATH1_H_
#define SRC_S21_MATH1_H_

#include <errno.h>
#include <float.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define S21_EXP 2.7182818284959045
#define S21_EPS 1e-6
#define S21_PI 3.1415926535

#define S21_INF 0.1 / 0.0
#define S21_NAN 0.0 / 0.0
#define S21_LN2 0.69314718055994530942
#define S21_M_PI_2 1.57079632679489661923
#define s21_size_t unsigned long long
#define is_nan(x) __builtin_isnan(x)
#define is_inf(x) __builtin_isinf(x)
int s21_abs(int x);
long double s21_factorial(int x);
long double s21_pow(double base, double exp);
long double s21_sqrt(double x);
long double s21_ceil(double x);
int floattostr(double num, int percision, char *buff);
s21_size_t s21_strlen(const char *str);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_exp(double x);
void s21_inttostr(unsigned long int n, char *str);
int s21_len(unsigned long int n);
long double s21_rt(double a, int n);
long double s21_ipow(long double base, int exp);
long double s21_sin(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_atan(double x);
long double s21_asin(double x);
long double s21_acos(double x);
#endif // SRC_S21_MATH1_H_
