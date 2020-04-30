/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graph_set.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 17:47:58 by moana         #+#    #+#                 */
/*   Updated: 2020/04/30 17:35:24 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

/*
** -------------------------------------------------------------------------- **
** helper function for graph_new()
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
