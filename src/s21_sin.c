#include "s21_math.h"

long double s21_sin(double x) {
  long double sum = 0;
  int n = 13;
  int k = 0;
  if (is_inf(x)) {
    return S21_NAN;
  }
  while (x > S21_PI) {
    x = x - S21_PI;
    k++;
  }
  while (x < S21_PI) {
    x = x + S21_PI;
    k++;
  }
  for (int i = 0; i < n; i++) {
    sum +=
        (s21_ipow(-1, i) * s21_ipow(x, 2 * i + 1)) / s21_factorial(2 * i + 1);
  }
  if (k % 2 != 0) {
    sum = (-1) * sum;
  }
  return sum;
}
