/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max_flow.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 18:13:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/05/12 11:16:58 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

/*
**	Params: edge, to find rooms that have modified flow
**	Return:
*/

static void		update_visited_status(t_edge *edge)
{
	int		visited;

	visited = edge->flow != 0 ? TRUE : FALSE;
	edge->head->visited = visited;
	edge->tail->visited = visited;
}

/*
**	Params:	path, list containing vertices used
**	Return:
*/

static void		update_flow(t_list *path)
{
	t_edge	*edge;
	t_list	*tmp;

	while (path)
	{
		if (!ft_strequ(((t_vert *)path->content)->name, "snk"))
		{
			edge = ((t_vert *)path->content)->connections;
			while (edge->head != path->next->content)
				edge = edge->next_conn;
			edge->flow += 1;
			edge = edge->invert;
			edge->flow -= 1;
			update_visited_status(edge);
		}
		tmp = path;
		path = path->next;
		free(tmp);
	}
}

/*
**	Params: s, current vertex to update
**			hop, number of hops to reach current vertex
**	Return:
*/

static void		update_hops(t_vert *s, int hop)
{
	t_edge	*edge;

	s->hops = hop;
	edge = s->connections;
	while (edge)
	{
		if (edge->flow == 1)
			update_hops(edge->head, hop + 1);
		edge = edge->next_conn;
	}
}

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
		if (edge->head->visited == FALSE && edge->head->distance < min_dist)
		{
			next_start = edge->head;
			min_dist = edge->head->distance;
		}
		edge = edge->next_conn;
	}
	return (next_start);
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
	while (keep_searching(graph, new_start))
	{
		rooms_used_to_false(graph->vert_list);
		// ft_putendl("Enter a_star"); // REMOVE
		aug_path = a_star(graph->source, graph->sink);
		// ft_putendl("Exit a_star"); // REMOVE
		if (aug_path)
		{
			ft_putendl("Updating_graph flow"); // REMOVE
			update_flow(aug_path);
			ft_putendl("Updating_graph hops"); // REMOVE
			update_hops(graph->source, 0);
		}
		// ft_putendl("get_next_start"); // REMOVE
		new_start = get_next_start(graph->source);
	}
}
