#include "s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (is_inf(x)) {
    res = S21_M_PI_2;
    if (x < 0) {
      res = -res;
    }
  } else if (is_nan(x)) {
    res = S21_NAN;
  } else {
    res = s21_asin(x / s21_sqrt(s21_ipow(x, 2) + 1));
  }

  return res;
}
