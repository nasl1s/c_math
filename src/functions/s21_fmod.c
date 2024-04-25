#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = S21_NAN;
  if (!s21_is_nan(x, y)) {
    if (S21_IS_INF(y))
      res = (long double)x;
    else {
      int n = x / y;
      res = (long double)x - n * (long double)y;
    }
  }
  return res;
}

int s21_is_nan(double x, double y) {
  return (S21_IS_INF(x) || (y == 0) ||
          (S21_IS_INF(x) && S21_IS_INF(y) && x != y));
}