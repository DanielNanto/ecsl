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

int escl_file_get_line_length(FILE* file, int line_n)
{
  int length = 0;
  // Retrieve starting position.
  int starting_position = ftell(file);
  // Seek to the desired line.
  if (escl_file_set_line(file, line_n) == 0)
  {
    char c = fgetc(file);
    if (c == EOF)
    {
      printf("Error: escl_file_get_line_length() has reached an invalid character or EOF.\n");
    }
    else
    {
      while(c != EOF && c != '\n')
      {
        c = fgetc(file);
        ++length;
      }
    } 
  }
  else
  {
    printf("Error: escl_file_get_line_length() unable to find desired line.\n");
  }
  fseek(file, starting_position, SEEK_SET);
  return length;
}
