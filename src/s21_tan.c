#include "s21_math.h"

long double s21_tan(double x) {
  long double sum = 0;
  long double k = s21_cos(x);
  if ((((int)s21_cos(x) - s21_cos(x) < 1e-10) && (s21_cos(x) < 0)) ||
      ((s21_cos(x) - (int)s21_cos(x) < 1e-10) && (s21_cos(x) > 0))) {
    k = (int)s21_cos(x);
    sum = s21_sin(x) / k;
  } else {
    sum = s21_sin(x) / s21_cos(x);
  }
  return sum;
}
