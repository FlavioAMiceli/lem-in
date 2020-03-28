/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   edge_new_del.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 16:48:34 by moana          #+#    #+#                */
/*   Updated: 2020/03/28 11:42:59 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void		edge_del(t_edge **edge)
{
	ft_memdel(&((*edge)->invert));
	ft_memdel(edge);
}

static void	edge_set(t_edge *edge, t_graph *graph)
{
	edge->invert->tail = edge->head;
	edge->invert->head = edge->tail;
	edge->next_edge = graph->edge_list;
	graph->edge_list = edge;
	edge->next_conn = edge->tail->connections;
	edge->tail->connections = edge;
	edge->invert->next_conn = edge->invert->tail->connections;
	edge->invert->tail->connections = edge->invert;	
}

t_edge  	*edge_new(char **input_line, t_graph *graph)
{
	t_edge  *edge;
	t_edge  *edge_invert;

	edge = (t_edge*)ft_memalloc(sizeof(t_edge));
	if (edge == NULL || input_line[0] == NULL || input_line[1] == 0
		|| input_line[2] != 0)
		return (NULL);
	edge_invert = (t_edge*)ft_memalloc(sizeof(t_edge));
	if (edge_invert == NULL)
	{
		free(edge);
		return (NULL);
	}
	edge->invert = edge_invert;
	edge_invert->invert = edge;
	edge->tail = hmap_get(graph->vertices, input_line[0]);
	edge->head = hmap_get(graph->vertices, input_line[1]);
	if (edge->tail == NULL || edge->head == NULL
		|| is_duplicate(edge, edge->tail) == TRUE)
	{
		edge_del(&edge);
		return (NULL);
	}
	edge_set(edge, graph);
	return (edge);
}
