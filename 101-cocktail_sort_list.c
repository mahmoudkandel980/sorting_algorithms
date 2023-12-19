#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list of integers
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node, *nextNode = NULL, *inNode = NULL;
	int c;

	if (list == NULL || *list == NULL)
		return;
	node = *list;
	for (node = *list; node; node = nextNode)
	{
		c = 0;
		nextNode = node->next;
		for (inNode = *list; inNode;)
		{
			if (inNode->next && inNode->next->n < inNode->n)
			{	c++;
				SWAP_DOUBLE_LIST_NEXT(inNode, list, listint_t *);
				print_list((const listint_t *)*list);
				continue;
			}
			if (inNode->next)
				inNode = inNode->next;
			else
			{
				if (c != 0)
					break;
				inNode = inNode->next;
			}
		}
		for (; inNode;)
		{
			if (inNode->prev && inNode->n < inNode->prev->n)
			{
				SWAP_DOUBLE_LIST(inNode, list, listint_t *);
				print_list((const listint_t *)*list);
				continue;
			}
			if (inNode->prev == NULL)
				break;
			inNode = inNode->prev;
		}
	}
}
