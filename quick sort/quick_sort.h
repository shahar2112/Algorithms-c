#ifndef __SIMPLE_SORTS_H__ 
#define __SIMPLE_SORTS_H__

#include <stddef.h> /*size_t */

/*nmemb number of elements, size is element size */
void QuickSort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));

#endif 
