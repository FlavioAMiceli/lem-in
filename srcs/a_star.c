/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   a_star.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 10:27:30 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/04/07 10:29:10 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		init_queue(t_list **queue, t_vert *source)
{
	t_list *head;

	head = (t_list*)ft_memalloc(sizeof(t_list));
	head->content = (t_list*)ft_memalloc(sizeof(t_list));
	head->SCORE = source->distance;
	head->content->content = source;
	queue = &head;
}

static t_list	*a_star_dequeue(t_list **queue)
{
	t_list	*equal_score_paths;
	t_list	*path;

	equal_score_paths = ft_lstdequeue(queue);
	if (queue == NULL && equal_score_paths->next)
		queue = &(equal_score_paths->next);
	return (equal_score_paths->content);
}

static void		a_star_clear_queue(t_list *queue)
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

static void		bfs_clear_queue(t_list *queue)
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

t_list			*a_star(t_vert *source, t_vert *sink, t_hmap *rooms)
{
	t_list	*queue;
	t_list	*rev_path;

	init_queue(&queue, source);
	while (queue)
	{
		rev_path = a_star_dequeue(&queue);
		// write a_star_expand
		rev_path = a_star_expand(rev_path, sink, rooms);
		if (rev_path)
		{
			a_star_clear_queue(queue);
			return (ft_lstrev(rev_path));
		}
	}
	return (NULL);
}