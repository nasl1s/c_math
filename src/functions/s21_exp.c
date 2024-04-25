#include "../s21_math.h"

long double s21_exp(double x) {
  long double res = 0.0;
  if (S21_IS_NAN(x)) {
    res = S21_NAN;
  } else if (x == S21_POS_INF || x >= LNLONGDOUBLE) {
    res = S21_POS_INF;
  } else if (x == S21_NEG_INF) {
    res = 0.0;
  } else {
    long double integer_part = 1;  // e ^ n
    int n = 0;  // целая часть икса. x = 5.3, то n = 5
    int is_negative = 0;
    if (x < 0) {
      is_negative = 1;
      x *= -1;
    }
    while (x > 1) {
      x -= 1;
      ++n;
    }
    for (int i = 0; i < n; ++i) {
      integer_part *= S21_E;
    }
    int n2 = 1;  // степень в формуле Тейлора
    long double term = x;
    long double sum = 1 + term;
    while (s21_fabs(term) > S21_EPS) {
      term *= x / (n2 + 1);

      n2 += 1;
      sum += term;
    }
    res = sum * integer_part;

    if (is_negative) {
      res = 1 / res;
    }
  }
  return res;
}