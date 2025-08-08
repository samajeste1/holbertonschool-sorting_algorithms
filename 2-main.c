#include <stdio.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {64, 25, 12, 22, 11};
	size_t n = sizeof(array) / sizeof(array[0]);

	print_array(array, n);
	selection_sort(array, n);
	print_array(array, n);
	return (0);
}
