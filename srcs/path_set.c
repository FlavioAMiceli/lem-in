/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   path_set.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/21 11:38:50 by moana         #+#    #+#                 */
/*   Updated: 2020/04/30 17:31:46 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

/*
** -------------------------------------------------------------------------- **
** sorts the paths by the hop count of their start vertix
**
** params
**	t_path **paths	array of the paths
**	int idx			the index of most recently added path
**
** return
**	VOID
*/

static void	paths_sort(t_path **paths, int idx)
{
	int	i;
	int	j;

	i = idx;
	while (i > 0)
	{
		if (paths[i - 1]->start->hops > paths[i]->start->hops)
		{
			ft_swap_ptr((void**)&(paths[i - 1]), (void**)&(paths[i]));
			j = i;
			while (paths[j + 1] != NULL &&
				paths[j]->start->hops > paths[j + 1]->start->hops)
			{
				ft_swap_ptr((void**)&(paths[j]), (void**)&(paths[j + 1]));
				++j;
			}
		}
		--i;
	}
}

/*
** -------------------------------------------------------------------------- **
** - adds a new path to the paths array in the graph struct
** - after the new path is added the paths array will sorted by the hops of the
**   start vertices in ascending order
**   (path with least hops will be at graph->paths[0])
**
** params
**	t_graph *graph		struct holding all information about graph
**	t_vert *new_start	start vert of the new path
**
** return
**	SUCCESS
**	ERROR
*/

int			path_new(t_graph *graph, t_vert *new_start)
{
	if (new_start == NULL)
		return (ERROR);
	graph->paths[graph->path_count] = (t_path*)ft_memalloc(sizeof(t_path));
	if (graph->paths[graph->path_count] == NULL)
		return (ERROR);
	graph->paths[graph->path_count]->start = new_start;
	paths_sort(graph->paths, graph->path_count);
	graph->paths[0]->threshold = 0;
	graph->path_count += 1;
	return (SUCCESS);
}
