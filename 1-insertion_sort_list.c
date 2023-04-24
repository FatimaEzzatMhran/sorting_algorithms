#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list with
 * the insertion sort algorithm
 *
 * @list: list to be sorted
 *
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	if (*list == NULL || (*list)->next == NULL)
		return;

	listint_t *curr = (*list)->next;

	while (curr != NULL)
	{
		listint_t *prev = curr->prev;

		while (prev != NULL && prev->n > curr->n)
		{
			listint_t *next = curr->next;

			if (prev->prev != NULL)
				prev->prev->next = curr;
			else
				*list = curr;

			curr->prev = prev->prev;
			prev->prev = curr;
			prev->next = next;

			if (next != NULL)
				next->prev = prev;

			curr->next = prev;
			prev = curr->prev;

			print_list(*list);
		}
		curr == curr->next;
	}
}

