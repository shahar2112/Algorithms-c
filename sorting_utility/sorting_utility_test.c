#include <stdio.h>

#include "sorting_utility.h"

int main()
{
	int a = 5;
	int b = 2;

	printf("before swapping numbers are: a=%d, b=%d\n", a, b);

	MemSwap( &a, &b, sizeof(int));

	printf("after swapping numbers are: a=%d, b=%d\n", a, b);


	return 0;
}