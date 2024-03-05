#include "sort.h"

/**
 * swap_nodes - swaps two nodes.
 *
 * @list: the head of the list
 * @node1: node 1
 * @node2: node 2
 * Return: a pointer to the swapped node.
 */
listint_t *swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *next, *prev;

	prev = node2->prev;
	next = node1->next;

	node2->next = next;
	node1->next = node2;
	if (prev)
		prev->next = node1;
	else
		*list = node1;

	node2->prev = node1;
	node1->prev = prev;
	if (next)
		next->prev = node2;

	print_list(*list);
	return (node2);
}
/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: the list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *current = NULL;

	if (!list || !(*list))
		return;

	node = (*list)->next;
	while (node)
	{
		if (node->n < node->prev->n)
		{
			node = swap_nodes(list, node, node->prev);
			current = node->prev;
			while (current && current->prev && current->n < current->prev->n)
			{
				current = swap_nodes(list, current, current->prev);
				current = current->prev;
			}
		}
		node = node->next;
	}
}
