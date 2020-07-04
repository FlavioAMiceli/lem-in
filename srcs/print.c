/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/15 16:05:50 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/04 18:46:57 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	release_ants(t_path **paths, t_print *p_info, unsigned int remaining)
{
	int		idx;

	idx = 0;
	while (paths[idx] != NULL)
	{
		if (paths[idx]->threshold > remaining)
			return ;
		
		++idx;
	}
}

void    print_result(t_graph *graph)
{
	t_print     p_info;

	ft_bzero(&p_info, sizeof(t_print));
	update_thresholds(graph->paths, graph->path_count);
	while (p_info.ant_send < graph->ant_total || p_info.moving_ants != NULL)
	{
		if (p_info.ant_send < graph->ant_total)
			release_ants(graph, &p_info, graph->ant_total = p_info.ant_send);
		print_step(&p_info);
	}
}
