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

void	bfs_clear_queue(t_list *queue)
{
	while (queue)
	{
		ft_lstdel(&(queue->content), ft_strdel);
		queue = queue->next;
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
		cpy_end->next = ft_lstnew(current->content->name,
			ft_strlen(current->content->name));
		cpy_end = cpy_end->next;
	}
	return (cpy)
}

int		is_reachable(
	t_vert *vert, char *next_room, t_hmap *rooms, t_hmap *used)
{
	if (hmap_get(rooms, next_room)->visited == FALSE
		&& hmap_get(used, next_room) == NULL)
		return (TRUE);
	return (FALSE);
}