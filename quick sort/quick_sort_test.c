#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "quick_sort.h"

#define RED	printf("\033[1;31m")
#define BLUE printf("\033[1;36m")
#define MAGENTA printf("\033[1;35m")
#define YELLOW printf("\033[1;33m")
#define DEFAULT	printf("\033[0m")

static int CompareFunc(const void *, const void *);
static void PrintFunc(int arr[] , size_t size);

int main()
{
	int arr[] = {3, 6, -100, 7, 25, 5};

	void *base = NULL;
	size_t element_size = sizeof(int);
	size_t nmemb = sizeof(arr)/ sizeof(arr[1]);
	size_t i = 0;

	printf("before:\n");
	PrintFunc(arr , nmemb);

	QuickSort(arr, nmemb, sizeof(int), CompareFunc);
	printf("after:\n");
	PrintFunc(arr , nmemb);
	/******************** regular tests ************************/


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
