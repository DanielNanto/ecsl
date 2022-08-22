#include "ecsl_str.h"

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
  str_1 = (char*)calloc(sizeof(char), str_length+1);
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

int str_to_array(char* str, int** array)
{
  int length = 0;
  char* tmp_str = str_remove_spaces(str);
  int str_length = strlen(tmp_str);
  printf("tmp_str = %s\n", tmp_str);
  if (tmp_str[0] == '[' && tmp_str[str_length-1] == ']')
  {
    length = str_array_length(tmp_str);
    *array = (int*)realloc(*array, length * sizeof(int));
    memset(*array, 0, length * sizeof(int));
    // This might be bad
    char* str_read = (char*)calloc(str_length, sizeof(char));
    int i = 0, j = 0, k = 0;
    for (i = 1; i < (str_length); i++)
    {
      if (tmp_str[i] == ',' || tmp_str[i] == ']')
      {
        (*array)[k] = atoi(str_read);
        memset(str_read, 0, strlen(str_read) * sizeof(char));
        ++k;
        j = 0;
      }
      else
      {
        str_read[j] = tmp_str[i];
        ++j;
      }
    }
    free(tmp_str);
    free(str_read);
  }
  else
  {
    printf("Error: str_to_array() cannot use convert given str to an array. ");
    printf("The target str must begin with an '[' and end with an ']'. Each ");
    printf("integer within the 'array' needs to be separated by commas.\n");
    length = -1;
  }
  return length;
}
