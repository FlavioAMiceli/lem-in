/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bfs.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/02 06:37:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/04/02 06:38:00 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*bfs_expand(
	t_list *rev_path, t_list *end_queue, t_hmap *used, t_vert *sink, t_hmap *rooms)
{
	t_list	*new_path;
	t_list	*path_current;
	t_room	*current;
	char	**neighbours;

	neighbours = rev_path->content->neighbours;
	while (neighbours)
	{
		// copy path, add each neighbour to front, append to end_queue
		if (is_reachable(rev_path->content, *neighbours, rooms, used))
		{
			new_path = copy_path(rev_path);
			ft_lstadd(&new_path, ft_lstnew(*neighbours), ft_strlen(*neighbours));
			(*neighbours)++;
			// append to end_queue
			end_queue->next = ft_lstnew(&new_path, sizeof(t_list *));
		}
		// free old path
		// test if sink reached -> free other paths and return path
	}
	return (NULL);
}

t_list	*bfs(t_vert *source, t_vert *sink, t_hmap *rooms)
{
	t_list	*queue;
	t_list	*end_queue;
	t_list	*rev_path;
	t_hmap	*used;

	used = hmap_new((((rooms->n) / 3) * 2), free);
	queue = (t_list*)ft_memalloc(sizeof(t_list));
	end_queue = queue;
	queue->content = source;
	while (queue)
	{
		rev_path = ft_dequeue(queue);
		rev_path = bfs_expand(rev_path, end_queue, used, sink, rooms);
		if (rev_path)
		{
			bfs_clear_queue(queue);
			return (ft_lstrev(rev_path));
		}
	}
	return (NULL);
}