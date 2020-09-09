#include <sys/types.h> /* ssize_t */
#include <assert.h> /* assert */
#include <time.h> /* rand */
#include <stdlib.h> /* rand */

#include "sorting_utility.h"
#include "sort.h"

static void QuickSortHelp(void *base, ssize_t left, ssize_t right, size_t size, int(*compar)(const void *, const void *), size_t nmemb);
static int partition(void *base, ssize_t left, ssize_t right, size_t size, int(*compar)(const void *, const void *), size_t nmemb);


void QuickSort(void *base, size_t nmemb, size_t size, int(*compar)(const void *, const void *))
{

	assert(base && compar);
	
	QuickSortHelp(base, 0, nmemb-1, size, compar, nmemb);
	
}


static void QuickSortHelp(void *base, ssize_t left, ssize_t right, size_t size, int(*compar)(const void *, const void *), size_t nmemb)
{
	if(left < right)
	{
		ssize_t pivot = partition(base, left, right, size, compar, nmemb);

		QuickSortHelp(base, left, pivot -1, size, compar, nmemb);
		QuickSortHelp(base, pivot +1, right, size, compar, nmemb);
	}
}


static int partition(void *base, ssize_t left, ssize_t right, size_t size, int(*compar)(const void *, const void *), size_t nmemb)
{
 	ssize_t pivot = 0;
	ssize_t i = 0, j = 0;

	i = left;

	pivot = left + rand()%(right-left);

	MemSwap((char *)base + pivot*size, (char *)base + right*size, size);

	for(j = left ; j < right; j++)
	{

		if(compar((char *)base + j*size, (char *)base + right*size) < 0)
		{
			MemSwap((char *)base + j*size, (char *)base + i*size, size);
			i++;
		}
	}

	MemSwap((char *)base + right*size, (char *)base + i*size, size);

	return i;
} 


