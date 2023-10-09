#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long long int i = 0;
  long double rez = 0;
  if (y == 0.0) {
    return S21_NAN;
  }
  if (is_inf(x) || is_nan(x) || is_nan(y)) {
    return S21_NAN;
  }
  i = s21_fabs(x / y);
  if ((x < 0 && y > 0) || (x > 0 && y < 0)) {
    rez = (long double)x + s21_floor(i) * (long double)y;
  } else {
    rez = (long double)x - s21_floor(i) * (long double)y;
  }

  if (i == 0) {
    rez = x;
  }

  return rez;
}
