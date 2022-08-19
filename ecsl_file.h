#ifndef ECSL_FILE_H_
#define ECSL_FILE_H_

#include <stdio.h>
#include <stdlib.h>

//! \brief Seek to the start of a given line number within the provided file.
//! \param file The FILE* to seek into.
//! \param line_n The line number requested to seek to.
//! \returns 0 if successful, 1 if unable to seek to the desired line.
extern int ecsl_file_set_line(FILE* file, int line_n);

//! \brief Find the character length of a given line within the provided file.
//! \param file The FILE* to evaluate.
//! \param line_n The line number of a FILE* to be evaluated.
//! \returns the length of desired line.
extern int ecsl_file_get_line_length(FILE* file, int line_n);

//! \brief Extract a string from the given line of a provided file.
//! \brief WARNING: Please note that the returned char* points to memory
//! \brief allocated through calloc(), and as such needs to be free'd.
//! \param file The FILE* to evaluate.
//! \param line_n The line number of a FILE* to be read.
//! \returns the extracted string.
extern char* ecsl_file_get_line_str(FILE* file, int line_n);

#endif