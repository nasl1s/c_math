#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 0.0;
  if (base == -1 && (exp == S21_POS_INF || exp == S21_NEG_INF)) {
    res = 1.0;
  } else if (base == 1 || exp == 0) {
    res = 1.0;
  } else if (base == S21_NEG_INF && exp == S21_NEG_INF) {
    res = 0.0;
  } else if (base == S21_NEG_INF && exp == S21_POS_INF) {
    res = S21_POS_INF;
  } else if (S21_IS_NAN(base) || S21_IS_NAN(exp)) {
    res = S21_NAN;
  } else if ((s21_fabs(base) < 1) && exp == S21_NEG_INF) {
    res = S21_POS_INF;
  } else if ((s21_fabs(base) < 1) && exp == S21_POS_INF) {
    res = +0.0;
  } else if ((s21_fabs(base) > 1) && exp == S21_POS_INF) {
    res = S21_POS_INF;
  } else if (base < 0 && exp != (long long int)exp) {
    res = S21_NAN;
  } else {
    int sign = base < 0 ? -1 : 1;
    res = s21_exp(exp * s21_log(base * sign));
    if (s21_fmod(exp, 2)) {
      res *= sign;
    }
  }
  return res;
}
