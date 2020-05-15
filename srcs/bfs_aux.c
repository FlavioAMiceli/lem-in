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

t_list	*copy_path(t_list *src)
{
	t_list	*cpy;
	t_list	*current;
	t_list	*cpy_end;

	cpy = ft_lstnew(src->content, sizeof(t_vert *));
	cpy->SCORE = ((t_vert *)src->content)->distance;
	cpy_end = cpy;
	current = src->next;
	while (current)
	{
		cpy_end->next = ft_lstnew(current->content, sizeof(t_vert *));
		cpy_end->SCORE = ((t_vert *)current->content)->distance;
		cpy_end = cpy_end->next;
	}
	return (cpy);
}

int		is_reachable(t_edge *edge, t_vert *room)
{
	if (room->visited == FALSE && room->used == FALSE && edge->flow <= 0)
		return (TRUE);
	return (FALSE);
}
