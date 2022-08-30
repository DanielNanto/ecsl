#include "ecsl_int.h"

int int_get_digit_total(int n)
{
  int length = 0;
  if (n == 0)
  {
    length = 1;
  }
  else
  {
    int n_tmp = n % (int)pow(10, length);
    while (n_tmp != n)
    {
      ++length;
      n_tmp = n % (int)(pow(10, length));
    }
  }
  return length;
}

int int_get_digit(int n, int digit_target)
{
  int value = 0;
  int digit_total = int_get_digit_total(n);
  if (digit_target > 0 && digit_target <= digit_total)
  {
    // Convert digit_target from right->left to left->right (ltr).
    int digit_ltr = (int)pow(10, digit_total - digit_target + 1);
    // Truncate numbers before and after desired digit.
    value = (n % digit_ltr) / (digit_ltr / 10);
    value *= (value < 0) ? -1 : 1;
  }
  else
  {
    printf("Error: Unable to read digit %d int_get_digit()\n", digit_target);
    value = -11;
  }
  return value;
}