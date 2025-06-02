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

	for (j = 0; j != len; j++) {
		min = j;
		for (i = j; i != len; i++)
			if (arr[min] > arr[i])
				min = i;
		swap(arr+j, arr+min);
	}
}

void
insertion_sort(int *arr, size_t len)
{
	size_t i, j, k;
	int tmp;

	for (i = 1; i != len; i++) {
		tmp = arr[i];
		for (j = 0; j <= i; j++) {
			if (tmp <= arr[j]) {
				for (k = i; k != j; k--)
					arr[k] = arr[k - 1];
				arr[j] = tmp;
				break;
			}
		}
	}
}
