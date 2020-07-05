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
#include <fcntl.h>			//REMOVE
#include <unistd.h>			//REMOVE
#include <stdlib.h>			//REMOVE

static int		no_back_flow(t_edge *edge, t_list *path)
{
	if (!path->next)
		return (TRUE);
	else if (edge->head != ((t_list *)path->next)->content)
		return (TRUE);
	return (FALSE);
}

static int		is_traversable(t_edge *edge, t_list *path, t_vert *source)
{
	t_edge *prev_edge;

	if (edge->flow <= 0 && edge->head->used == FALSE)
	{
		if (edge->flow < 0)
			return (TRUE);
		else if (edge->tail->visited == FALSE || edge->tail == source)
			return (TRUE);
		else if (path->next)
		{
			prev_edge = ((t_vert *)path->next->content)->connections;
			while (prev_edge->head != edge->tail)
				prev_edge = prev_edge->next_conn;
			if (prev_edge->flow < 0)
				return (TRUE);
		}
	}
	return (FALSE);
}

static t_list	*new_path_alloc(t_edge *edge, t_list *path)
{
	t_list	*new_path;

	new_path = (t_list *)ft_memalloc(sizeof(t_list));
	new_path->content = edge->head;
	new_path->next = copy_path(path);
	new_path->SCORE = evaluate(new_path);
	return (new_path);
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**			sink, exit vertex.
**			rooms, hmap that contains all rooms in the graph.
**	Return:	NULL if sink hasn't been reached yet,
**			otherwise shortest path in reverse.
*/

static t_list	*a_star_expand(t_list **queue, t_vert *sink, t_vert *source)
{
	t_list	*path;
	t_list	*new_path;
	t_edge	*edge;

	path = a_star_dequeue(queue);
	edge = ((t_vert *)path->content)->connections;
	while (edge)
	{
		if (no_back_flow(edge, path) && is_traversable(edge, path, source))
		{
			edge->head->used = TRUE;
			new_path = new_path_alloc(edge, path);
			if (edge->head == sink)
			{
				free_path(path);
				return (new_path);
			}
			insert_into_queue(queue, new_path);
		}
		edge = edge->next_conn;
	}
	free_path(path);
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
	while (queue && queue->content != NULL)
	{
		rev_path = a_star_expand(&queue, sink, source);
		// ft_putendl("a_star expand"); //remove
		// sleep(3); //remove
		if (rev_path)
		{
			// sleep(1);
			// ft_putendl("pre clear queue"); //remove
			// sleep(3); //remove
			// ft_putendl("clearing queue"); //remove
			a_star_clear_queue(&queue);
			// ft_putendl("post clear queue"); //remove
			// sleep(3); //remove
			return (ft_lstrev(&rev_path));
		}
	}
	return (NULL);
}
