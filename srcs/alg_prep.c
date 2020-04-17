/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg_prep.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 15:51:21 by moana         #+#    #+#                 */
/*   Updated: 2020/04/17 19:07:15 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

/*
** -------------------------------------------------------------------------- **
** helper function for distance_set() to check if vertix is leading to nothing
** but dead-ends
**
** params
**	t_graph *graph		struct holding all information about graph
**	t_vert *vert		current vertix for which to set distance
**	t_vert *prev_vert	vertix from where we came
**
** return
**	VOID
*/

static int	is_deadend(t_graph *graph, t_vert *vert, t_vert *prev_vert)
{
	t_edge	*edge;

	if (vert == graph->source || vert == graph->sink)
		return (FALSE);
	edge = vert->connections;
	while (edge != NULL)
	{
		if (edge->head != prev_vert)
		{
			if (edge->head == graph->source || edge->head == graph->sink
				|| edge->head->distance > 0)
				return (FALSE);
		}
		edge = edge->next_conn;
	}
	return (TRUE);
}

/*
** -------------------------------------------------------------------------- **
** this function recursively travels through the graph and saves the shortest
** distance of each vertix to the sink.
** distances of vertices leading into a dead-end are set to < 0
**
** params
**	t_graph *graph		struct holding all information about graph
**	t_vert *vert		current vertix for which to set distance
**	t_vert *prev_vert	vertix from where we came in the recursive function
**
** return
**	VOID
*/

void		distance_set(t_graph *graph, t_vert *vert, t_vert *prev_vert)
{
	t_edge	*edge;

	if (vert == NULL || vert->distance == -2 || (vert->conn_count == 1
		&& vert != graph->sink && vert != graph->source))
		return ;
	if ((prev_vert != NULL
		&& vert->distance != -1 && vert->distance <= prev_vert->distance)
		|| vert == graph->source)
		return ;
	if (vert == graph->sink)
		vert->distance = 0;
	else if (vert != graph->sink && prev_vert != NULL)
		vert->distance = prev_vert->distance + 1;
	edge = vert->connections;
	while (edge != NULL)
	{
		if (edge->head != prev_vert && edge->head != graph->sink)
			distance_set(graph, edge->head, vert);
		edge = edge->next_conn;
	}
	if (is_deadend(graph, vert, prev_vert) == TRUE)
		vert->distance = -2;
	return ;
}

static int	paths_sort(t_graph *graph)
{
	int		idx;
	int		jdx;
	t_edge	*start_edge;

	start_edge = graph->source->connections;
	while (idx < graph->source->conn_count)
	{
		graph->path[idx]->path_start = start_edge->head;
		jdx = idx;
		while (jdx > 0)
		{
			if (graph->path[jdx]->path_start->distance <
				graph->path[jdx - 1]->path_start->distance)
				ft_swap(graph->path[jdx], graph->path[jdx - 1]);
			--jdx;
		}
		start_edge = start_edge->next_conn;
		++idx;
	}
}

int			paths_set(t_graph *graph)
{
	int	idx;

	graph->path = (t_path**)ft_memalloc(sizeof(t_path*)
		* graph->source->conn_count);
	if (graph->path == NULL)
		return(ERROR);
	idx = 0;
	while (idx < graph->source->conn_count)
	{
		graph->path[idx] = (t_path*)ft_memalloc(sizeof(t_path));
		if (graph->path[idx] == NULL)
			return (ERROR);
		++idx;
	}
	paths_sort(graph);
	idx = 0;
	while (idx < graph->source->conn_count)
	{
		graph->path[idx]->threshold = threshold(graph->path, idx, FALSE);
		++idx;
	}
	return (OK);
}
