#include "ecsl_time.h"

int time_compare(uint32_t new,
                 uint32_t old,
                 uint32_t period)
{
  int errors = 0;
  // If 'new' has exceeded the maximum value of uint32_t, it will be < old.  
  if (new < old)
  {
    if ((__UINT32_MAX__ - old + new) > period)
    {
      errors = 1;
    }
  }
  else
  {
    if ((new - old) > period)
    {
      errors = 1;
    }
  }
  return errors;
}