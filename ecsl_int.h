#ifndef ECSL_INT_H_
#define ECSL_INT_H_

#include <math.h>

//! \brief Count the digits of a given integer. If the integer is negative, one
//! \brief one additional digit is included for the sign.
//! \param n The int to be evaluated.
//! \returns The number of digits within the provided integer.
extern int int_get_length(int n);

#endif