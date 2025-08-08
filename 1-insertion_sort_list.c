#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @a: First node
 * @b: Second node (comes after a)
 */
void swap_nodes(listint_t *a, listint_t *b)
{
	if (!a || !b || a == b)
		return;

	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;

	a->next = b->next;
	b->prev = a->prev;

	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *insertion;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		insertion = current;
		current = current->next;

		while (insertion->prev && insertion->n < insertion->prev->n)
		{
			swap_nodes(insertion->prev, insertion);
			if (!insertion->prev)
				*list = insertion;
			print_list(*list);
		}
	}
}
