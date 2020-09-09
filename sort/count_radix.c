#include <stdio.h> /*print */
#include <stdlib.h> /* malloc */
#include <sys/types.h>
#include <assert.h>
#include <math.h> /* pow */

#include "sort.h"

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define DIGITS (10)

static int Max(int *arr, size_t nmemb);
static int Min(int *arr, size_t nmemb);
static int Digits(int num);
static int RadixCountSort(int *arr, size_t nmemb, int exp);

/* sorting technique based on keys between a specific range. */
int CountingSort(int *arr, size_t nmemb)
{
	ssize_t i = 0;
	ssize_t length = 0;
	ssize_t index = 0;
	int min = 0;
	int max = 0;
	int *counter_arr = NULL;
	int *third_arr = NULL;

	assert(arr);

	for (i = 0; i < nmemb; i++)
	{
		min = MIN(arr[i], min);
		max = MAX(arr[i], max);
	}

	length = max - min + 1;
	
	/* void *calloc(size_t nitems, size_t size) */
	counter_arr = (int*)calloc(length, sizeof(int));
	if (NULL == counter_arr)
	{
		fprintf(stderr, "allocation failed\n");
		return -1;
	}

	/* first stage is counting the times each element appears */
	/*starting from end to begining so it will stay stable */
	for (i = nmemb-1; i >= 0; i--)
	{
		counter_arr[arr[i] - min] +=1;
	}

	/* second stage is to sum all counter pairs */
	for ( i = 0; i < length -1; i++)
	{
		counter_arr[i + 1] += counter_arr[i];
	}
	
	/* create third array with nmemb */
	third_arr = (int*)malloc(nmemb*sizeof(int));
	if (NULL == third_arr)
	{
		fprintf(stderr, "allocation failed\n");
		free(counter_arr);
		counter_arr = NULL;
		return -1;
	}

	/* third stage is to place object in correct positions and decrease count by one */
	for (i = 0; i < nmemb; i++)
	{
		/* -1 at the end because the counting 
		starts from 1 and index starts from 0*/
		index = counter_arr[arr[i]-min] -1;
		third_arr[index] = arr[i];
		counter_arr[arr[i] -min] -= 1;
	}
	
	/*copy back to original arr */
	for (i = 0; i < nmemb; i++)
	{
		arr[i] = *(third_arr + i);
	}
	
	free(counter_arr);
	counter_arr = NULL;
	free(third_arr);
	third_arr = NULL;

	return 0;

}


/******************** Radix ************************/
int RadixSort(int *arr, size_t nmemb)
{
	int max = 0, min = 0, tocountdigits = 0, maxdigits = 0;
	size_t i =0;

	assert(arr);
	
	max = Max(arr, nmemb);
	min = Min(arr, nmemb);

	if(min<0)
	{
		min *= -1;
	}

	tocountdigits = MAX(min, max);

	maxdigits = Digits(tocountdigits);

	for (i = 1; i <= maxdigits; i++)
	{
		if(RadixCountSort(arr, nmemb, i) != 0)
		{
			return 1;
		};
		
	}
	return 0;
}


/******************** RadixCountSort ************************/
static int RadixCountSort(int *arr, size_t nmemb, int exp)
{
	ssize_t i = 0;
	int div = 0;
	int *count_arr = NULL;
	int *output = NULL;

	div = (int)pow(10, exp-1);

	count_arr = (int*)calloc((DIGITS*2 -1), sizeof(int));
	if (NULL == count_arr)
	{
		fprintf(stderr, "allocation failed\n");
		return -1;
	}

	/* count the number of times each of the digit appears */
	for(i=0; i<nmemb; i++)
	{
		int index = ((arr[i]/div) % DIGITS) + DIGITS-1;
		count_arr[index] += 1;
	}

	
   /* Change count[i] so that count[i] now contains actual  
     position of this digit in output[]  */
 	for (i = 1; i < (2*DIGITS - 1); i++)
	{
		count_arr[i] += count_arr[i-1];
	}
	
	/* allocate new place for the output */
	output = (int*)malloc(nmemb*sizeof(int));
	if (NULL == output)
	{
		fprintf(stderr, "allocation failed\n");
		free(count_arr);
		count_arr = NULL;
		return -1;
	}

	/* third stage is to place object in correct 
		positions and decrease count by one */
	for (i = nmemb-1; i >=0; i--)
	{	/* -1 at the end because the counting 
		starts from 1 and index starts from 0*/
		int index = count_arr[(arr[i]/div) % DIGITS + DIGITS-1]-1;
		output[index] = arr[i];
		count_arr[(arr[i]/div) % DIGITS + DIGITS-1] -= 1;
	}

	/*last copy back sorted output to original arr */
	for ( i = 0; i < nmemb; i++)
	{
		arr[i] = output[i];
	}
	
	free(count_arr);
	count_arr = NULL;

	free(output);
	output = NULL;

	return 0;
}	



/******************** countMax ************************/
static int Max(int *arr, size_t nmemb)
{
	int max = 0;
	ssize_t i = 0;

	for (i = 0; i < nmemb; i++)
	{
		max = MAX(arr[i], max);
	}

	return max;
}

/******************** countMin ************************/
static int Min(int *arr, size_t nmemb)
{
	int min = 0;
	ssize_t i = 0;

	for (i = 0; i < nmemb; i++)
	{
		min = MIN(arr[i], min);
	}

	return min;
}


/******************** countdigits ************************/
static int Digits(int num)
{
	int count =0;

	while(num>0)
	{
		count++;
		num = num/10;
	}

	return count;
}
