#ifndef ECSL_STR_H_
#define ECSL_STR_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ecsl_int.h"
#include "ecsl_file.h"

extern int str_get_array_length(char* str);

extern char* str_remove_spaces(char* str);

extern int str_to_array(char* str, int** array);

extern char* int_to_str(int n);

extern int str_to_int(char* str);

extern char* array_to_str(int* array, int elements);

#endif