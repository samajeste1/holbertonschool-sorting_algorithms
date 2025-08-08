#ifndef SORT_H
#define SORT_H

#include <stddef.h>

/* Doubly linked list node */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Print helpers */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);

/* Sorting algorithms */
void bubble_sort(int *array, size_t size);

#endif /* SORT_H */
