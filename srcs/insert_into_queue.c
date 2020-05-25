/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_star_queue.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                  +#+                       */
/*   Created: 2020/05/05 06:21:30 by fmiceli        #+#    #+#                */
/*   Updated: 2020/05/05 06:21:47 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h> // REMOVE

static void	add_to_front_of_sub_queue(t_list *curr, t_list *path)
{
	ft_putendl("Enter atfosq"); //remove
	ft_lstadd((t_list **)&(curr->content), ft_lstnew(&(path), sizeof(t_list *)));
	curr->SCORE = path->SCORE;
}

static void	new_sub_queue(t_list *curr, t_list *path)
{
	t_list	*temp;

	temp = curr->next;
	curr->next = ft_lstnew(path, sizeof(t_list *));
	curr->next->SCORE = path->SCORE;
	curr->next->next = temp;
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**			path, list to be inserted in the proper second order queue.
**	Return:
*/

void	insert_into_queue(t_list **queue, t_list *path)
{
	t_list	*curr;
	t_list	*temp;

	// ft_putendl("Enter IIQ"); //remove
	curr = *queue;
	if (curr == NULL)
	{
		// ft_putendl("curr == NULL"); //remove
		curr = ft_lstnew(path, sizeof(t_list *));
		curr->SCORE = path->SCORE;
		printf("%p, ", queue);
		printf("%p, ", *queue);
		printf("%p, ", (*queue)->content);
		printf("%p, ", ((t_list *)(*queue)->content)->content);
		printf("%s\n", ((t_vert *)((t_list *)(*queue)->content)->content)->name);
		return ;
	}
	// ft_putendl("Pre while loop"); //remove
	while (curr && curr->SCORE < path->SCORE)
	{
		temp = curr;
		curr = curr->next;
	}
	// ft_putendl("Post while loop"); //remove
	if (curr == NULL)
	{
		// ft_putendl("Curr == NULL post loop"); //remove
		temp->next = ft_lstnew(path, sizeof(t_list *));
		temp->next->SCORE = path->SCORE;
	}
	else if (curr->SCORE == path->SCORE)
		add_to_front_of_sub_queue(curr, path);
	else
		new_sub_queue(curr, path);
}
