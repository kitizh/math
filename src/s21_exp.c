#include "s21_math.h"

long double s21_exp(double x) {
  long double rezult = 0;
  long double m = 0;
  long double fac_i = 1;
  long double powx = 1;
  if (is_inf(x)) {
    return S21_INF;
  }
  if (is_nan(x)) {
    return S21_NAN;
  }
  for (int i = 1; i < 120; i++) {
    fac_i *= i;
    powx *= x;
    m = powx / fac_i;
    if (s21_fabs(m) < 1e-10) {
      break;
    }
    rezult += m;
  }
  return rezult + 1;
}
