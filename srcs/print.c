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

static void	free_ant(t_ant **ant)
{
	if (ant == NULL || *ant == NULL)
		return ;
	ft_strdel(&((*ant)->name));
	ft_bzero(*ant, sizeof(t_ant));
	free(*ant);
	*ant = NULL;
}

static void	move_ants(t_print_info *print)
{
	
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
			new_ant->name = ft_atoi(print->ants_send);
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
			ft_printf("L%s-%s", ant->name, ant->current_vert);
			if (ant->next != NULL)
				write(1, " ", 1);
			ant = ant->next;
		}
		write(1, "\n", 1);
		move_ants(&print);
	}
}
