/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_star_queue.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                  +#+                       */
/*   Created: 2020/05/05 06:21:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/05/05 06:21:47 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void add_to_front_of_sub_queue(t_list *curr, t_list *path)
{
    ft_lstadd(&(curr->content), ft_lstnew(&(path), sizeof(t_list *)));
    curr->SCORE = path->SCORE;
}

static void new_sub_queue(t_list *curr, t_list *path)
{
    t_list	*temp;

    temp = curr->next;
    curr->next = ft_lstnew(path, sizeof(t_list *));
    curr->next->SCORE = path->score;
    curr->next->next = temp;
}

/*
**	Params:	queue, ordered list of queues of reverse paths to expand.
**				first level nodes are sorted nodes of queues with equal scores.
**			path, list to be inserted in the proper second order queue.
**	Return:
*/

void		insert_into_queue(t_list **queue, t_list *path)
{
	t_list	*curr;
	t_list	*temp;

	curr = *queue;
	if (curr == NULL)
	{
		curr = ft_lstnew(path, sizeof(t_list *));
		curr->SCORE = path->SCORE;
	}
	while (curr && curr->SCORE < path->SCORE)
	{
		temp = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		temp->next = ft_lstnew(path, sizeof(t_list *));
		temp->next->SCORE = path->SCORE;
	}
	else if (curr->SCORE == path->SCORE)
        add_to_front_of_sub_queue(curr, path);
	else
        new_sub_queue(curr, path);
}
