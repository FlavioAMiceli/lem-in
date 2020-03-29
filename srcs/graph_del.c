/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graph_del.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:46:04 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/29 12:17:03 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void	vert_del(t_vert **vert)
{
	ft_strdel(&((*vert)->name));
	ft_memdel(vert);
}

void		edge_del(t_edge **edge)
{
	ft_memdel(&((*edge)->invert));
	ft_memdel(edge);
}

void	graph_del(t_graph *graph)
{
	t_edge	**walk_edge;
	t_edge	*del_edge;
	t_vert	**walk_vert;
	t_vert	*del_vert;

	(*walk_edge) = graph->edge_list;
	while ((*walk_edge) != NULL)
	{
		del_edge = (*walk_edge);
		(*walk_edge) = (*walk_edge)->next_edge;
		edge_del(&del_edge);
	}
	(*walk_vert) = graph->vert_list;
	while ((*walk_vert) != NULL)
	{
		del_vert = (*walk_vert);
		(*walk_vert) = (*walk_vert)->next_vert;
		hmap_del(graph->vertices, del_vert->name);
		del_vert = NULL;
	}
	ft_memdel(&(graph->vertices));
	ft_bzero(graph, sizeof(t_graph));
}
