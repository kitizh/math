#include "s21_math.h"

long double s21_sqrt(double x) {
  long double srd = x / 2;
  if (x < 0) {
    srd = S21_NAN;
  }
  while ((srd - (x / srd) > S21_EPS || (x / srd) - srd > S21_EPS) && (x > 0)) {
    srd = 0.5 * (srd + x / srd);
  }
  return srd;
}
