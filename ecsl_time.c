#include "ecsl_time.h"

int time_compare(uint32_t time_new,
                 uint32_t time_old,
                 uint32_t period)
{
  int errors = 0;
  // If 'new' has exceeded the maximum value of uint32_t, it will be < old.  
  if (time_new < time_old)
  {
    if ((__UINT32_MAX__ - time_old + time_new) > period)
    {
      errors = 1;
    }
  }
  else
  {
    if ((time_new - time_old) > period)
    {
      errors = 1;
    }
  }
  return errors;
}