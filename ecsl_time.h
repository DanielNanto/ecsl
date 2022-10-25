#ifndef ECSL_TIME_H_
#define ECSL_TIME_H_

#include <stdint.h>

int time_compare(uint32_t new,
                 uint32_t old,
                 uint32_t period);

#endif