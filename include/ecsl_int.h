#ifndef ECSL_INT_H_
#define ECSL_INT_H_

#include <stdio.h>
#include <math.h>

//! \brief Count the digits of a given integer.
//! \param n The int to be evaluated.
//! \returns The number of digits within the provided integer.
extern int int_get_digit_total(int n);

//! \brief Retrieve the value at the requested digit of a given integer.
//! \param n The integer to be evaluated.
//! \param digit_target The desired digit counted from left to right.
//! \returns The value at the requested digit of n if successful, -11 if
//! \returns unable to read the desired digit.
extern int int_get_digit(int n, int digit_target);

#endif