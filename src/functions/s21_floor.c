#include "../s21_math.h"

long double s21_floor(double x) {
  int int_res = (int)x;
  int_res -= (x < 0 && (x - int_res));
  long double res = int_res;
  if (S21_IS_INF(x) || S21_IS_NAN(x) || x == S21_DBL_MAX) res = x;
  if (res == 0 && x < 0) res = -res;

  return res;
}