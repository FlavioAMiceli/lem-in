/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   apply_aug_path.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/04 12:53:00 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/07/04 14:24:58 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Params: edge, to find rooms that have modified flow
**	Return:
*/

void	update_visited_status(t_list *path)
{
	int		visited;
	t_edge	*edge;

	while (path)
	{
		edge = ((t_vert *)path->content)->connections;
		visited = FALSE;
		while (edge)
		{
			if (edge->flow != 0)
			{
				visited = TRUE;
				break ;
			}
			edge = edge->next_conn;
		}
		((t_vert *)path->content)->visited = visited;
		path = path->next;
	}
}

/*
**	Params:	path, list containing vertices used
**	Return:
*/

void	update_flow(t_list *path)
{
	t_edge	*edge;

	while (path)
	{
		if (!ft_strequ(((t_vert *)path->content)->name, "snk"))
		{
			edge = ((t_vert *)path->content)->connections;
			while (path->next != NULL && edge->head != path->next->content)
				edge = edge->next_conn;
			edge->flow += 1;
			edge = edge->invert;
			edge->flow -= 1;
		}
		path = path->next;
	}
}

/*
**	Params:	path, list containing vertices used
**	Return:
*/

void	revert_flow(t_list *path)
{
	t_edge	*edge;

	while (path)
	{
		if (!ft_strequ(((t_vert *)path->content)->name, "src"))
		{
			edge = ((t_vert *)path->content)->connections;
			while (edge->head != path->next->content)
				edge = edge->next_conn;
			edge->flow -= 1;
			edge = edge->invert;
			edge->flow += 1;
		}
		path = path->next;
	}
}

/*
**	Params: snk, current vertex to update
**			hop, number of hops to reach current vertex
**	Return:
*/

void	update_hops(t_vert *snk, int hop)
{
	t_edge	*edge;

	snk->hops = hop;
	edge = snk->connections;
	while (edge)
	{
		if (edge->flow == -1)
			update_hops(edge->head, hop + 1);
		edge = edge->next_conn;
	}
}
