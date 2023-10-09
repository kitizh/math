#include "s21_math.h"

long double s21_floor(double x) {
  int flag = 0;
  if (x != x) {
    x = S21_NAN;
    flag = 1;
  }
  if (is_inf(x)) {
    if (x > 0) {
      x = S21_INF;
    } else {
      x = -S21_INF;
    }
    flag = 1;
  }

  double y = (int)x;
  if (flag == 0) {
    if (x > 0 && y != x) {
      x = (int)x;
    }
    if (x < 0 && y != x) {
      x = (int)x - 1;
    }
  }

  return x;
}
