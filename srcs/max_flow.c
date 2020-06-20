/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   max_flow.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 18:13:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/05/12 11:16:58 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

static void print_path_cpy(t_list *path)
{
	t_list	*curr;

	// remove this function
	ft_putendl("Printing augmented path:");
	curr = path;
	while (curr)
	{
		ft_putstr(((t_vert *)curr->content)->name);
		ft_putchar(' ');
		curr = curr->next;
	}
	ft_putchar('\n');
}

/*
**	Params: edge, to find rooms that have modified flow
**	Return:
*/

static void		update_visited_status(t_list *path)
{
	int		visited;
	t_edge	*edge;
	t_list	*tmp;

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
		// ft_putstr(((t_vert *)path->content)->name);
		// ft_putstr(" visited status changing from ");
		// ft_putstr(((t_vert *)path->content)->visited ? "TRUE" : "FALSE");
		// ft_putstr(" to ");
		// ft_putendl(visited ? "TRUE" : "FALSE");
		((t_vert *)path->content)->visited = visited;
		tmp = path;
		path = path->next;
		free(tmp);
	}
}

/*
**	Params:	path, list containing vertices used
**	Return:
*/

static void		update_flow(t_list *path)
{
	t_edge	*edge;

	while (path)
	{
		if (!ft_strequ(((t_vert *)path->content)->name, "snk"))
		{
			edge = ((t_vert *)path->content)->connections;
			while (edge->head != path->next->content)
				edge = edge->next_conn;
			ft_putstr(((t_vert *)edge->tail)->name); // remove
			ft_putstr(" to "); // remove
			ft_putstr(((t_vert *)edge->head)->name); // remove
			edge->flow += 1;
			ft_putstr(" flow: "); // remove
			ft_putnbr(edge->flow); // remove
			edge = edge->invert;
			edge->flow -= 1;
			ft_putstr(" invert flow: "); // remove
			ft_putnbr(edge->flow); // remove
			ft_putchar('\n'); // remove
		}
		path = path->next;
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
	// ft_putstr(s->name); // remove
	// ft_putstr(" hops: "); // remove
	// ft_putnbr(hop); // remove
	// ft_putchar('\n'); // remove
	while (edge)
	{
		if (edge->flow == 1)
			update_hops(edge->head, hop + 1);
		edge = edge->next_conn;
	}
}

/*
**	Params:	s, source vertex
**
**	Return: Unvisited vertex connected to source with lowest distance to sink
*/

static t_vert	*get_next_start(t_vert *s)
{
	t_vert	*next_start;
	t_edge	*edge;
	int		min_dist;

	edge = s->connections;
	min_dist = FT_INT_MAX;
	next_start = NULL;
	while (edge)
	{
		if (edge->head->visited == FALSE && edge->head->distance < min_dist)
		{
			next_start = edge->head;
			min_dist = edge->head->distance;
		}
		edge = edge->next_conn;
	}
	return (next_start);
}

/*
**	Params:	graph, struct containing all information about the graph
**
**	Return:
*/

void			edmonds_karp(t_graph *graph)
{
	t_list	*aug_path;
	t_vert	*new_start;
	int		stop; //remove

	stop = 3; //remove
	new_start = get_next_start(graph->source);
	while (keep_searching(graph, new_start))
	{
		rooms_used_to_false(graph->vert_list);
		// ft_putendl("Enter a_star"); // REMOVE
		aug_path = a_star(graph->source, graph->sink);
		// ft_putendl("Exit a_star"); // REMOVE
		if (aug_path)
		{
			print_path_cpy(aug_path);
			// ft_putendl("Updating_graph flow"); // REMOVE
			update_flow(aug_path);
			// ft_putendl("Updating_visited status"); // REMOVE
			update_visited_status(aug_path);
			// ft_putendl("Updating_graph hops\n\n"); // REMOVE
			update_hops(graph->source, 0);
		}
		if (stop == 0) // remove
			return ; // remove
		stop--; // remove
		// ft_putendl("get_next_start"); // REMOVE
		new_start = get_next_start(graph->source);
	}
}
