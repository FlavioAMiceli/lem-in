/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_set.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/21 11:38:50 by moana         #+#    #+#                 */
/*   Updated: 2020/04/21 17:05:34 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void	paths_sort(t_path **paths, int path_count)
{
	int	i;
	int	j;

	i = path_count;
	while (i > 0)
	{
		if (paths[i - 1]->start->hops > paths[i]->start->hops)
		{
			ft_swap(paths[i - 1], paths[i]);
			j = i;
			while (paths[j + 1] != NULL &&
				paths[j]->start->hops > paths[j + 1]->start->hops)
			{
				ft_swap(paths[j], paths[j + 1]);
				++j;
			}
		}
		--i;
	}
}

int		path_new(t_graph *graph, t_vert *new_start)
{
	graph->path_count += 1;
	if (new_start == NULL)
		return (ERROR);
	graph->paths[graph->path_count] = (t_path*)ft_memalloc(sizeof(t_path));
	if (graph->paths[graph->path_count] == NULL)
		return (ERROR);
	graph->paths[graph->path_count]->start = new_start;
	paths_sort(graph->paths, graph->path_count);
	graph->paths[0]->threshold = 0;
	return (OK);
}