/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max_flow.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 18:13:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/25 18:14:00 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Params: edge, to find rooms that have modified flow
**			e, hmap that stores flow
**	Return:
*/
static void		update_visited_status(t_list *edge, t_hmap *e)
{
	int		visited;

	visited = hmap_get(e, edge->content)->flow != 0 ? TRUE : FALSE;
	edge->content->head->visited = visited;
	edge->content->tail->visited = visited;
}

/*
**	Params:	path, list containing names of edges used
**			e, hmap that stores flow and names of edges in opposite direction
**			v, hmap that stores room information. Used to track visited rooms.
**	Return:
*/
static void		update_flow(t_list *path, t_hmap *e, t_hmap *v)
{
	t_edge	*edge;
	t_list	*tmp;

	// right now written for path of edges, probably will rewrite for vertices
	while (path)
	{
		edge = hmap_get(e, path->content);
		edge->flow += 1;
		edge = edge->invert;
		edge->flow -= 1;
		update_visited_status(path, e, v);
		tmp = path;
		path = path->next;
		ft_strdel(tmp->content);
		free(tmp);
	}
}

/*
**	Params:	e, adress of hmap storing edges
**				(every edge should have a counterpart in opposite direct)
**			v, adress of hmap storing vertices
**				(used to find every edge for that vertex)
**			s, t source and sink adresses
**	return:
**
*/
void			edmonds_karp(t_hmap *e, t_hmap *v, t_vert *s, t_vert, *t)
{
	t_list	*path;
	int		path_found;

	max_flow = 0;
	path_found = TRUE;
	while (path_found)
	{
		path_found = FALSE;
		path = bfs(s, t, v);
		if (path)
		{
			update_flow(path, e, v);
			path_found = TRUE;
		}
	}
}