/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_star.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 10:27:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/05/12 11:15:21 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**			sink, exit vertex.
**			rooms, hmap that contains all rooms in the graph.
**	Return:	NULL if sink hasn't been reached yet,
**			otherwise shortest path in reverse.
*/
static t_list	*a_star_expand(t_list **queue, t_vert *sink)
{
	t_list	*path;
	t_list	*new_path;
	t_edge	*edge;

	path = a_star_dequeue(queue);
	edge = ((t_vert *)(path->content))->connections;
	while (edge)
	{
		// copy path, add each neighbour to front, insert into queue
		if (is_reachable(edge, path->content))
		{
			new_path = copy_path(path);
			ft_lstadd(&new_path, ft_lstnew(&(edge->head), sizeof(t_vert *)));
			new_path->SCORE = evaluate(new_path);
			// test if sink reached
			if (edge->head == sink)
			{
				free(path);
				return (new_path);
			}
			edge = edge->next_conn;
			// insert into queue
			insert_into_queue(queue, new_path);
		}
	}
	free(path);
	return (NULL);
}

/*
**	Params:	source, adress of starting room
**			sink, adress of last room
**			rooms, hmap that contains all vertices in graph
**	Return:	linked list of vertices
**			that make up the shortest path from source to sink
*/
t_list			*a_star(t_vert *source, t_vert *sink)
{
	t_list	*queue;
	t_list	*rev_path;

	init_queue(&queue, source);
	while (queue)
	{
		ft_putendl("Enter a_star_expand"); //remove
		rev_path = a_star_expand(&queue, sink);
		if (rev_path)
		{
			a_star_clear_queue(queue);
			return (ft_lstrev(&rev_path));
		}
	}
	return (NULL);
}
