#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

#define LENGTH 1000

static void
fill_rand(int *arr, size_t len)
{
	for (size_t i = 0; i != len; i++)
		arr[i] = rand();
}

static bool
ascends(int *arr, size_t len)
{
	if (len < 1)
		return true;
	for (size_t i = 0; i != len-1; i++)
		if (arr[i] > arr[i+1])
			return false;
	return true;
}

int
main(void)
{
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

	return EXIT_SUCCESS;
}
