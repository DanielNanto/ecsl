#include "ecsl_file.h"

int str_array_length(char* str)
{
  // Note: expected str format: "[a,b,c]"
  int str_length = strlen(str);
  int array_length = 0;
  if (str_length > 2) // If there is at least one number between '[' and ']'
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

char* str_remove_spaces(char* str)
{
  char* str_1 = NULL;
  int str_length = strlen(str);
  str_1 = (char*)calloc(sizeof(char), str_length);
  int i = 0, j = 0;
  for (i = 0; i < str_length; i++)
  {
    if (str[i] != ' ')
    {
      str_1[j] = str[i];
      ++j;
    }
  }
  if (j != str_length)
  {
    str_1 = (char*)realloc(str_1, j * sizeof(char)); // Trimming excess memory
  }
  return str_1;
}