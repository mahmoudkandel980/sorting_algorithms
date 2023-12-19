#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: doubly linked list of integers
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *n = NULL;
	listint_t *nextNode = NULL;
	listint_t *inNode = NULL;

	if (list == NULL || *list == NULL)
		return;

	for (n = (*list)->next; n; n = nextNode)
	{
		nextNode = n->next;
		for (inNode = n; IF_PREV_BIGGER(inNode);)
		{
			SWAP_DOUBLE_LIST(inNode, list, listint_t *);
			print_list((const listint_t *)*list);
		}
	}
}
