/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max_flow.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 18:13:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/07/04 16:01:36 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <fcntl.h>			//REMOVE
#include <unistd.h>			//REMOVE

/*
**	Params:	s, source vertex
**
**	Return: Unvisited vertex connected to source with lowest distance to sink
*/

static t_vert	*get_next_start(t_vert *s)
{
	t_vert	*next_start;
	t_edge	*edge;
	int		min_dist;

	edge = s->connections;
	min_dist = FT_INT_MAX;
	next_start = NULL;
	while (edge)
	{
		if (edge->head->visited == FALSE && edge->head->distance < min_dist \
			&& edge->head->distance > 0)
		{
			next_start = edge->head;
			min_dist = edge->head->distance;
		}
		edge = edge->next_conn;
	}
	return (next_start);
}

static int		revert(t_graph *graph)
{
	(void)graph;
	return (FALSE);
}

static void		clear_aug_path(t_graph *graph, t_list *aug_path)
{
	t_list	*to_free;

	if (!aug_path)
		return ;
	if (revert(graph))
	{
		revert_flow(aug_path);
		update_visited_status(aug_path);
		update_hops(graph->sink, 0);
	}
	while (aug_path)
	{
		to_free = aug_path;
		aug_path = aug_path->next;
		free(to_free);
	}
}

/*
**	Params:	graph, struct containing all information about the graph
**
**	Return:
*/

void			edmonds_karp(t_graph *graph)
{
	t_list	*aug_path;
	t_vert	*new_start;

	new_start = get_next_start(graph->source);
	while (new_start != NULL && keep_searching(graph, new_start))
	{
		rooms_used_to_false(graph->vert_list);
		aug_path = a_star(graph->source, graph->sink);
		if (aug_path)
		{
			update_flow(aug_path);
			update_visited_status(aug_path);
			update_hops(graph->sink, 0);
			path_new(graph, aug_path->next->content);
		}
		else
			break ;
		new_start = get_next_start(graph->source);
		clear_aug_path(graph, aug_path);
	}
}
