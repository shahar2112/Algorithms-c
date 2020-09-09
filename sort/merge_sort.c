#include <sys/types.h> /* ssize_t */
#include <assert.h> /* assert */
#include <stdlib.h>

#include "sort.h"

static int MergeAction(int arr[], size_t m, size_t arr_size);

/* devide and conqure */
int MergeSort(int *arr, size_t arr_size)
{
	if(arr_size>1)
	{
		int m = arr_size /2;

		MergeSort(arr, m);
		MergeSort(arr+m, arr_size-m);

		if(MergeAction(arr, m, arr_size))
		{
			return 1;
		}
	}
	return 0;
}


static int MergeAction(int arr[], size_t m, size_t arr_size)
{
	size_t i=0;
	size_t j=0;
	size_t merged_index;
	size_t left_size = m;
	size_t right_size = arr_size - m;
	int *left = NULL;
	int *right = NULL;

	left = (int*)malloc(left_size*sizeof(int));
	if(left == NULL)
	{
		return 1;
	}

	right = (int*)malloc(right_size*sizeof(int));
	if(right == NULL)
	{
		free(left);
		return 1;
	}

	for(i=0; i < left_size; i++)
	{
		left[i] = arr[i];
	}

	for(j=0; j < right_size; j++)
	{
		right[j] = arr[m +j];
	}

	i=0;
	j=0;
	merged_index = 0;

	while((i < left_size) && (j < right_size))
	{
		if(left[i] <= right[j])
		{
			arr[merged_index] = left[i];
			i++;
		}
		else
		{
			arr[merged_index] = right[j];
			j++;
		}
		merged_index++;
	}

	while(i < left_size)
	{
		arr[merged_index] = left[i];
		i++;
		merged_index++;
	}

	while(j < right_size)
	{
		arr[merged_index] = right[j];
		j++;
		merged_index++;
	}

	free(left);
	free(right);

	return 0;

}
