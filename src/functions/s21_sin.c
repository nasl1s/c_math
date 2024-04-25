#include "../s21_math.h"

long double s21_sin(double x) {
  long double res = 0;
  if (x == S21_NAN || S21_IS_INF(x)) {
    res = S21_NAN;
  } else {
    int flag = 0;
    if (x < 0) {
      while (x < -2 * S21_PI) {
        x += 2 * S21_PI;
      }
      if (x < -S21_PI) {  // (-2 * PI, 0)
        x += S21_PI;
        flag = 1;
      }
    } else if (x > 0) {
      x = s21_fmod(x, 2 * S21_PI);
      if (x > S21_PI) {  // (0, 2 * PI)
        x -= S21_PI;
        flag = 1;
      }
    }

    long double term = x;  // одно слагаемое
    int n = 1;             // степень
    res = x;               // вся сумма

    while (s21_fabs(term) > S21_EPS) {
      term *= -1 * (x * x) / ((n + 1) * (n + 2));
      n += 2;
      res += term;
    }
    if (flag == 1) {
      res = -res;
    }
  }
  return res;
}