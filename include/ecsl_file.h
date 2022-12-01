#ifndef ECSL_FILE_H_
#define ECSL_FILE_H_

#include <stdio.h>
#include <stdlib.h>
#include "ecsl_str.h"

//! \brief Seek to the start of a given line number within the provided file.
//! \param file The FILE* to seek into.
//! \param line_n The line number requested to seek to.
//! \returns 0 if successful, 1 if unable to seek to the desired line.
extern int file_set_line(FILE* file, int line_n);

//! \brief Find the character length of a given line within the provided file.
//! \param file The FILE* to evaluate.
//! \param line_n The line number of a FILE* to be evaluated.
//! \returns The length of desired line.
extern int file_get_line_length(FILE* file, int line_n);

//! \brief Extract a string from the given line of a provided file.
//! \brief WARNING: Please note that the returned char* points to memory
//! \brief allocated through calloc(), and as such needs to be free'd.
//! \param file The FILE* to evaluate.
//! \param line_n The line number of a FILE* to be read.
//! \returns The extracted string.
extern char* file_get_line_str(FILE* file, int line_n);

//! \brief Extract an integer value from a specific line of a given file.
//! \param file The FILE* to extract an int from.
//! \param line_n The line number.
//! \returns the int value if successful, 0 if 0, or if unable to aquire int.
extern int file_get_line_int(FILE* file, int line_n);

#endif
