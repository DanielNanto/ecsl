#ifndef ECSL_STR_H_
#define ECSL_STR_H_

//! \brief Calculate how many elements are within a given "int array" string.  
//! \brief CAUTION: The given str must not contain spaces. Use str_remove_spaces() first.
//! \param str The char array to be examined
//! \returns The or number of elements within a given "int array" string.
extern int str_array_length(char* str);

//! \brief Create a clone of a string, but exclude all spaces.  
//! \brief WARNING: Please note that the 'str' argument will have memory allocated via
//! \brief malloc(), and as such will need to be free'd manually.
//! \param str The char array to be cleaned
//! \returns The new string without spaces
extern char* str_remove_spaces(char* str); 

//! \brief Convert a string to an array of integers, and return the size of the array.  
//! \brief CAUTION: If the given 'array' pointer previously pointed to memory allocated
//! \brief through aligned_alloc, calloc, malloc, or realloc, it needs to be free'd before
//! \brief use in this function.  
//! \brief WARNING: Please note that the 'array' argument will have memory allocated via
//! \brief realloc(), and as such will need to be free'd manually.
//! \param str A char array to be converted to an int array, in the format "[a,b,c]".
//! \param array A pointer to the int array to be realloc'd and populated.
//! \returns The length of the newly created array of integers, -1 if given invalid sting.
extern int str_to_array(char* str, int** array);

#endif