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
#include <stdlib.h>

// static void print_path(t_list *path)
// {
// 	t_list	*curr;
//
// 	// remove this function
// 	ft_putendl("Printing path:");
// 	curr = path;
// 	while (curr)
// 	{
// 		ft_putstr(((t_vert *)curr->content)->name);
// 		ft_putchar(' ');
// 		curr = curr->next;
// 	}
// 	ft_putchar('\n');
// }

static int no_back_flow(t_edge *edge, t_list *path)
{
	if (!path->next)
		return (TRUE);
	else if (edge->head != ((t_list *)path->next)->content)
		return (TRUE);
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

static t_list	*a_star_expand(t_list **queue, t_vert *sink)
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
		// ft_putstr("expanding next edge with head: "); //remove
		// ft_putstr(((t_vert *)edge->head)->name); //remove
		// ft_putchar('\n'); //remove
		if (is_reachable(edge, path->content) && no_back_flow(edge, path))
		{
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
			// print_path(new_path); //remove
			insert_into_queue(queue, new_path);
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
		// // ft_putendl("Enter a_star_expand"); //remove
		// ft_putstr("Current vert: "); //remove
		// ft_putstr(((t_vert *)((t_list *)((t_list *)queue->content)->content)->content)->name); //remove
		// ft_putchar('\n'); //remove
		// ft_putstr("Score: "); //remove
		// ft_putnbr(queue->SCORE); //remove
		// ft_putchar('\n'); //remove
		rev_path = a_star_expand(&queue, sink);
		if (rev_path)
		{
			// ft_putendl("rev_path found"); //remove
			// ft_putendl("Check if stuff was freed."); //remove
			a_star_clear_queue(&queue);
			return (ft_lstrev(&rev_path));
		}
	}
	// ft_putendl("No path found"); //remove
	// ft_putendl("Check if stuff was freed."); //remove
	return (NULL);
}
