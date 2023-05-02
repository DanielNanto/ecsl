#include "../include/ecsl_str.h"

//! \brief Calculate how many elements are within a given "int array" string.  
//! \brief CAUTION: The given str must not contain spaces. Use str_remove_spaces() first.
//! \param str The char array to be examined
//! \returns The or number of elements within a given "int array" string.
int str_get_array_length(char* str)
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

//! \brief Create a clone of a string, but exclude all spaces.  
//! \brief WARNING: Please note that the 'str' argument will have memory allocated via
//! \brief malloc(), and as such will need to be free'd manually.
//! \param str The char array to be cleaned
//! \returns The new string without spaces
char* str_remove_spaces(char* str)
{
  char* str_1 = NULL;
  int str_length = strlen(str);
  str_1 = (char*)calloc(str_length + 1, sizeof(char));
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
    char* str_2 = NULL;
    str_2 = (char*)calloc(j + 1, sizeof(char));
    strcpy(str_2, str_1);
    free(str_1);
    str_1 = (char*)calloc(j + 1, sizeof(char));
    strcpy(str_1, str_2);
    free(str_2);
  }
  return str_1;
}

//! \brief Convert a string to an array of integers, and return the size of the array.  
//! \brief CAUTION: If the given 'array' pointer previously pointed to memory allocated
//! \brief through aligned_alloc, calloc, malloc, or realloc, it needs to be free'd before
//! \brief use in this function.  
//! \brief WARNING: Please note that the 'array' argument will have memory allocated via
//! \brief realloc(), and as such will need to be free'd manually.
//! \param str A char array to be converted to an int array, in the format "[a,b,c]".
//! \param array A pointer to the int array to be realloc'd and populated.
//! \returns The length of the newly created array of integers, -1 if given invalid sting.
int str_to_array(char* str, int** array)
{
  int length = 0;
  char* tmp_str = str_remove_spaces(str);
  int str_length = strlen(tmp_str);
  if (tmp_str[0] == '[' && tmp_str[str_length - 1] == ']')
  {
    length = str_get_array_length(tmp_str);
    *array = (int*)realloc(*array, length * sizeof(int));
    memset(*array, 0, length * sizeof(int));
    char* str_read = (char*)calloc(str_length + 1, sizeof(char));
    int i = 0, j = 0, k = 0;
    for (i = 1; i < (str_length); i++)
    {
      if (tmp_str[i] == ',' || tmp_str[i] == ']')
      {
        (*array)[k] = str_to_int(str_read);
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

//! \brief Convert a given signed integer to an array of characters.  
//! \brief WARNING: Please note that the returned char* points to memory
//! \brief allocated through calloc(), and as such needs to be free'd.
//! \param n The integer to be converted.
//! \returns The newly created string.
char* int_to_str(int n)
{
  char* str_1;
  int length = int_get_digit_total(n);
  // Add a character for a negative sign, if needed.
  length += (n < 0) ? 1 : 0;
  str_1 = (char*)calloc(length + 1, sizeof(char));
  int i = 0;
  if (n < 0)
  {
    str_1[i] = '-';
    i = 1;
  }
  // Extract the digits starting with digit 1 (left to right)
  int digit_target = 1;
  for (; i < length; i++, digit_target++)
  {
    // TODO - Rewrite to avoid redundant calls to int_get_digit_total()
    str_1[i] = 48 + int_get_digit(n, digit_target);
  }
  return str_1;
}

//! \brief Convert a given array of characters to a signed integer.  
//! \param str The character array to be converted.
//! \returns The newly created signed integer.
int str_to_int(char* str)
{
  int n = 0;
  int n_previous;
  int length = strlen(str);
  int i;
  // Extract each digit of the number (str) one at a time.
  for (i = 0; i < length; i++)
  {
    // Verify that i char of the given str is a number:
    if (str[i] >= 48 && str[i] <= 57)
    {
      n_previous = n;
      // Extract each number, then multiply to correct ten's place:
      n += (str[i] - 48) * pow(10, length - 1 - i);
      // If n_previous is larger than n, n has exceeded the maximum int size:
      if (n_previous > n)
      {
        printf("Error: str_to_int(): string is larger than __INT_MAX__.\n");
        n = 0;
        i = length;
      }
    }
  }
  // Handle negative integers:
  if (str[0] == '-')
  {
    n = n * -1;
  }
  return n;
}

//! \brief Copy a given array of integers to a string.  
//! \brief WARNING: Please note that the returned char* points to memory
//! \brief allocated through calloc(), and as such needs to be free'd.
//! \param array  A pointer to the array of integers to be copied.
//! \param elements The number of elements within the afore mentioned array.
//! \returns The newly created string.
char* array_to_str(int* array, int elements)
{
  char* str_1;
  int total_size = 1; // For '['
  int i;
  // Calculate new string size first to avoid redundant calls to realloc().
  for (i = 0; i < elements; i++)
  {
    total_size += int_get_digit_total(array[i]) + 1; // + 1 for ',' and ']'
  }
  str_1 = (char*)calloc(total_size + 1, sizeof(char));
  str_1[0]='[';
  // Warning: several memory allocation functions are called; consider revising.
  for (i = 0; i < elements; i++)
  {
    char* str_tmp = int_to_str(array[i]);
    strcat(str_1, str_tmp);
    if ( i < elements - 1)
    {
      strcat(str_1, ",");
    }
    else
    {
      strcat(str_1, "]");
    }
    free(str_tmp);
  }
  return str_1;
}

