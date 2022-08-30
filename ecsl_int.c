#include "ecsl_int.h"

int int_get_digit_total(int n)
{
  int length = 0;
  int n_tmp = n % (int)pow(10, length);
  while (n_tmp != n)
  {
    ++length;
    n_tmp = n % (int)(pow(10, length));
  }
  return length;
}
