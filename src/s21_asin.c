#include "s21_math.h"

long double s21_asin(double x) {
  long double result = 0;
  if (x > -1. && x < 1.) {
    if (s21_fabs(x) > 0.8) {
      result = s21_acos(s21_sqrt(1 - x * x));
      if (x < 0) {
        result = -result;
      }
    } else if (x == 0) {
      result = 0;
    } else {
      long double m = 0;
      long double xpow = x;
      long double pow4 = 1;
      long double fci = 1;
      for (int i = 0; i < 35; i++) {
        if (i > 0) {
          xpow *= x * x;
          pow4 *= 4;
          fci *= i;
        }
        m = s21_factorial(2 * i) * xpow /
            (pow4 * s21_ipow(fci, 2) * (2 * i + 1));
        result += m;
      }
    }

  } else if (x == 1) {
    result = S21_PI / 2;
  } else if (x == -1) {
    result = -S21_PI / 2;
  } else if (x == 1.0 / 0.0) {
    result = S21_NAN;
  } else if (x == -1.0 / 0.0) {
    result = S21_NAN;
  } else if (x == 0.0 / 0.0 || -0.0 / 0.0) {
    result = S21_NAN;
  }

  return result;
}
