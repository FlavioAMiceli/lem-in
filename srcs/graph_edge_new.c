/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graph_edge_new.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/30 17:32:45 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/04/30 17:34:17 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

/*
** -------------------------------------------------------------------------- **
** helper function for edge_new()
** checks if the new edge is already saved in its tail
**
** params
**	t_edge *new_edge	the struct for the new egde
**
** return
**	OK
**	ERROR
*/

static int	edge_is_duplicate(t_edge *new_edge)
{
	t_edge	*walk;

	walk = new_edge->tail->connections;
	while (walk != NULL)
	{
		if (walk->head == new_edge->head)
			return (TRUE);
		walk = walk->next_conn;
	}
	return (FALSE);
}

/*
** -------------------------------------------------------------------------- **
** helper function for edge_new()
** sets all the pointers for the new edge and its invert edge
**
** params
**	t_edge *edge	the struct for the new egde
**	t_graph *graph	struct holding all information about graph
**
** return
**	OK
**	ERROR
*/

static void	edge_set(t_edge *edge, t_graph *graph)
{
	t_edge	*edge_invert;

	++(edge->head->conn_count);
	++(edge->tail->conn_count);
	edge->next_edge = graph->edge_list;
	graph->edge_list = edge;
	edge->next_conn = edge->tail->connections;
	edge->tail->connections = edge;
	edge_invert = edge->invert;
	edge_invert->invert = edge;
	edge_invert->tail = edge->head;
	edge_invert->head = edge->tail;
	edge_invert->next_conn = edge_invert->tail->connections;
	edge_invert->tail->connections = edge_invert;
}

/*
** -------------------------------------------------------------------------- **
** helper function for graph_new()
** creates a directed edge and its invert edge in the graph and links it to its
** head and tail vertices
**
** params
**	char **input_line	line of input declaring a room split at '-'
**	t_graph *graph		struct holding all information about graph
**
** return
**	OK
**	ERROR
*/

int			edge_new(char **input_line, t_graph *graph)
{
	t_edge	*edge;

	edge = (t_edge*)ft_memalloc(sizeof(t_edge));
	if (edge == NULL
		|| input_line[0] == NULL || input_line[1] == 0 || input_line[2] != 0)
		return (strarrdel_edgedel_and_return(ERROR, &input_line, &edge));
	edge->invert = (t_edge*)ft_memalloc(sizeof(t_edge));
	if (edge->invert == NULL)
		return (strarrdel_edgedel_and_return(ERROR, &input_line, &edge));
	edge->tail = hmap_get(graph->vertices, input_line[0]);
	edge->head = hmap_get(graph->vertices, input_line[1]);
	if (edge->tail == NULL || edge->head == NULL)
		return (strarrdel_edgedel_and_return(ERROR, &input_line, &edge));
	if (edge->head == edge->tail || edge_is_duplicate(edge))
		return (strarrdel_edgedel_and_return(OK, &input_line, &edge));
	edge_set(edge, graph);
	return (strarrdel_and_return(OK, &input_line));
}
