/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graph_del.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/27 17:47:58 by moana          #+#    #+#                */
/*   Updated: 2020/03/27 17:48:30 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

void	graph_del(t_graph *graph)
{
	int				i;
	t_input_line	*room;

	i = 0;
	if (graph->room_list != 0)
		room = graph->room_list;
	while (i < graph->vert_count)
	{
		hmap_del(graph->vertices, room->room_name);
		if (room->next_room == 0)
			break ;
		room = room->next_room;
		++i;
	}
	while (i < graph->edge_count)
	{
		//TODO delete edges
		++i;
	}
	ft_bzero(graph, sizeof(t_graph));
}
