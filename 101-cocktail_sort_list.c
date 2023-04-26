#include "sort.h"

/**
 * swap_nodes - Swaps two nodes of a doubly linked list
 * @list: Pointer to a pointer to the head of the list
 * @node1: Pointer to the first node to swap
 * @node2: Pointer to the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev1 = node1->prev, *next2 = node2->next;

	if (prev1)
		prev1->next = node2;
	else
		*list = node2;
	node2->prev = prev1;
	node2->next = node1;
	node1->prev = node2;
	node1->next = next2;
	if (next2)
		next2->prev = node1;
}
/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order
 * using the Cocktail Shaker Sort algorithm
 * @list: Pointer to a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = *list, *right = NULL, *curr = NULL;
	int swapped = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	do
	{
		swapped = 0;
		while (left->next != right)
		{
			curr = left;
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				left = left->next;
			}
		}
		if (!swapped)
			break;
		swapped = 0;
		right = left;
		while (right != *list)
		{
			curr = right;
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				right = right->prev;
			}
		}
		left = left->prev;
	}
	while (swapped);
}
