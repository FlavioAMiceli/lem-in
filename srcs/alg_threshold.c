/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg_threshold.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/20 17:44:40 by moana         #+#    #+#                 */
/*   Updated: 2020/04/28 17:14:34 by mmarcell      ########   odam.nl         */
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
**		path[idx]
**	- case 2:
**		placeholder = 'distance to sink of potential new path number idx'
**		the resulting threshold marks the min number of ants for which (if
**		exceeded) we want to run Edmonds Karps algorithm on the vertix of the
**		potential new path
**
** params
**	t_path **paths	array of pointers for paths
**	int idx			index for the path to calculate threshold for
**	int placeholder	distance of new path or hops of path[idx]
** return
**	int				the threshold for path[idx]
*/

int		threshold(t_path **paths, int idx, int placeholder)
{
	int	i;
	int	threshold;

	i = 0;
	threshold = 0;
	while (i < idx)
	{
		threshold += ft_absolute(placeholder - paths[i]->start->hops);
		++i;
	}
	threshold += idx + 1;
	return (threshold);
}