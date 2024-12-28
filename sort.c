#include "sort.h"

static void
swap(int *left, int *right)
{
	int tmp;

	tmp = *left;
	*left = *right;
	*right = tmp;
}

void
bubble_sort(int *arr, size_t len)
{
	for (size_t j = len - 1; j != 0; j--)
		for (size_t i = 0; i != j; i++)
			if (arr[i] > arr[i+1])
				swap(arr+i, arr+i+1);
}

void
selection_sort(int *arr, size_t len)
{
	for (size_t j = 0; j != len; j++) {
		int min = j;

		for (size_t i = j; i != len; i++)
			if (arr[min] > arr[i])
				min = i;

		swap(arr+j, arr+min);
	}
}
