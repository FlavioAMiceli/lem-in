/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   copy_path.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/05 12:34:35 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/07/05 12:34:35 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*copy_node(t_list *src)
{
	t_list	*node;

	node = ft_memalloc(sizeof(t_list));
	node->content = src->content;
	node->SCORE = src->SCORE;
	node->next = NULL;
	return (node);
}

t_list			*copy_path(t_list *src)
{
	t_list	*head;
	t_list	*current;
	t_list	*tail;

	head = copy_node(src);
	tail = head;
	current = src->next;
	while (current)
	{
		tail->next = copy_node(current);
		current = current->next;
		tail = tail->next;
	}
	return (head);
}
