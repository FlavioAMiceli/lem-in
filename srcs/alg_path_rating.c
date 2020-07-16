/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   alg_path_rating.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/16 16:28:54 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/16 16:28:54 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int		path_rating(t_path **paths, unsigned int path_count, \
		unsigned int ant_total)
{
	while (path_count > 0)
	{
		if (paths[path_count - 1]->threshold > ant_total)
			return (ERROR);
		--path_count;
	}
	return (SUCCESS);
}
