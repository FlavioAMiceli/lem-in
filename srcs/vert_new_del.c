/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vert_new_del.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:46:04 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/27 17:48:26 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

t_vert	*vert_new(char **room_info)
{
	t_vert		*vert;

	vert = (t_vert*)malloc(sizeof(t_vert));
	if (vert == 0 || room_info == 0 || *room_info == 0 ||
		room_info[1] == 0 || ft_isint(room_info[1]) == 0 ||
		room_info[2] == 0 || ft_isint(room_info[2]) == 0 ||
		room_info[3] != 0)
		return (NULL);
	ft_bzero(vert, sizeof(t_vert));
	vert->name = ft_strdup(room_info[0]);
	vert->x_coord = ft_atoi(room_info[1]);
	vert->y_coord = ft_atoi(room_info[2]);
	vert->distance = -1;
	ft_strarrdel(&room_info);
	return (vert);
}

void	vert_del(t_vert **vert)
{
	if (vert == 0 || *vert == 0)
		return ;
	if ((*vert)->name != 0)
		ft_strdel(&((*vert)->name));
	if ((*vert)->conn_count > 0 && (*vert)->connections != NULL)
	{
		ft_bzero((*vert)->connections, sizeof(t_vert*) * (*vert)->conn_count);
		free((*vert)->connections);
	}
	ft_bzero(*vert, sizeof(t_vert));
	free(*vert);
	*vert = 0;
}
