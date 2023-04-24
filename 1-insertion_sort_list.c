#include "sort.h"

void swap(listint_t **head, listint_t *node1, listint_t *node2);


/**
 * insertion_sort_list - Sorts a doubly linked list of ints in an ascending
 *                       order using the Insertion sort algorithm.
 * @list: A pointer to the list to be sorted.
 * Return: void
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *iter, *insert;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (iter = (*list)->next; iter != NULL; iter = temp)
	{
		temp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap(list, insert, iter);
			print_list(*list);
		}
	}
}

/**
 * swap - swaps two nodes in a doubly linked list.
 * @head: a pointer to the head of the doubly linked list.
 * @node1: first node
 * @node2: second node
 * Return: void
 */

void swap(listint_t **head, listint_t *node1, listint_t *node2)
{
	node1->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = node1;
	node2->prev = node1->prev;
	node2->next = node1;
	if (node1->prev != NULL)
		node1->prev->next = node2;
	else
		*head = node2;
	node1->prev = node2;
	node1 = node2->prev;
}
