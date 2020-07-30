/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:09:39 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/30 13:05:52 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static void	print_input(t_input_line *input_line)
{
	while (input_line)
	{
		ft_putendl(input_line->line);
		input_line = input_line->next_line;
	}
	ft_putchar('\n');
}

int			main(int argc, char **argv)
{
	t_graph			graph;
	t_input_info	input;

	if (argc > 2 || (argc == 2 && ft_strequ(argv[1], "-l") == FALSE))
		return (1);
	ft_bzero(&graph, sizeof(graph));
	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	if (input_read(&input) == ERROR || graph_new(&graph, &input) == ERROR)
	{
		ft_putendl_fd("ERROR", 2);
		return (free_graph_input_and_return(0, &graph, &input));
	}
	if (argc == 1)
		print_input(input.list);
	if (graph.source != graph.sink && graph.ant_count != 0)
	{
		distance_set(&graph, graph.sink, NULL);
		edmonds_karp(&graph);
		if (graph.path_count > 0)
			print_result(&graph);
		else
			ft_putendl("ERROR: There is no path.");
	}
	return (free_graph_input_and_return(0, &graph, &input));
}
