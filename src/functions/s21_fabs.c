#include "../s21_math.h"

long double s21_fabs(double x) {
  long double res = (long double)x;
  if (x == S21_NEG_INF)
    res = S21_POS_INF;
  else if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (x < 0) {
    res = -x;
  }
  return res;
}