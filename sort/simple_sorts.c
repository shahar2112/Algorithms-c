#include <sys/types.h> /* ssize_t */
#include <assert.h> /* assert */


#include "sorting_utility.h"
#include "sort.h"



/* repeatedly compare neighbor pairs and swap if necessary. base points to start*/
void BubbleSort(void *base, size_t nmemb, size_t element_size, int (*compar)(const void *, const void *))
{
	size_t i = 0, j = 0;

	assert(base);

	for(i=0 ; i<nmemb-1; i++)
	{
		for(j=i+1 ; j<nmemb; j++)
		{
			if(compar(((char*)base + element_size*i), ((char*)base + j*element_size)) >  0)
			{
				MemSwap(((char*)base + element_size*i), ((char*)base + j*element_size), element_size);
			}
		}
	}
	
}


/* repeatedly compare neighbor pairs and swap if necessary. base points to start*/
 void BubbleSortReal(void *base, size_t nmemb, size_t element_size, int (*compar)(const void *, const void *))
{
	size_t i = 0, j = 0;

	assert(base);

	for(i=0 ; i<nmemb-1; i++)
	{
		for(j=0 ; j<nmemb-i-1; j++)
		{
			if(compar(((char*)base + element_size*j), ((char*)base + (j+1)*element_size)) >  0)
			{
				MemSwap(((char*)base + element_size*j), ((char*)base + (j+1)*element_size), element_size);
			}
		}
	}

}
 


/* repeatedly add new element to the sorted result. */
void InsertionSort(void *base, size_t nmemb, size_t element_size, int (*compar)(const void *, const void *))
{
	ssize_t i = 0, j = 0;
	size_t key = 0;

	assert(base);

	for(i=1 ; i< nmemb ; i++)
	{
		key = *((char*)base + element_size*i);
		j = i - 1;

		while( j >= 0 && (compar(((char*)base + element_size*j), &key )) > 0)
		{
			MemSwap(((char*)base + element_size*(j + 1)), ((char*)base +element_size*j), element_size);
			j = j - 1;
		}

		*((char*)base + element_size*(j + 1)) = key;
	}
		/* 	
    	for (i = 1; i < n; i++) 
		{
        key = arr[i]; 
        j = i - 1; 

		while(j>=0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j = j-1;
		}
		arr[j+1] = key; 
		}
		 */
}

/* repeatedly pick the smallest element to append to the result. */
void SelectionSort(void *base, size_t nmemb, size_t element_size, int (*compar)(const void *, const void *))
{
	size_t i = 0, j = 0;
	size_t min_ind = 0;

	assert(base);

	for(i=0; i<(nmemb-1); i++)
	{
		min_ind = i;
		for(j = i+1; j<nmemb; j++)
		{
			if(compar(((char*)base + element_size*j), ((char*)base + element_size*min_ind)) < 0)
			{
				min_ind = j;
			}
		}
		MemSwap( ((char*)base + element_size*min_ind), ((char*)base + element_size*i), element_size);
	}

/*    for (i = 0; i < n-1; i++) 
    { 
        //Find the minimum element in unsorted array 
        min_idx = i; 
        for (j = i+1; j < n; j++) 
          if (arr[j] < arr[min_idx]) 
            min_idx = j; 
  
        // Swap the found minimum element with the first element 
        swap(&arr[min_idx], &arr[i]); 
    }  */
}


