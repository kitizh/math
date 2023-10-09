#include "s21_math.h"

long double s21_fabs(double x) {
  int flag = 0;
  if (x != x) {
    x = S21_NAN;
    flag = 1;
  }
  if (x == S21_INF) {
    x = S21_INF;
    flag = 1;
  }
  if (flag == 0) {
    if (x < 0) {
      x = x * (-1);
    }
  }
  return x;
}
