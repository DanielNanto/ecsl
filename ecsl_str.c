#include "ecsl_file.h"

int str_array_length(char* str)
{
  // Note: expected str format: "[a,b,c]"
  int str_length = strlen(str);
  int array_length = 0;
  // If there is at least one number between '[' and ']'
  if (str_length > 2)
  {
    array_length = 1;
    int i;
    for (i = 1; i < str_length; i++)
    {
      if (str[i] == ',')
      {
        ++array_length;
      }
    }
  }
  return array_length;
}