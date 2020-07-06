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

static t_list	*free_node(t_list **node)
{
	t_list	*next;

	if (node == NULL || *node == NULL)
		return (NULL);
	next = (*node)->next;
	ft_memdel((void **)node);
	*node = next;
	return (next);
}

void			free_path(t_list **path)
{
	t_list	*node;

	if (path == NULL || *path == NULL)
		return ;
	node = *path;
	while (node)
		node = free_node(&node);
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**	Return:
*/

void			a_star_clear_queue(t_list **queue)
{
	t_list	*curr;
	t_list	*paths;
	t_list	*node;

	curr = *queue;
	while (curr)
	{
		paths = curr->content;
		while (paths)
		{
			node = paths->content;
			while (node)
				node = free_node(&node);
			paths = free_node(&paths);
		}
		curr = free_node(&curr);
	}
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**	Return: path found at top node of top queue.
*/

t_list			*a_star_dequeue(t_list **queue)
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
