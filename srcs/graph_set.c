/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graph_set.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 17:47:58 by moana         #+#    #+#                 */
/*   Updated: 2020/04/21 16:42:47 by moana         ########   odam.nl         */
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
** helper function for graph_set()
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

static int	edge_new(char **input_line, t_graph *graph)
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

/*
** -------------------------------------------------------------------------- **
** helper function for graph_set()
** creates a vertix in the graph
**
** params
**	char **input_line	line of input declaring a room split at ' '
**	t_graph *graph		struct holding all information about graph
**
** return
**	OK
**	ERROR
*/

static int	vert_new(char **input_line, t_graph *graph)
{
	t_vert		*vert;

	vert = (t_vert*)ft_memalloc(sizeof(t_vert));
	if (vert == 0 || input_line == NULL || input_line[0] == NULL ||
		ft_strchr(input_line[0], '-') != NULL ||
		input_line[1] == NULL || ft_isint(input_line[1]) == FALSE ||
		input_line[2] == NULL || ft_isint(input_line[2]) == FALSE ||
		input_line[3] != NULL)
		return (ERROR);
	vert->name = ft_strdup(input_line[0]);
	vert->x_coord = ft_atoi(input_line[1]);
	vert->y_coord = ft_atoi(input_line[2]);
	vert->distance = -1;
	vert->hops = -1;
	vert->next_vert = graph->vert_list;
	graph->vert_list = vert;
	if (hmap_set(graph->vertices, vert->name, vert) != 0)
		return (ERROR);
	ft_strarrdel(&input_line);
	return (OK);
}

/*
** -------------------------------------------------------------------------- **
** helper function for graph_new(), whick had to be split due to the norm
** params
**	t_graph *graph		struct holding all information about graph
**	t_input_info *input	struct holding all information from input
**
** return
**	VOID
*/

static void	graph_set(t_graph *graph, t_input_info *input)
{
	graph->source = hmap_get(graph->vertices, input->start->room_name);
	graph->sink = hmap_get(graph->vertices, input->end->room_name);
	graph->ant_count = input->ant_no;
	graph->vert_count = input->room_count;
}

/*
** -------------------------------------------------------------------------- **
** creates the graph with its vertices and edges
** catches the following errors:
**	- vertix is given twice
**	- source or sink vertix is missing
**	- coordinates of vertix are not integers
**	- the input for an egde contains two '-' (in which case it is up to inter-
**		pretation what name the vertices have)
**	- the vertices for an edge don't exist
** NOTE:
**	a duplicate edge will be added only once
**
** params
**	t_graph *graph		struct holding all information about graph
**	t_input_info *input	struct holding all information from input
**
** return
**	OK
**	ERROR
*/

int			graph_new(t_graph *graph, t_input_info *input)
{
	t_input_line	*walk;

	graph->vertices = hmap_new(input->room_count);
	if (graph->vertices == NULL)
		return (ERROR);
	walk = input->rooms;
	while (walk != NULL)
	{
		if (vert_new(ft_strsplit(walk->line, ' '), graph) == ERROR)
			return (ERROR);
		walk = walk->next_room;
	}
	walk = input->links;
	while (walk != NULL)
	{
		if (edge_new(ft_strsplit(walk->line, '-'), graph) == ERROR)
			return (ERROR);
		walk = walk->next_link;
	}
	graph_set(graph, input);
	if (graph->source == NULL || graph->sink == NULL)
		return (ERROR);
	graph->paths = (t_path**)ft_memalloc(sizeof(t_path*) *
		graph->source->conn_count + 1);
	return (OK && graph->paths != NULL);
}
