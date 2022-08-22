#include "../ecsl_file.h"
#include "../ecsl_str.h"

int main(int argc, char* argv[])
{
  int errors = 0;

  (void)argc;
  (void)argv;

  FILE* file;
  file = fopen("src/file.txt", "r+");
  if (file != NULL)
  {
    char* tile = file_get_line_str(file, 6);
    printf("tile = %s\n",tile);
    int* array = NULL;
    int array_length = str_to_array(tile, &array);
    free(array);
    free(tile);
  }
  else
  {
    printf("5\n");
  }
  fclose(file);
  return errors;
}