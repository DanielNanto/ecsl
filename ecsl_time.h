#ifndef ECSL_TIME_H_
#define ECSL_TIME_H_

#include <stdint.h>

//! \brief Assess if a given 'period' of time has passed between the provided 
//! \brief 'old' and 'new' times.  
//! \param new The uint32_t 'new' time.
//! \param old The uint32_t 'old' time.
//! \param period The target period of time to be compared.
//! \returns 1 if the target period of time has passed, 0 if not.
int time_compare(uint32_t time_new,
                 uint32_t time_old,
                 uint32_t period);

#endif