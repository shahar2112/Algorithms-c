#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "search.h"

#define RED	printf("\033[1;31m")
#define BLUE printf("\033[1;36m")
#define MAGENTA printf("\033[1;35m")
#define YELLOW printf("\033[1;33m")
#define DEFAULT	printf("\033[0m")

static void PrintFunc(int arr[] , size_t size);

int main()
{

	int arr[] = {2, 3, 4, 5, 8, 11};
	int num = 4;
	size_t arr_size = sizeof(arr)/ sizeof(arr[1]);
	size_t i = 0;

	MAGENTA;
	printf("Interative binary search\n");
	DEFAULT;
	if(BinarySearch(arr, num, arr_size) != -1)
	{
		printf("num %d is found in array in index %d\n", num, BinarySearch(arr, num, arr_size));
	}
	else
	{
		printf("num %d not found in arr\n", num);
	}

	YELLOW;
	printf("\nRecursive binary search\n");
	DEFAULT;
	if(BinarySearchRec(arr, 0, arr_size, num) != -1)
	{
		printf("num %d is found in array in index %d\n", num, BinarySearch(arr, num, arr_size));
	}
	else
	{
		printf("num %d not found in arr\n", num);
	}


	BLUE;
	printf("\n\nTest num that doesn't exist:\n");
	DEFAULT;

	num = 6;

	MAGENTA;
	printf("\nInterative binary search\n");
	DEFAULT;
	if(BinarySearch(arr, num, arr_size) != -1)
	{
		printf("num %d is found in array in index %d\n", num, BinarySearch(arr, num, arr_size));
	}
	else
	{
		printf("num %d not found in arr\n", num);
	}

	YELLOW;
	printf("\nRecursive binary search\n");
	DEFAULT;
	if(BinarySearchRec(arr, 0, arr_size, num) != -1)
	{
		printf("num %d is found in array in index %d\n", num, BinarySearch(arr, num, arr_size));
	}
	else
	{
		printf("num %d not found in arr\n", num);
	}


	return 0;

}

static int CompareFunc(const void *num1, const void *num2)
{
	return *(int*)num1 - *(int*)num2;
}

static void PrintFunc(int arr[] , size_t size)
{
	size_t i =0;

	for (i = 0; i < size; i++)
	{
		printf("arr %ld is %d\n", i, arr[i]);
	}
	printf("\n");
}

