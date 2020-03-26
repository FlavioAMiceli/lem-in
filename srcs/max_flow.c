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
**	Params: vertex, name of
*/
static t_list	*bfs(t_room *source, t_room *sink, t_hmap *rooms)
{
	t_list	*queue;
	t_list	*path;

	qeueu = (t_list*)ft_memalloc(sizeof(t_list));
	qeueu->content = source;
	while (queue)
	{
		// expand all neighbours, look for shortest path to reach sink
		// return path, or NULL if sink is not reachable
	}
	return (path);
}

/*
**	Params:	path, list containing names of edges used
**			e, hmap that stores flow and namesof edges in opposite direction
**	Return:
*/
static void	update_flow(t_list *path, t_hmap *e)
{
	t_edge	*edge;
	t_list	*tmp;

	while (path)
	{
		edge = hmap_get(e, path->content);
		edge->flow += 1;
		edge = edge->opposite;
		edge->flow -= 1;
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
void	edmonds_karp(t_hmap *e, t_hmap *v, t_room *s, t_room, *t)
{
	t_list		*path;
	int			path_found;

	max_flow = 0;
	path_found = TRUE;
	while (path_found)
	{
		path_found = FALSE;
		path = bfs(s, t, v);
		if (path)
		{
			update_flow(path, e);
			path_found = TRUE;
		}
	}
}