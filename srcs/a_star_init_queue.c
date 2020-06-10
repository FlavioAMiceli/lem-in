/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_star_queue.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/10 10:55:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/05/12 11:15:51 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**			source, vertex that represents first the first room in graph.
**	Return:
*/

static t_list	*init_queue_first_path(t_vert *source)
{
	t_list *head;

	head = (t_list*)ft_memalloc(sizeof(t_list));
	head->content = source;
	head->SCORE = source->distance;
	head->next = NULL;
	return (head);
}

static t_list	*init_queue_equal_value(t_vert *source)
{
	t_list *head;

	head = (t_list*)ft_memalloc(sizeof(t_list));
	head->content = init_queue_first_path(source);
	head->SCORE = source->distance;
	head->next = NULL;
	return (head);
}

void		init_queue(t_list **queue, t_vert *source)
{
	t_list *head;

	head = (t_list*)ft_memalloc(sizeof(t_list));
	head->content = init_queue_equal_value(source);
	head->SCORE = source->distance;
	head->next = NULL;
	(*queue) = head;
}
