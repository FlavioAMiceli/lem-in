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

void		a_star_clear_queue(t_list **queue)
{
	t_list *paths;
	t_list *current;

	// moana added safety if-statement here for preventing segfault
	if (queue == NULL || *queue == NULL)
		return ;
	paths = (*queue)->content;
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
**	Return: path found at top node of top queue.
*/

t_list		*a_star_dequeue(t_list **queue)
{
	t_list	*current;
	t_list	*path;
	t_list	*tmp;

	current = *queue;
	path = ((t_list *)current->content)->content;
	if (((t_list *)current->content)->next)
	{
		tmp = current->content;
		current->content = ((t_list *)current->content)->next;
		free(tmp);
	}
	else if (current->next)
	{
		(*queue) = current->next;
		free(current->content);
		free(current);
	}
	else
	{
		(*queue) = NULL;
		free(current->content);
		free(current);
	}
	return (path);
}
