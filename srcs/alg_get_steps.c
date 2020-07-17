/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg_get_steps.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 16:28:54 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/16 16:28:54 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		get_steps(t_path **paths, unsigned int path_count, \
		unsigned int ant_total)
{
	unsigned int	steps;
	unsigned int	ants_arrived;
	unsigned int	idx;

	if (path_count == 0)
		return (-1);
	ants_arrived = 0;
	steps = 0;
	while (ants_arrived < ant_total)
	{
		idx = 0;
		++steps;
		while (idx < path_count \
			&& (unsigned int)paths[idx]->start->hops < steps)
		{
			++ants_arrived;
			++idx;
		}
	}
	return (steps);
}
