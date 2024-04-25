#include "../s21_math.h"

long double s21_asin(double x) {
  long double res = S21_NAN;
  if (x >= 0 && x <= 1) res = s21_acos(s21_sqrt(1 - s21_pow(x, 2)));
  if (x >= -1 && x < 0) res = -s21_acos(s21_sqrt(1 - s21_pow(x, 2)));
  return res;
}