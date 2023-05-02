#include "../include/ecsl_file.h"

//! \brief Seek to the start of a given line number within the provided file.
//! \param file The FILE* to seek into.
//! \param line_n The line number requested to seek to.
//! \returns 0 if successful, 1 if unable to seek to the desired line. 
int file_set_line(FILE* file, int line_n)
{
  int errors = 0;
  // Set file position to the beginning (SEEK_SET) of the file.
  fseek(file, 0L, SEEK_SET);
  // Read through the file until  number of '\n' characters are read.
  signed char c = '0';
  int line_counter = 0;
  while(line_counter < line_n && c != EOF)
  {
    c = fgetc(file);
    if(c == '\n')
    {
      ++line_counter;
    }
  }
  if (line_counter != line_n)
  {
    printf("Error: file_set_line() unable to seek to desired line\n");
    errors = 1;
  }
  return errors;
}

//! \brief Find the character length of a given line within the provided file.
//! \param file The FILE* to evaluate.
//! \param line_n The line number of a FILE* to be evaluated.
//! \returns The length of desired line.
int file_get_line_length(FILE* file, int line_n)
{
  int length = 0;
  // Retrieve starting position.
  int starting_position = ftell(file);
  // Seek to the desired line.
  if (file_set_line(file, line_n) == 0)
  {
    signed char c = fgetc(file);
    if (c == EOF)
    {
      printf("Error: file_get_line_length() has reached an invalid character ");
      printf("or EOF.\n");
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
    printf("Error: file_get_line_length() unable to find desired line.\n");
  }
  fseek(file, starting_position, SEEK_SET);
  return length;
}

//! \brief Extract a string from the given line of a provided file.
//! \param file The FILE* to evaluate.
//! \param line_n The line number of a FILE* to be read.
//! \returns The extracted string.
//! \warning Please note that the returned char* points to memory
//! \warning allocated through calloc(), and as such needs to be free'd.
char* file_get_line_str(FILE* file, int line_n)
{
  // Record the position of the 'cursor' before operating.
  int starting_position = ftell(file);
  // Set 'cursor' to the beginning of line_n.
  file_set_line(file, line_n);
  int length = file_get_line_length(file, line_n);
  // Create a string large enough to contain the current line.
  char* tmp_str = (char*)calloc(1,sizeof(char) * (length+1));
  // Find length of current line.
  int i = 0;
  for (i = 0; i < length; i++)
  {
    tmp_str[i] = fgetc(file);
  }
  // Return the 'cursor' to the recorded position before this operation.
  fseek(file, starting_position, SEEK_SET);
  return tmp_str;
}

//! \brief Extract an integer value from a specific line of a given file.
//! \param file The FILE* to extract an int from.
//! \param line_n The line number.
//! \returns the int value if successful, 0 if 0, or if unable to aquire int.
int file_get_line_int(FILE* file, int line_n)
{
  int value = 0;
  // Record the position of the 'cursor' before operating.
  int starting_position = ftell(file);
  // Set 'cursor' to the beginning of line_n.
  file_set_line(file, line_n);
  int length = file_get_line_length(file, line_n);
  // Create a string large enough to contain the current line.
  char* tmp_str = (char*)calloc(length + 1, sizeof(char));
  // Find length of current line.
  int i = 0;
  for (i = 0; i < length; i++)
  {
    tmp_str[i] = fgetc(file);
  }
  // Return the 'cursor' to the recorded position before this operation.
  fseek(file, starting_position, SEEK_SET);
  value = str_to_int(tmp_str);
  free(tmp_str);
  return value;
}
