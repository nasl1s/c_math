#include "../s21_math.h"

long double s21_atan(double x) {
  long double res = 0;
  if (x == S21_POS_INF)
    res = S21_PI / 2;
  else if (x == S21_NEG_INF)
    res = -S21_PI / 2;
  else if (x == 1)
    res = S21_PI / 4.;
  else if (x == -1)
    res = -S21_PI / 4.;
  else if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (x != 0) {
    int range = (x > -1 && x < 1);
    res = range ? x : 1 / x;
    for (int i = 1; i < 1000; i++) {
      long double step = 0.;
      step = i % 2 != 0 ? -1. : 1.;
      step *= s21_pow(x, (1 + 2 * i) * (range ? 1 : -1));
      step /= 1. + 2. * i;
      res += step;
    }
    if (!range) res = (S21_PI * s21_fabs(x) / (2 * x)) - res;
  }
  return res;
}