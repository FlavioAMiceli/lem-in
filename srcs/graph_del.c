/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graph_del.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:46:04 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/28 17:22:37 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void	ant_del(t_ant **ant)
{
	if (ant == NULL || *ant == NULL)
		return ;
	ft_strdel(&((*ant)->name));
	ft_bzero(*ant, sizeof(t_ant));
	free(*ant);
	*ant = NULL;
}

void	vert_del(t_vert **vert)
{
	if (vert == NULL || *vert == NULL)
		return ;
	ft_strdel(&((*vert)->name));
	ft_bzero((*vert), sizeof(t_vert));
	free((*vert));
	(*vert) = NULL;
}

void	edge_del(t_edge **edge)
{
	if (edge == NULL || *edge == NULL)
		return ;
	ft_bzero((*edge)->invert, sizeof(t_edge));
	if ((*edge)->invert != NULL)
		free(((*edge)->invert));
	ft_bzero((*edge), sizeof(t_edge));
	free((*edge));
	(*edge) = NULL;
}

void	path_del(t_graph *graph)
{
	unsigned int	i;

	i = 0;
	while (i < graph->path_count && graph->paths[i])
	{
		ft_bzero(graph->paths[i], sizeof(t_path));
		free(graph->paths[i]);
		graph->paths[i] = NULL;
		i++;
	}
	free(graph->paths);
	graph->paths = NULL;
}

void	graph_del(t_graph *graph)
{
	t_edge	**walk_edge;
	t_edge	*del_edge;
	t_vert	**walk_vert;
	t_vert	*del_vert;

	walk_edge = &(graph->edge_list);
	if (graph->paths != NULL)
		path_del(graph);
	while ((*walk_edge) != NULL)
	{
		del_edge = (*walk_edge);
		(*walk_edge) = (*walk_edge)->next_edge;
		edge_del(&del_edge);
	}
	walk_vert = &(graph->vert_list);
	while ((*walk_vert) != NULL)
	{
		del_vert = (*walk_vert);
		(*walk_vert) = (*walk_vert)->next_vert;
		hmap_del_slot(graph->vertices, del_vert->name);
		vert_del(&del_vert);
	}
	hmap_del_map(&(graph->vertices));
	ft_bzero(graph, sizeof(t_graph));
}
