/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/05 16:46:37 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/05 18:53:39 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

static void	free_ant(t_ant **ant)
{
	if (ant == NULL || *ant == NULL)
		return ;
	ft_strdel(&((*ant)->name));
	ft_bzero(*ant, sizeof(t_ant));
	free(*ant);
	*ant = NULL;
}

static void	remove_ants(t_print_info *print)
{
	t_ant	*current;
	t_ant	*arrived;
	t_ant	*next_ant;

	while (print->first_ant != NULL && print->first_ant->current_vert == NULL)
	{
		arrived = print->first_ant;
		print->first_ant = print->first_ant->next;
		++(print->ants_arrived);
		free_ant(&arrived);
	}
	current = print->first_ant;
	while (current != NULL && current->next != NULL)
	{
		next_ant = current->next;
		while (next_ant->current_vert == NULL)
		{
			arrived = next_ant;
			next_ant = next_ant->next;
			++(print->ants_arrived);
			free_ant(&arrived);
		}
		current = next_ant;
	}
	print->last_ant = current;
}

static void	move_ants(t_print_info *print)
{
	t_ant	*current;
	t_edge	*next_edge;

	current = print->first_ant;
	while (current != NULL)
	{
		next_edge = current->current_vert->connections;
		while (next_edge != NULL)
		{
			if (next_edge->flow == 1)
				break ;
			next_edge = next_edge->next_conn;
		}
		current->current_vert = next_edge ? next_edge->head : NULL;
		current = current->next;
	}
}

static void	release_ants(t_path **paths, unsigned int path_count, \
			t_print_info *print)
{
	unsigned int	idx;
	t_ant			*new_ant;

	idx = 0;
	while (idx < path_count)
	{
		if (print->ants_total > print->ants_send \
			&& print->ants_total - print->ants_send >= paths[idx]->threshold)
		{
			new_ant = (t_ant*)ft_memalloc(sizeof(t_ant));
			if (new_ant == NULL)
				return ;
			++(print->ants_send);
			new_ant->name = ft_itoa(print->ants_send);
			new_ant->current_vert = paths[idx]->start;
			print->first_ant = print->first_ant ? print->first_ant : new_ant;
			if (print->last_ant != NULL)
				print->last_ant->next = new_ant;
			print->last_ant = new_ant;
		}
		++idx;
	}
}

void	print_result(t_graph *graph)
{
	t_print_info	print;
	t_ant			*ant;

	ft_bzero(&print, sizeof(t_print_info));
	print.ants_total = graph->ant_count;
	while (print.ants_arrived < print.ants_total)
	{
		if (print.ants_send < print.ants_total)
			release_ants(graph->paths, graph->path_count, &print);
		ant = print.first_ant;
		while (ant != NULL)
		{
			ft_printf("L%s-%s", ant->name, ant->current_vert->name);
			if (ant->next != NULL)
				ft_putchar(' ');
			ant = ant->next;
		}
		ft_putchar('\n');
		move_ants(&print);
		remove_ants(&print);
	}
}
