#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

static void
fill_rand(int *arr, size_t len)
{
	size_t i;

	for (i = 0; i != len; i++)
		arr[i] = rand();
}

static bool
ascends(int *arr, size_t len)
{
	size_t i;

	if (len < 1)
		return true;
	for (i = 0; i != len-1; i++)
		if (arr[i] > arr[i+1])
			return false;
	return true;
}

int
main(void)
{
	const size_t LENGTH = 1000;
	int arr[LENGTH];

	fill_rand(arr, LENGTH);
	bubble_sort(arr, LENGTH);
	assert(ascends(arr, LENGTH));

	fill_rand(arr, LENGTH);
	selection_sort(arr, LENGTH);
	assert(ascends(arr, LENGTH));

	fill_rand(arr, LENGTH);
	insertion_sort(arr, LENGTH);
	assert(ascends(arr, LENGTH));

	fill_rand(arr, LENGTH);
	heap_sort(arr, LENGTH);
	assert(ascends(arr, LENGTH));

	return EXIT_SUCCESS;
}
