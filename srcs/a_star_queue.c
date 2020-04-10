/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_star_queue.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                  +#+                       */
/*   Created: 2020/04/10 10:55:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/04/10 10:55:47 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	bfs_clear_queue(t_list *queue)
{
	t_list	*current;

	while (queue)
	{
		free_path(&(queue->content));
		current = queue->next;
		free(queue);
		queue = current;
	}
}

void	a_star_clear_queue(t_list *queue)
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

void	init_queue(t_list **queue, t_vert *source)
{
	t_list *head;

	head = (t_list*)ft_memalloc(sizeof(t_list));
	head->content = (t_list*)ft_memalloc(sizeof(t_list));
	head->SCORE = source->distance;
	head->content->content = source;
	queue = &head;
}

t_list	*a_star_dequeue(t_list **queue)
{
	t_list	*equal_score_paths;
	t_list	*path;

	equal_score_paths = ft_lstdequeue(queue);
	if (queue == NULL && equal_score_paths->next)
		queue = &(equal_score_paths->next);
	return (equal_score_paths->content);
}

void	insert_into_queue(t_list **queue, t_list *path)
{
	t_list	*curr;
	t_list	*last;

	curr = *queue;
	if (curr == NULL)
	{
		curr = ft_lstnew(path, sizeof(t_list *));
		curr->SCORE = path->SCORE;
	}
	while (curr && curr->SCORE < path->SCORE)
	{
		last = curr;
		curr = curr->next;
	}
	if (curr == NULL)
	{
		last->next = ft_lstnew(path, sizeof(t_list *));
		last->next->SCORE = path->SCORE;
	}
	else if (curr->SCORE == path->SCORE)
	{
		ft_lstadd(&(curr->content), ft_lstnew(&(path), sizeof(t_list *)));
		curr->SCORE = path->SCORE;
	}
	else
	{
		//Insert new node after current, link to current->next
	}
}