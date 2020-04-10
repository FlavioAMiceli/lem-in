/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_star.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 10:27:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/04/07 10:29:10 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_list	*a_star_expand(t_list **queue, t_vert *sink, t_hmap *rooms)
{
	rev_path = a_star_dequeue(queue);
	edge = rev_path->content->connections
	while (edge)
	{
		// copy path, add each neighbour to front, insert into queue
		if (is_reachable(edge, rev_path->content, rooms))
		{
			new_path = copy_path(rev_path);
			ft_lstadd(&new_path, ft_lstnew(&(edge->head), sizeof(t_vert *)));
			new_path->SCORE = evaluate(new_path);
			// test if sink reached
			if (edge->head == sink)
			{
				free(rev_path);
				return (new_path);
			}
			edge = edge->next_conn;
			// insert into queue
			insert_into_queue(queue, new_path);
	}
	free(rev_path);
	return (NULL);
}

t_list			*a_star(t_vert *source, t_vert *sink, t_hmap *rooms)
{
	t_list	*queue;
	t_list	*rev_path;

	init_queue(&queue, source);
	while (queue)
	{
		rev_path = a_star_expand(&queue, sink, rooms);
		if (rev_path)
		{
			a_star_clear_queue(queue);
			return (ft_lstrev(rev_path));
		}
	}
	return (NULL);
}