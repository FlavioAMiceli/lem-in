/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg_prep.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 15:51:21 by moana         #+#    #+#                 */
/*   Updated: 2020/04/07 19:05:58 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		distance_set(t_graph *graph, t_vert *vert, int prev_distance)
{
	t_edge	*edge;

	if (vert == NULL)
		return (ERROR);
	if (vert->distance >= 0 || vert == graph->source)
		return (OK);
	if (vert->conn_count == 1)
		return (ERROR);
	vert->distance = ++prev_distance;
	edge = vert->connections;
	while (edge != NULL)
	{
		if (distance_set(graph, edge->head, vert->distance) == OK)
			return (OK);
		edge = edge->next_conn;
	}
	return (OK);
}