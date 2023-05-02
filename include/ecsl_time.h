#ifndef ECSL_TIME_H_
#define ECSL_TIME_H_

#include <stdint.h>

extern int time_compare(uint32_t time_new,
                        uint32_t time_old,
                        uint32_t period);

#endif