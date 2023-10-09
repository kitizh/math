#include "s21_math.h"

long double s21_log(double x) {
  long double m = (x - 1) / (x + 1);
  long double k = 1;
  long double mpow = m;
  long double res = 0;
  int i = 1;
  if (x < 0) {
    return S21_NAN;
  }
  if (x == 0) {
    return -S21_INF;
  }
  if (is_inf(x)) {
    return S21_INF;
  }

  if (x == S21_EXP) {
    return 1.;
  }
  while (s21_fabs(k) > 1e-20) {
    k = 2 * mpow / i;
    mpow *= m * m;
    res += k;
    i += 2;
  }
  return res;
}
