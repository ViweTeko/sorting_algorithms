#include "sort.h"
#include <stdio.h>

/**
 * cocktail_sort_list - sorts doubly linked list using Cocktail shaker sort
 * @list: Double pointer to head of list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp;
	char swp = 1;

	if (list == NULL || *list == NULL)
		return;
	temp = *list;
	while (swp != 0)
	{
		swp = 0;
		while (temp->next != NULL)
		{
			if (temp->next->n < temp->n)
			{
				swap(list, temp);
				swp = 1;
				print_list(*list);
			}
			else
				temp = temp->next;
		}
		if (swp == 0)
			break;
		swp = 0;
		while (temp->prev != NULL)
		{
			if (temp->next->n > temp->n)
			{
				swap(list, temp->prev);
				swp = 1;
				print_list(*list);
			}
			else
				temp = temp->prev;
		}
	}
}

/**
 * swap - swaps nodes
 * @list: the list traversed
 * @node: node to be swapped
 */
void swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}
