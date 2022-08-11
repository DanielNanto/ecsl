#ifndef ECSL_FILE_H_
#define ECSL_FILE_H_

#include <stdio.h>

//! \brief Seek to the start of a given line number within the provided file.
//! \param file The file stream to seek into.
//! \param dst_line_n The desired line number to seek to.
//! \returns 0 if successful, 1 if unable to seek to desired line.
extern int escl_file_set_line(FILE* file, int dst_line_n);

//! \brief Find the character length of a given line within the provided file.
//! \param file The FILE* to evaluate
//! \param line_n The desired line number.
//! \returns length of desired line
extern int escl_file_get_line_length(FILE* file, int line_n);

#endif