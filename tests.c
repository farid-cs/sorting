#include <assert.h>
#include <stdlib.h>

#include "sort.h"

#define LENGTH 1000

static void
fill_rand(int *arr, size_t len)
{
	for (size_t i = 0; i != len; i++)
		arr[len] = rand();
}

static int
ascends(int *arr, size_t len)
{
	for (size_t i = 0; i != len - 1; i++)
		if (arr[i] > arr[i+1])
			return 0;
	return 1;
}

int
main(void)
{
	int arr[LENGTH];

	fill_rand(arr, LENGTH);
	selection_sort(arr, LENGTH);
	assert(ascends(arr, LENGTH));

	fill_rand(arr, LENGTH);
	bubble_sort(arr, LENGTH);
	assert(ascends(arr, LENGTH));

	return 0;
}
