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

static void		free_path(t_list **path)
{
	t_list	*current;

	current = *path;
	while (current)
	{
		next = current->next;
		ft_memdel(current);
		current = next;
	}
	path = NULL;
}

static t_list	*bfs_expand(
	t_list *rev_path, t_list **end_queue, t_vert *sink, t_hmap *rooms)
{
	edge = rev_path->content->connections
	while (edge)
	{
		// copy path, add each neighbour to front, append to end_queue
		if (is_reachable(edge, rev_path->content, rooms))
		{
			new_path = copy_path(rev_path);
			ft_lstadd(&new_path, ft_lstnew(&(edge->head), sizeof(t_vert *)));
			// test if sink reached
			if (edge->head == sink)
			{
				free(rev_path);
				return (new_path);
			}
			edge = edge->next_conn;
			// append to end_queue
			(*end_queue)->next = new_path;
			end_queue = &new_path;

	}
	free(rev_path);
	return (NULL);
}

t_list	*bfs(t_vert *source, t_vert *sink, t_hmap *rooms)
{
	t_list	*queue;
	t_list	*end_queue;
	t_list	*rev_path;

	queue = (t_list*)ft_memalloc(sizeof(t_list));
	end_queue = queue;
	queue->content = source;
	while (queue)
	{
		rev_path = ft_dequeue(queue);
		rev_path = bfs_expand(rev_path, &end_queue, sink, rooms);
		if (rev_path)
		{
			bfs_clear_queue(queue);
			return (ft_lstrev(rev_path));
		}
	}
	return (NULL);
}