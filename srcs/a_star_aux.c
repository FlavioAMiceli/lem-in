/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_star_aux.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 10:52:15 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/04/10 10:52:49 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Params:	rooms, hmap that contains all rooms in the graph.
**	Return:
*/

void	rooms_used_to_false(t_vert *rooms)
{
	while (rooms)
	{
		rooms->used = FALSE;
		rooms = rooms->next_vert;
	}
}

/*
**	Params:	path, list of vertices.
**	Return: Fitness of latest node for finding the shortest path in a graph.
*/

int		evaluate(t_list *path)
{
	int	prev_score;
	int	prev_dist;
	int	curr_dist;

	prev_score = 0;
	prev_dist = 0;
	if (path->next)
	{
		prev_score = path->next->SCORE;
		prev_dist = ((t_vert *)(path->next->content))->distance;
	}
	curr_dist = ((t_vert *)path->content)->distance;
	return (curr_dist + prev_score - prev_dist + 1);
}
