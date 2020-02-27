/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_room.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:46:04 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/27 14:20:12 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"
#include <stdlib.h>

t_room		*create_room(char **room_info)
{
	t_room		*room;

	room = (t_room*)malloc(sizeof(t_room));
	if (room == 0 || room_info == 0 || *room_info == 0 ||
		room_info[0][0] == 'L' || room_info[0][0] == '#' ||
		room_info[1] == 0 || ft_is_int(room_info[1]) == 0 ||
		room_info[2] == 0 || ft_is_int(room_info[2]) == 0 ||
		room_info[3] != 0)
		return (0);
	room->name = ft_strdup(room_info[0]);
	room->x_coord = ft_atoi(room_info[1]);
	room->y_coord = ft_atoi(room_info[2]);
	room->distance = -1;
	room->link_count = 0;
	room->links = 0;
	ft_strarrdel(&room_info);
	return (room);
}
