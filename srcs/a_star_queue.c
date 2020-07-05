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

static void	free_equal_score_paths(t_list *eq_s_p)
{
	t_list	*current;

	while (eq_s_p)
	{
		free_path((t_list **)(&(eq_s_p->content)));
		current = eq_s_p->next;
		// ft_memdel((void **)&eq_s_p);
		eq_s_p = current;
	}
}

void		free_path(t_list **path)
{
	t_list	*current;
	t_list	*next;

	current = *path;
	while (current)
	{
		next = current->next;
		ft_memdel((void **)&current);
		current = next;
	}
	path = NULL;
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**	Return:
*/

void		a_star_clear_queue(t_list **queue)
{
	t_list	*curr;
	t_list	*equal_score_paths;

	curr = *queue;
	while (curr)
	{
		equal_score_paths = curr->content;
		free_equal_score_paths(equal_score_paths);
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
	t_list	*equal_score;
	t_list	*path;
	t_list	*tmp;

	current = *queue;
	equal_score = current->content;
	path = equal_score->content;
	if (equal_score->next)
	{
		tmp = equal_score;
		equal_score = equal_score->next;
		ft_memdel((void **)&tmp);
	}
	else
	{
		if (current->next)
			(*queue) = current->next;
		else
			(*queue) = NULL;
		ft_memdel((void **)&equal_score);
		ft_memdel((void **)&current);
	}
	return (path);
}
