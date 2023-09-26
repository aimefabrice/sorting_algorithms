#include "sort.h"
void swap_nodes(listint_t **node, listint_t **back, listint_t *bef);

/**
 * insertion_sort_list - sort the list of integers
 * @list: pointer to the linkedlist to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *tmp, *mark, *node, *pre;

	if (!list || !*list || !(*list)->next)
		return;
	node = *list;
	for (tmp = node->next; tmp; tmp = mark)
	{
		mark =  tmp->next;
		pre = tmp->prev;
		while (pre)
		{
			if (tmp->n < pre->n)
			{
				swap_nodes(list, &pre, tmp);
				print_list(*list);
			}
			pre = pre->prev;
		}
	}
}
/**
 * swap_nodes - swap two nodes of a linkedlist
 * @node: the linked list
 * @back: pointer to the node we push back
 * @bef: pointer to the node we insert before back
 *
 * Description: It will be in a way that back->prev = bef and
 *	bef->next = pre
 */
void swap_nodes(listint_t **node, listint_t **back, listint_t *bef)
{
	(*back)->next = bef->next;
	if (bef->next)
		bef->next->prev = *back;
	bef->next = *back;
	if ((*back)->prev)
		(*back)->prev->next = bef;
	else
		*node = bef;
	bef->prev = (*back)->prev;
	(*back)->prev = bef;
}
