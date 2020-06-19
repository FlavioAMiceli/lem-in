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

static t_list 	*new_equal_score_queue(t_list *path)
{
	t_list	*head;

	// ft_putendl("enter nesq"); //remove
	head = (t_list *)ft_memalloc(sizeof(t_list));
	head->SCORE = path->SCORE;
	head->next = NULL;
	head->content = (t_list *)ft_memalloc(sizeof(t_list));
	((t_list *)head->content)->content = path;
	((t_list *)head->content)->SCORE = path->SCORE;
	((t_list *)head->content)->next = NULL;
	return (head);
}

static void	add_to_front_of_sub_queue(t_list *curr, t_list *path)
{
	t_list	*head;

	// ft_putendl("enter atfosq"); //remove
	head = (t_list *)ft_memalloc(sizeof(t_list));
	head->SCORE = path->SCORE;
	head->next = curr->content;
	head->content = path;
	curr->content = head;
}

static void	insert_sub_queue(t_list *prev, t_list *path)
{
	t_list	*temp;

	// ft_putendl("enter isq"); //remove
	temp = prev->next;
	prev->next = new_equal_score_queue(path);
	prev->next->next = temp;
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

	curr = *queue;
	temp = curr;
	if (curr == NULL)
	{
		*queue = new_equal_score_queue(path);
		return ;
	}
	while (curr && curr->SCORE < path->SCORE)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
		temp->next = new_equal_score_queue(path);
	else if (curr->SCORE == path->SCORE)
		add_to_front_of_sub_queue(curr, path);
	else
		insert_sub_queue(temp, path);
}
