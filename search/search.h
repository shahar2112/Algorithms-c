#ifndef __SIMPLE_SORTS_H__ 
#define __SIMPLE_SORTS_H__

#include <sys/types.h> /* ssize_t */
#include <stddef.h> /*size_t */

int BinarySearch(int arr[], int num, size_t arr_size);


int BinarySearchRec(int arr[], ssize_t start_index, ssize_t end_index, int num);


#endif 
