#include "sort.h"

/**
 * swap - échange deux entiers dans un tableau
 * @a: pointeur vers un entier
 * @b: pointeur vers un entier
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - trie un tableau avec l'algorithme selection sort
 * @array: tableau à trier
 * @size: taille du tableau
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_idx;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}
		if (min_idx != i)
		{
			swap(&array[i], &array[min_idx]);
			print_array(array, size);
		}
	}
}
