#include "ecsl_file.h"

int escl_file_set_line(FILE* file, int dst_line_n)
{
  int errors = 0;
  fseek(file, 0L, SEEK_SET);
  char c = '0';
  int line_counter = 0;
  while(line_counter < dst_line_n && c != EOF)
  {
    c = fgetc(file);
    if(c == '\n')
    {
      ++line_counter;
    }
  }
  return errors;
}