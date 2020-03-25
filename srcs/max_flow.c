/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hmap_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 18:13:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/25 18:14:00 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Params:	graph, struct containing e and v;
				e, adress of hmap storing edges
**					(every edge should have a counterpart in opposite direct)
**				v, adress of hmap storing vertices
**					(used to find every edge for that vertex)
**				s, t source and sink adresses
**	return:
**
*/
void	edmonds_karp(t_graph *graph)
{
	t_list		*q;
	t_list		*path;
	int			path_found;

	max_flow = 0;
	path_found = TRUE;
	while (path_found)
	{
		q = (t_list*)ft_memalloc(sizeof(t_list));
		q->content = s;
		path_found = FALSE;
		while (q)
		{
			path = bfs(ft_lstdequeue(&q), graph);
			if (path)
			{
				update_flow(path, graph);
				path_found = TRUE;
			}
		}
	}
}