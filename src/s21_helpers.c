#include "s21_math.h"

long double s21_factorial(int x) {
  long double sum = 1;
  if (x < 0) {
    sum = S21_NAN;
  } else {
    for (int i = 0; i < x; i++) {
      sum *= (x - i);
    }
  }
  return sum;
}

long double s21_ipow(long double base, int exp) {
  long double sum = 1;
  if (exp < 0) {
    for (int i = 0; i < -exp; i++) {
      sum *= (1 / base);
    }
  } else {
    for (int i = 0; i < exp; i++) {
      sum *= base;
    }
  }
  return sum;
}
