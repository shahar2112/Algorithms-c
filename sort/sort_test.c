#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#include "sort.h"

#define RED	printf("\033[1;31m")
#define BLUE printf("\033[1;36m")
#define MAGENTA printf("\033[1;35m")
#define YELLOW printf("\033[1;33m")
#define DEFAULT	printf("\033[0m")

static int CompareFunc(const void *, const void *);
static void PrintFunc(int arr[] , size_t size);

int main()
{

	int arr[] = {3, 6, 0, -5, -100, 5};
	int arr1[] = {3, 6, 0, -5, -100, 5};
    int arr2[] = {3, 6, 0, -5, -100, 5};
	int arr3[] = {3, 6, 0, -5, -100, 5};
	int arr4[] = {3, 6,0, -5, -100, 5};
	int arr5[] = {3, 6, 0, -5, -100, 5};
    int arr6[] = {3, 6, 1234, -5, -100, 5000};
    int arr7[] = {3, 6, -124, 5, 100, 50};
    
	size_t nmemb = sizeof(arr4)/ sizeof(arr4[1]);
    
	clock_t start_t, end_t, total_t;
	int *bubble = NULL;
	int *insertion = NULL;
	int *selection = NULL;
	int *queue = NULL;

	void *base = NULL;
	size_t element_size = sizeof(int);

	size_t i = 0;

	bubble = (int*)malloc(5000*sizeof(int));
 	insertion = (int*)malloc(5000*sizeof(int));
	selection = (int*)malloc(5000*sizeof(int));
	queue = (int*)malloc(5000*sizeof(int)); 
	
	for ( i = 0; i < 5000; i++)
	{
		bubble[i] = rand();
		insertion[i] = rand();
		selection[i] = rand();
	}

	base = bubble;
	start_t = clock();
	BubbleSort(base, 5000, element_size, CompareFunc);
	end_t = clock();
	total_t = (double)(end_t - start_t); /* CLOCKS_PER_SEC;*/
	printf("total time taken by CPU for BubbleSort is %ld\n", total_t);

	base = insertion;
	start_t = clock();
	InsertionSort(base, 5000, element_size, CompareFunc);
	end_t = clock();
	total_t = (double)(end_t - start_t); /* CLOCKS_PER_SEC;*/
	printf("total time taken by CPU for InsertionSort is %ld\n", total_t);

	base = selection;
	start_t = clock();
	SelectionSort(base, 5000, element_size, CompareFunc);
	end_t = clock();
	total_t = (double)(end_t - start_t); /* CLOCKS_PER_SEC;*/
	printf("total time taken by CPU for SelectionSort is %ld\n", total_t);

	base = queue;
	start_t = clock();
	qsort(base, 5000, element_size, CompareFunc);
	end_t = clock();
	total_t = (double)(end_t - start_t); /* CLOCKS_PER_SEC;*/
	printf("total time taken by CPU for qsort is %ld\n", total_t);

	free(bubble);
	free(insertion);
	free(selection);
	free(queue);

	/******************** regular tests ************************/

 	base = arr;


	RED;
	printf("before bubble sorting:\n");
	DEFAULT;
	PrintFunc(arr , nmemb);
	BubbleSort(base, nmemb, element_size, CompareFunc);
	RED;
	printf("after bubble sorting\n");
	DEFAULT;
	PrintFunc(arr , nmemb);
	base = arr5;
	BubbleSortReal(base, nmemb, element_size, CompareFunc);
	RED;
	printf("after real bubble sorting\n");
	DEFAULT;
	PrintFunc(arr5 , nmemb);


	base = arr2;
	YELLOW;
	printf("before insertion sorting:\n");
	DEFAULT;
	PrintFunc(arr2 , nmemb);
	InsertionSort(base, nmemb, element_size, CompareFunc);
	YELLOW;
	printf("after insertion sorting\n");
	DEFAULT;
	PrintFunc(arr2 , nmemb);


 	base = arr3;
	BLUE;
	printf("before  selection sorting:\n");
	DEFAULT;
	PrintFunc(arr3 , nmemb);
	SelectionSort(base, nmemb, element_size, CompareFunc);
	BLUE;
	printf("after  selection sorting\n");
	DEFAULT;
	PrintFunc(arr3 , nmemb);


	MAGENTA;
	printf("before  CountingSort sorting:\n");
	DEFAULT;
	PrintFunc(arr4 , nmemb);
	CountingSort(arr4, nmemb);
	MAGENTA;
	printf("after  CountingSort sorting:\n");
	DEFAULT;
	PrintFunc(arr4 , nmemb);

	YELLOW;
	printf("before  radix sorting:\n");
	DEFAULT;
	PrintFunc(arr1 , nmemb);
	RadixSort(arr1, nmemb);
	YELLOW;
	printf("after  radix sorting:\n");
	DEFAULT;
	PrintFunc(arr1 , nmemb);


	MAGENTA;
	printf("before  MergeSort sorting:\n");
	DEFAULT;
	PrintFunc(arr7 , nmemb);
	MergeSort(arr7, nmemb);
	MAGENTA;
	printf("after  MergeSort sorting:\n");
	DEFAULT;
	PrintFunc(arr7 , nmemb);
	
	BLUE;
	printf("before Quick sort:\n");
	DEFAULT;
	PrintFunc(arr6 , nmemb);
	QuickSort(arr6, nmemb, sizeof(int), CompareFunc);
	BLUE;
	printf("after Quick sort:\n");
	DEFAULT;
	PrintFunc(arr6 , nmemb);

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
