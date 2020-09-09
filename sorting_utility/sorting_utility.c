#include "sorting_utility.h"

void MemSwap( void* a, void* b, size_t element_size)
{
	char temp = '\0';
	unsigned int i = 0;

	for(i=0; i<element_size; i++)
	{
			 temp = *(char*)a;
			*(char*)a = *(char*)b;
			*(char*)b = temp;
			a = (char*)a + 1;
			b = (char*)b + 1;
	}

}