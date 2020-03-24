/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   graph_create_free.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:46:04 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/24 15:45:45 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

t_room		*create_room(char **room_info)
{
	t_room		*room;

	room = (t_room*)malloc(sizeof(t_room));
	if (room == 0 || room_info == 0 || *room_info == 0 ||
		room_info[0][0] == 'L' || room_info[0][0] == '#' ||
		room_info[1] == 0 || ft_isint(room_info[1]) == 0 ||
		room_info[2] == 0 || ft_isint(room_info[2]) == 0 ||
		room_info[3] != 0)
		return (NULL);
	room->name = ft_strdup(room_info[0]);
	room->x_coord = ft_atoi(room_info[1]);
	room->y_coord = ft_atoi(room_info[2]);
	room->distance = -1;
	room->link_count = 0;
	room->links = 0;
	ft_strarrdel(&room_info);
	return (room);
}

static void	free_room(t_room **room)
{
	if (room == 0 || *room == 0)
		return ;
	if ((*room)->name != 0)
		ft_strdel(&((*room)->name));
	if ((*room)->links != 0)
	{
		ft_bzero((*room)->links, (*room)->link_count);
		free((*room)->links);
	}
	ft_bzero(*room, sizeof(t_room));
	free(*room);
	*room = 0;
}

void		free_graph(t_graph *graph)
{
	int		i;

	i = 0;
	while (i < graph->room_count)
	{
		free_room(&((graph->rooms)[i]));
		++i;
	}
	ft_bzero(graph, sizeof(t_graph));
}
