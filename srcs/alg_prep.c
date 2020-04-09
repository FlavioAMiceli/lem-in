/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg_prep.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 15:51:21 by moana         #+#    #+#                 */
/*   Updated: 2020/04/09 17:38:51 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int	is_deadend(t_graph *graph, t_vert *vert, t_vert *prev_vert)
{
	t_edge	*edge;

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

int		distance_set(t_graph *graph, t_vert *vert, t_vert *prev_vert)
{
	t_edge	*edge;

	if (vert == NULL || vert->distance == -2 || (vert->conn_count == 1
		&& vert != graph->sink && vert != graph->source))
		return (ERROR);
	if ((prev_vert != NULL
		&& vert->distance != -1 && vert->distance <= prev_vert->distance)
		|| vert == graph->source)
		return (OK);
	if (vert == graph->sink)
		vert->distance = 0;
	else if (vert != graph->sink && prev_vert != NULL)
		vert->distance = prev_vert->distance + 1;
	edge = vert->connections;
	while (edge != NULL)
	{
		if (edge->head != prev_vert && edge->head != graph->sink
			&& distance_set(graph, edge->head, vert) == OK && vert != graph->sink
			&& edge->next_conn == NULL)
			// return (OK);
			break ;
		edge = edge->next_conn;
	}	
	if (vert != graph->source && vert != graph->sink
		&& is_deadend(graph, vert, prev_vert) == TRUE)
		vert->distance = -2;
	return (OK);
}