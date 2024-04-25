#include "../s21_math.h"

long double s21_cos(double x) {
  long double res;
  if (S21_IS_NAN(x) || S21_IS_INF(x))
    res = S21_NAN;
  else
    res = s21_sin(S21_PI / 2 - x);
  return res;
}