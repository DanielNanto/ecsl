#ifndef ECSL_FILE_H_
#define ECSL_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include "ecsl_str.h"
 
extern int file_set_line(FILE* file, int line_n);

extern int file_get_line_length(FILE* file, int line_n);

extern char* file_get_line_str(FILE* file, int line_n);

extern int file_get_line_int(FILE* file, int line_n);

#endif