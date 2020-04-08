/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg_prep.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 15:51:21 by moana         #+#    #+#                 */
/*   Updated: 2020/04/08 18:53:05 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		distance_set(t_graph *graph, t_vert *vert, t_vert *prev_vert)
{
	t_edge	*edge;

	if (vert == NULL || (vert->conn_count == 1
		&& vert != graph->sink && vert != graph->source))
		return (ERROR);
	if (vert->distance > 0 || vert == graph->source)
		return (OK);
	if (vert == graph->sink)
		vert->distance = 0;
	else if (vert != graph->sink && prev_vert != NULL && vert->distance == -1)
		vert->distance = ++(prev_vert->distance);
	edge = vert->connections;
	while (edge != NULL)
	{
		if (edge->head->distance == -1 && edge->head != prev_vert)
			distance_set(graph, edge->head, vert);
		edge = edge->next_conn;
	}
	if (vert->distance < 0)
		return (ERROR);
	return (OK);
}