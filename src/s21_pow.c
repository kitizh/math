#include "s21_math.h"

long double s21_pow(double base, double exp) {
  int b_n = is_nan(base);
  int e_n = is_nan(exp);
  int b_f = is_inf(base);
  int e_f = is_inf(exp);
  long double res = 0;
  int flag = 0;

  if (b_n || e_n) {
    res = S21_NAN;
    flag = 1;
  }
  if ((e_f) && (exp > 0) && (flag == 0)) {
    if (b_f) {
      if (base > 0) {
        res = S21_INF;
      } else {
        res = S21_INF;
      }
    } else if (base > 1) {
      res = S21_INF;
    } else if (base == 1) {
      res = 1;
    } else if (base > 0) {
      res = 0;
    } else if (base == 0) {
      res = 0;
    } else if (base > -1) {
      res = 0;
    } else if (base == -1) {
      res = 1;
    } else {
      res = S21_INF;
    }
    flag = 1;
  }

  if ((e_f) && (exp < 0) && (flag == 0)) {
    if (b_f) {
      res = 0;
    } else if (base > 1) {
      res = 0;
    } else if (base == 1) {
      res = 1;
    } else if (base > 0) {
      res = S21_INF;
    } else if (base == 0) {
      res = S21_INF;
    } else if (base > -1) {
      res = S21_INF;
    } else if (base == -1) {
      res = 1;
    } else {
      res = 0;
    }
    flag = 1;
  }

  if ((b_f) && (base > 0) && (flag == 0)) {
    if (exp > 0) {
      res = S21_INF;
    } else if (exp == 0) {
      res = 1;
    } else {
      res = 0;
    }
    flag = 1;
  }

  if ((b_f) && (base < 0) && (flag == 0)) {
    if (exp > 0) {
      if ((exp - (int)exp == 0) && ((int)exp % 2 == 0)) {
        res = S21_INF;
      } else {
        res = -S21_INF;
      }
    } else if (exp == 0) {
      res = 1;
    } else {
      res = 0;
    }
    flag = 1;
  }
  if ((base == 0) && (flag == 0)) {
    if (exp == 0) {
      res = 1;
    } else if (exp == -1) {
      res = S21_INF;
    }
    flag = 1;
  }
  if ((exp - (int)exp == 0) && (flag == 0)) {
    res = s21_ipow(base, (int)exp);
    flag = 1;
  }
  if (flag == 0) {
    if (base < 0 && exp != (int)exp) {
      flag = 1;
      res = S21_NAN;
    }
    if (flag == 0) {
      res = s21_exp(exp * s21_log(base));
    }
  }
  return res;
}
