#include "ecsl_file.h"

int escl_file_set_line(FILE* file, int dst_line_n)
{
  int errors = 0;
  // Set file position to the beginning (SEEK_SET) of the file.
  fseek(file, 0L, SEEK_SET);
  // Read through the file until  number of '\n' characters are read.
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
  if (line_counter != dst_line_n)
  {
    printf("Error: escl_file_set_line() unable to seek to desired line\n");
    errors = 1;
  }
  return errors;
}