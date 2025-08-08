#include "sort.h"

/**
 * swap_ints - Swaps two integers
 * @a: Pointer to first int
 * @b: Pointer to second int
 */
void swap_ints(int *a, int *b)
{
	if (a != b)
	{
		int tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for quicksort
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the array (for printing)
 * Return: Index of the pivot
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			if (i != j)
				print_array(array, size);
		}
	}

	if (array[i + 1] != array[high])
	{
		swap_ints(&array[i + 1], &array[high]);
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort_recursive - Recursively sorts array using quicksort
 * @array: Array to sort
 * @low: Start index
 * @high: End index
 * @size: Size of the array (for printing)
 */
void quicksort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);

		quicksort_recursive(array, low, pi - 1, size);
		quicksort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers using quick sort
 * @array: The array to sort
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_recursive(array, 0, size - 1, size);
}
