/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 06:39:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/04/02 06:40:00 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	rooms_used_to_false(t_vert *rooms)
{
	while (rooms)
	{
		rooms->used = FALSE;
		rooms = rooms->next_vert;
	}
}

void	bfs_clear_queue(t_list *queue)
{
	t_list	*current;

	while (queue)
	{
		free_path(&(queue->content));
		current = queue->next;
		free(queue);
		queue = current;
	}
}

t_list	*copy_path(t_list *src)
{
	t_list	*cpy;
	t_list	*current;
	t_list	*cpy_end;

	cpy = ft_lstnew(src->content, src->content_size);
	cpy_end = cpy;
	current = src->next;
	while (current)
	{
		cpy_end->next = ft_lstnew(current->content, sizeof(t_vert *));
		cpy_end = cpy_end->next;
	}
	return (cpy)
}

int		is_reachable(t_edge *edge, t_vert *room, t_hmap *rooms)
{
	if (room->visited == FALSE && room->used == FALSE && edge->flow <= 0)
		return (TRUE);
	return (FALSE);
}