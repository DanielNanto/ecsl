#ifndef ECSL_STR_H_
#define ECSL_STR_H_

//! \brief Convert a string to an array of integers, and return the size of the array.  
//! \brief CAUTION: If the given 'array' pointer previously pointed to memory allocated
//! \brief through aligned_alloc, calloc, malloc, or realloc, it needs to be free'd before
//! \brief use in this function.  
//! \brief WARNING: Please note that the 'array' argument will have memory allocated via
//! \brief realloc(), and as such will need to be free'd manually.
//! \param str A char array to be converted to an int array, in the format "[a,b,c,d]".
//! \param array A pointer to the int array to be realloc'd and populated.
//! \returns The length of the newly created array of integers, -1 if given invalid sting.
extern int str_to_array(char* str, int** array);

extern int str_array_length(char* str);

extern char* str_remove_spaces(char* str); 

#endif