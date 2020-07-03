/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_star.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 10:27:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/05/12 11:15:21 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
// #include <stdlib.h>

static int	no_back_flow(t_edge *edge, t_list *path)
{
	if (!path->next)
		return (TRUE);
	else if (edge->head != ((t_list *)path->next)->content)
		return (TRUE);
	return (FALSE);
}

static int	is_traversable(t_edge *edge, t_list *path, t_vert *source)
{
	t_edge *prev_edge;

	// ft_putchar('\n');
	// ft_putstr(edge->tail->name);
	// ft_putstr(" to ");
	// ft_putendl(edge->head->name);
	if (edge->flow <= 0 && edge->head->used == FALSE)
	{
		if (edge->flow < 0)
			return (TRUE);
		else if (edge->tail->visited == FALSE || edge->tail == source)
			return (TRUE);
		else if (path->next)
		{
			prev_edge = ((t_vert *)path->next->content)->connections;
			while (prev_edge->head != edge->tail)
				prev_edge = prev_edge->next_conn;
			if (prev_edge->flow < 0)
				return (TRUE);
		}
	}
	// ft_putstr("visited: ");
	// ft_putendl((edge->head->visited ? "TRUE" : "FALSE"));
	// ft_putstr("used: ");
	// ft_putendl((edge->head->used ? "TRUE" : "FALSE"));
	// ft_putstr("flow: ");
	// ft_putnbr(edge->flow);
	// ft_putchar('\n');
	return (FALSE);
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**			sink, exit vertex.
**			rooms, hmap that contains all rooms in the graph.
**	Return:	NULL if sink hasn't been reached yet,
**			otherwise shortest path in reverse.
*/

static t_list	*a_star_expand(t_list **queue, t_vert *sink, t_vert *source)
{
	t_list	*path;
	t_list	*new_path;
	t_edge	*edge;

	path = a_star_dequeue(queue);
	// ft_putendl("Exit a_star_dequeue"); //remove
	// print_path(path); //remove
	edge = ((t_vert *)path->content)->connections;
	while (edge)
	{
		// copy path, add each neighbour to front, insert into queue
		// ft_putstr("\ncurrent head: "); //remove
		// ft_putendl(((t_vert*)edge->head)->name); //remove
		// ft_putstr("is_traversable: "); //remove
		// ft_putendl((is_traversable(edge, path, source) ? "TRUE" : "FALSE")); //remove
		// ft_putstr("no_back_flow: "); //remove
		// ft_putendl((no_back_flow(edge, path) ? "TRUE" : "FALSE")); //remove
		if (no_back_flow(edge, path) && is_traversable(edge, path, source))
		{
			// ft_putstr("expanding next edge with head: "); //remove
			// ft_putstr(((t_vert *)edge->head)->name); //remove
			// ft_putchar('\n'); //remove
			edge->head->used = TRUE;
			new_path = (t_list *)ft_memalloc(sizeof(t_list));
			new_path->content = edge->head;
			new_path->next = copy_path(path);
			new_path->SCORE = evaluate(new_path);
			// test if sink reached
			if (edge->head == sink)
			{
				ft_memdel((void **)&path);
				return (new_path);
			}
			// insert into queue
			// ft_putchar('\n'); //remove
			// ft_putendl("inserting into queue:"); //remove
			// print_path(new_path); //remove
			// ft_putstr("Score: "); //remove
			// ft_putnbr(new_path->SCORE); //remove
			// ft_putchar('\n'); //remove
			insert_into_queue(queue, new_path);
			// ft_putendl("exit iiq"); //remove
		}
		edge = edge->next_conn;
	}
	ft_memdel((void **)&path);
	return (NULL);
}

/*
**	Params:	source, adress of starting room
**			sink, adress of last room
**			rooms, hmap that contains all vertices in graph
**	Return:	linked list of vertices
**			that make up the shortest path from source to sink
*/

t_list			*a_star(t_vert *source, t_vert *sink)
{
	t_list	*queue;
	t_list	*rev_path;

	init_queue(&queue, source);
	while (queue && queue->content != NULL)
	{
		// ft_putchar('\n'); //remove
		// ft_putendl("Enter a_star_expand"); //remove
		// ft_putstr("Current vert: "); //remove
		// ft_putstr(((t_vert *)((t_list *)((t_list *)queue->content)->content)->content)->name); //remove
		// ft_putchar('\n'); //remove
		// ft_putstr("Score: "); //remove
		// ft_putnbr(queue->SCORE); //remove
		// ft_putchar('\n'); //remove
		rev_path = a_star_expand(&queue, sink, source);
		if (rev_path)
		{
			// ft_putendl("rev_path found"); //remove
			// ft_putendl("Check if stuff was freed."); //remove
			a_star_clear_queue(&queue);
			return (ft_lstrev(&rev_path));
		}
	}
	ft_putendl("No path found"); //remove
	// ft_putendl("Check if stuff was freed."); //remove
	return (NULL);
}
