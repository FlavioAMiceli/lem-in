/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs_aux.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 06:39:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/05/12 11:16:24 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	bfs_clear_queue(t_list *queue)
{
	t_list	*current;

	while (queue)
	{
		free_path((t_list **)&(queue->content));
		current = queue->next;
		free(queue);
		queue = current;
	}
}

void	free_path(t_list **path)
{
	t_list	*current;
	t_list	*next;

	current = *path;
	while (current)
	{
		next = current->next;
		ft_memdel((void **)&current);
		current = next;
	}
	path = NULL;
}

static t_list	*copy_node(t_list *src)
{
	t_list	*node;

	node = ft_memalloc(sizeof(t_list));
	node->content = src->content;
	node->SCORE = src->SCORE;
	node->next = NULL;
	return (node);
}

t_list	*copy_path(t_list *src)
{
	t_list	*head;
	t_list	*current;
	t_list	*tail;

	ft_putendl("Enter copy_path"); //remove
	// ft_putstr("Current src: "); //remove
	// ft_putstr(((t_vert *)src->content)->name); //remove
	// ft_putchar('\n'); //remove
	head = copy_node(src);
	tail = head;
	current = src->next;
	// if (current)
	// {
	// 	ft_putstr("Next src: "); //remove
	// 	ft_putstr(((t_vert *)current->content)->name); //remove
	// 	ft_putchar('\n'); //remove
	// }
	// ft_putstr("Current copy: "); //remove
	// ft_putstr(((t_vert *)head->content)->name); //remove
	// ft_putchar('\n'); //remove
	// ft_putstr("Score: "); //remove
	// ft_putnbr(cpy->SCORE); //remove
	// ft_putchar('\n'); //remove
	while (current)
	{
		tail->next = copy_node(current);
		current = current->next;
		tail = tail->next;
	}
	return (head);
}

int		is_reachable(t_edge *edge, t_vert *room)
{
	if (room->visited == FALSE && room->used == FALSE && edge->flow <= 0)
		return (TRUE);
	return (FALSE);
}
