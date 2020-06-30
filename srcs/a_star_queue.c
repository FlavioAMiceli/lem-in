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
		ft_memdel((void **)&queue);
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
	t_list	*curr;
	t_list	*paths;

	curr = *queue;
	while (curr)
	{
		paths = curr->content;
		bfs_clear_queue(paths);
		curr = curr->next;
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
		ft_memdel((void **)&tmp);
	}
	else if (current->next)
	{
		(*queue) = current->next;
		ft_memdel((void **)&current->content);
		ft_memdel((void **)&current);
	}
	else
	{
		(*queue) = NULL;
		ft_memdel((void **)&current->content);
		ft_memdel((void **)&current);
	}
	return (path);
}
