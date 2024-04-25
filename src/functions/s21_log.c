#include "../s21_math.h"

long double s21_log(double x) {
  long double res = 0.0;
  if (S21_IS_NAN(x) || x < 0)
    res = S21_NAN;
  else if (S21_IS_INF(x))
    res = S21_POS_INF;
  else if (x == 0)
    res = S21_NEG_INF;
  else {
    long double res_n = 0.0;
    do {
      res_n = res;
      res = res_n + 2 * (x - s21_exp(res_n)) / (x + s21_exp(res_n));
    } while (s21_fabs(res_n - res) > S21_EPS2);
  }
  return res;
}