#include "ecsl_int.h"

int int_get_length(int n)
{
  int length = 0;
  int n_tmp = n % (int)pow(10, length);
  while (n_tmp != n)
  {
    ++length;
    n_tmp = n % (int)(pow(10, length));
  }
  length += (n <= 0) ? 1 : 0;
  return length;
}