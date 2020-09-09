#ifndef __SIMPLE_SORTS_H__ 
#define __SIMPLE_SORTS_H__

#include <stddef.h> /*size_t */

/* repeatedly compare neighbor pairs and swap if necessary. */
void BubbleSort(void *base, size_t nmemb, size_t element_size, int (*compar)(const void *a, const void *b));

/* repeatedly pick the smallest element to append to the result. */
void SelectionSort(void *base, size_t nmemb, size_t element_size, int (*compar)(const void *, const void *));

/* repeatedly add new element to the sorted result. */
void InsertionSort(void *base, size_t nmemb, size_t element_size, int (*compar)(const void *, const void *));

/* repeatedly compare neighbor pairs and swap if necessary. base points to start*/
 void BubbleSortReal(void *base, size_t nmemb, size_t element_size, int (*compar)(const void *, const void *));
 
 /* sorting technique based on keys between a specific range. */
int CountingSort(int *arr, size_t nmemb);

/* integer sorting algorithm that sorts data with integer keys
 by grouping the keys by individual digits that share the same 
 significant position and value (place value). Radix sort uses
 counting sort as a subroutine to sort an array of numbers.*/
int RadixSort(int *arr, size_t nmemb);

int MergeSort(int *arr, size_t arr_size);

/*nmemb number of elements, size is element size */
void QuickSort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *));

#endif 
