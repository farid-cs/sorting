#include <stdbool.h>

#include "sort.h"

static void
swap(int *l, int *r)
{
	int tmp;

	tmp = *l;
	*l = *r;
	*r = tmp;
}

void
bubble_sort(int *arr, size_t len)
{
	size_t n, i; /* n is the number of elements bubbled up to the top */

	if (len < 1)
		return;
	for (n = 0; n != len-1; n++)
		for (i = 0; i != len-n-1; i++)
			if (arr[i] > arr[i+1])
				swap(arr+i, arr+i+1);
}

void
selection_sort(int *arr, size_t len)
{
	size_t min, j, i;

	if (len < 1)
		return;
	for (j = 0; j != len-1; j++) {
		min = j;
		for (i = j+1; i != len; i++)
			if (arr[min] > arr[i])
				min = i;
		swap(arr+j, arr+min);
	}
}

void
insertion_sort(int *arr, size_t len)
{
	size_t i, j;

	if (len < 1)
		return;
	for (i = 1; i != len; i++)
		for (j = i; j && arr[j] < arr[j-1]; j--)
			swap(arr+j, arr+j-1);
}

void
heap_sort(int *arr, size_t len)
{
	size_t i, j, child;

	/* construct the heap */
	for (i = 1; i != len; i++)
		for (j = i; j && arr[(j-1)/2] < arr[j]; j = (j-1)/2)
			swap(arr+j, arr+(j-1)/2);

	/* sort the array */
	i = len;
	while (true) {
		swap(arr, arr+i-1);
		i--;
		if (i == 1)
			break;
		j = 0;
		while (true) {
			child = 2*j+1;
			if (child >= i)
				break;
			if (child+1 < i)
				if (arr[child+1] > arr[child])
					child += 1;
			if (arr[child] <= arr[j])
				break;
			swap(arr+j, arr+child);
			j = child;
		}
	}
}
