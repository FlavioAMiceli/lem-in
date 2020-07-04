/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg_threshold.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/20 17:44:40 by moana         #+#    #+#                 */
/*   Updated: 2020/07/04 18:19:44 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

/*
** -------------------------------------------------------------------------- **
** calculates the threshold for number of ants
** 	- case 1:
**		placeholder = paths[idx]->start->hops
**		the resulting threshold marks the min number of ants for which to use
**		paths[idx]
**	- case 2:
**		placeholder = 'distance to sink of potential new path number idx'
**		the resulting threshold marks the min number of ants for which (if
**		exceeded) we want to run Edmonds Karps algorithm on the vertix of the
**		potential new path
**
** params
**	t_path **paths				array of pointers for paths
**	unsigned int idx			index for the path to calculate threshold for
**	unsigned int placeholder	distance of new path or hops of paths[idx]
** return
**	unsigned int				the threshold for paths[idx]
*/

unsigned int	threshold(t_path **paths, unsigned int idx,
				unsigned int placeholder)
{
	unsigned int	i;
	unsigned int	threshold;
	unsigned int	count;

	i = 0;
	threshold = 0;
	count = 1;
	while (i < idx)
	{
		if (paths[i]->start->hops >= 0 && \
			placeholder >= (unsigned int)paths[i]->start->hops)
		{
			threshold += placeholder - paths[i]->start->hops;
			++count;
		}
		++i;
	}
	return (threshold + count);
}

void		set_thresholds(t_path **paths, unsigned int path_count)
{
	unsigned int	idx;

	idx = 0;
	while (idx < path_count)
	{
		paths[idx]->threshold = threshold(paths, idx, paths[idx]->start->hops);
		++idx;
	}
}
