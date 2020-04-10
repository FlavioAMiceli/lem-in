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
**	Return:
*/
static void		update_visited_status(t_edge *edge)
{
	int		visited;

	visited = edge->flow != 0 ? TRUE : FALSE;
	edge->content->head->visited = visited;
	edge->content->tail->visited = visited;
}

/*
**	Params:	path, list containing vertices used
**	Return:
*/
static void		update_flow(t_list *path)
{
	t_edge	*edge;
	t_list	*tmp;

	while (path)
	{
		edge = path->content->connections;
		while (edge->head != path->next->content)
			edge = edge->next_conn;
		edge->flow += 1;
		edge = edge->invert;
		edge->flow -= 1;
		update_visited_status(edge);
		tmp = path;
		path = path->next;
		free(tmp);
	}
}


/*
**	Params: s, current vertex to update
**			hop, number of hops to reach current vertex
**	Return:
*/
static void		update_hops(t_vert *s, int hop)
{
	t_edge	*edge;

	s->hops = hop;
	edge = s->connections;
	while (edge)
	{
		if (edge->flow == 1)
			update_hops(edge->head, hop + 1);
		edge = edge->next_conn;
	}
}

/*
**	Params:	v, adress of hmap storing vertices
**				(used to find every edge for that vertex)
**			s, t source and sink adresses
**	Return:
*/
void			edmonds_karp(t_hmap *v, t_vert *s, t_vert, *t, t_vert *rooms)
{
	t_list	*path;
	int		path_found;

	max_flow = 0;
	path_found = TRUE;
	while (path_found)
	{
		path_found = FALSE;
		rooms_used_to_false(rooms);
		path = a_star(s, t, v);
		if (path)
		{
			update_flow(path, v);
			update_hops(s, 0);
			path_found = TRUE;
		}
	}
}