#include <sys/types.h> /* ssize_t */
#include <assert.h> /* assert */

#include "search.h"

int BinarySearch(int arr[], int num, size_t arr_size)
{
    ssize_t mid = 0;
    ssize_t right = arr_size-1;
    ssize_t left = 0;

    while(right>=left)
    {
        if(arr[mid] == num)
        {
            return mid;
        }
        if(num > arr[mid])
        {
            left = mid+1;
        }
        if(num < arr[mid])
        {
            right = mid-1;
        }
        mid = (right + left)/2;
    }

    return -1;
}


int BinarySearchRec(int arr[], ssize_t start_index, ssize_t end_index, int num)
{   
    if(start_index <= end_index)
    {
        ssize_t mid = (start_index + end_index)/2;

        if(num == arr[mid])
        {
            return mid;
        }
        if(num > arr[mid])
        {
            return BinarySearchRec(arr, mid+1, end_index, num);
        }
        if(num < arr[mid])
        {
            return BinarySearchRec(arr, start_index, mid-1, num);
        }
    }
    return -1;
}
