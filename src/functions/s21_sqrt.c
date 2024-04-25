#include "../s21_math.h"
//Кв корень из числа = число в степени 1/2

long double s21_sqrt(double x) {
  long double res = 0;
  if (x < 0 || S21_IS_NAN(x)) res = S21_NAN;
  if (x == 0) res = 0;
  if (x == S21_POS_INF) res = S21_POS_INF;
  if (x > 0) res = s21_pow(x, 0.5);
  return res;
}
