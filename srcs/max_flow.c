/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hmap_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/25 18:13:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/25 18:14:00 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		bfs_clear_queue(t_list *queue)
{
	while (queue)
	{
		ft_lstdel(&(queue->content), ft_strdel);
		queue = queue->next;
	}
}

static t_list	*copy_path(t_list *src)
{
	t_list	*cpy;
	t_list	*current;
	t_list	*cpy_end;

	cpy = ft_lstnew(src->content, src->content_size);
	cpy_end = cpy;
	current = src->next;
	while (current)
	{
		cpy_end->next = ft_lstnew(current->content->name,
			ft_strlen(current->content->name));
		cpy_end = cpy_end->next;
	}
	return (cpy)
}

static int		is_reachable(
	t_vert *vert, char *next_room, t_hmap *rooms, t_hmap *used)
{
	if (hmap_get(rooms, next_room)->visited == FALSE
		&& hmap_get(used, next_room) == NULL)
		return (TRUE);
	return (FALSE);
}

static t_list	*bfs_expand(
	t_list *rev_path, t_list *end_queue, t_hmap *used, t_vert *sink, t_hmap *rooms)
{
	t_list	*new_path;
	t_list	*path_current;
	t_room	*current;
	char	**neighbours;

	neighbours = rev_path->content->neighbours;
	while (neighbours)
	{
		// copy path, add each neighbour to front, append to end_queue
		if (is_reachable(rev_path->content, *neighbours, rooms, used))
		{
			new_path = copy_path(rev_path);
			ft_lstadd(&new_path, ft_lstnew(*neighbours), ft_strlen(*neighbours));
			(*neighbours)++;
			// append to end_queue
			end_queue->next = ft_lstnew(&new_path, sizeof(t_list *));
		}
		// free old path
		// test if sink reached -> free other paths and return path
	}
	return (NULL);
}

static t_list	*bfs(t_vert *source, t_vert *sink, t_hmap *rooms)
{
	t_list	*queue;
	t_list	*end_queue;
	t_list	*rev_path;
	t_hmap	*used;

	used = hmap_new((((rooms->n) / 3) * 2), free);
	queue = (t_list*)ft_memalloc(sizeof(t_list));
	end_queue = queue;
	queue->content = source;
	while (queue)
	{
		rev_path = ft_dequeue(queue);
		rev_path = bfs_expand(rev_path, end_queue, used, sink, rooms);
		if (rev_path)
		{
			bfs_clear_queue(queue);
			return (ft_lstrev(rev_path));
		}
	}
	return (NULL);
}

/*
**	Params: edge, to find rooms that have modified flow
**			e, hmap that stores flow
**			v, hmap containing room information
**	Return:
*/
static void		update_visited_status(t_list *edge, t_hmap *e, t_hmap *v)
{
	t_vert	*room;
	char	*key;
	char	*separator;
	int		visited;

	visited = hmap_get(e, edge->content)->flow != 0 ? TRUE : FALSE;
	separator = ft_strchr(edge->content, ROOM_SEPARATOR);
	key = ft_memdup(edge->content, separator - edge->content);
	room = hmap_get(v, key);
	room->visited = visited;
	free(key);
	key = ft_strdup(separator + 1);
	room = hmap_get(v, key);
	room->visited = visited;
	free(key);
}

/*
**	Params:	path, list containing names of edges used
**			e, hmap that stores flow and names of edges in opposite direction
**			v, hmap that stores room information. Used to track visited rooms.
**	Return:
*/
static void		update_flow(t_list *path, t_hmap *e, t_hmap *v)
{
	t_edge	*edge;
	t_list	*tmp;

	// right now written for path of edges, probably will rewrite for vertices
	while (path)
	{
		edge = hmap_get(e, path->content);
		edge->flow += 1;
		edge = edge->invert;
		edge->flow -= 1;
		update_visited_status(path, e, v);
		tmp = path;
		path = path->next;
		ft_strdel(tmp->content);
		free(tmp);
	}
}

/*
**	Params:	e, adress of hmap storing edges
**				(every edge should have a counterpart in opposite direct)
**			v, adress of hmap storing vertices
**				(used to find every edge for that vertex)
**			s, t source and sink adresses
**	return:
**
*/
void			edmonds_karp(t_hmap *e, t_hmap *v, t_vert *s, t_vert, *t)
{
	t_list	*path;
	int		path_found;

	max_flow = 0;
	path_found = TRUE;
	while (path_found)
	{
		path_found = FALSE;
		path = bfs(s, t, v);
		if (path)
		{
			update_flow(path, e, v);
			path_found = TRUE;
		}
	}
}