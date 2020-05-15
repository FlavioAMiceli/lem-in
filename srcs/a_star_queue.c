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
#include <stdlib.h>

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**	Return:
*/

static void	bfs_clear_queue(t_list *queue)
{
	t_list	*current;

	while (queue)
	{
		free_path((t_list **)(&(queue->content)));
		current = queue->next;
		free(queue);
		queue = current;
	}
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**	Return:
*/

void		a_star_clear_queue(t_list *queue)
{
	t_list *paths;
	t_list *current;

	paths = queue->content;
	while (paths)
	{
		current = paths;
		paths = paths->next;
		bfs_clear_queue(current);
	}
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**			source, vertex that represents first the first room in graph.
**	Return:
*/

void		init_queue(t_list **queue, t_vert *source)
{
	t_list *head;

	(*queue) = (t_list*)ft_memalloc(sizeof(t_list));
	head = (*queue);
	head->content = (t_list*)ft_memalloc(sizeof(t_list));
	head->SCORE = source->distance;
	((t_list *)head->content)->content = source;
	((t_list *)head->content)->SCORE = source->distance;
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**	Return: path found at top node of top queue.
*/

// t_list		*a_star_dequeue(t_list **queue)
// {
// 	t_list	*equal_score_paths;
//
// 	equal_score_paths = ft_lstdequeue(queue);
// 	if (queue == NULL && equal_score_paths->next)
// 		queue = &(equal_score_paths->next);
// 	return (equal_score_paths->content);
// }

t_list		*a_star_dequeue(t_list **queue)
{
	t_list	*current;
	t_list	*path;

	// TODO: Check whether the correct return value is current, or current->content
	current = *queue;
	path = current->content;
	if (((t_list *)current->content)->next)
	{
		(*queue) = (((t_list *)current->content)->next);
		(*queue)->next = current->next;
	}
	else if (current->next)
		(*queue) = current->next;
	else
	{
		(*queue) = NULL;
		queue = NULL;
	}
	free(current); // Is this needed?
	return (path);
}
