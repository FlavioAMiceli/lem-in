/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:09:39 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/04 12:34:09 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>			//REMOVE
#include <unistd.h>			//REMOVE
#include "lem_in.h"
#include "libft.h"

int		main(int argc, char **argv)
{
	t_graph			graph;
	t_input_info	input;
	int				fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_putendl("map doesn't exist");
		return (0);
	}
	dup2(fd, 0);
	ft_bzero(&graph, sizeof(graph));
	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	if (input_read(&input) == ERROR ||
		graph_new(&graph, &input) == ERROR)
	{
		ft_putendl_fd("Error", 2);
		return (free_graph_input_and_return(0, &graph, &input));
	}
	if (graph.source != graph.sink)
	{
		distance_set(&graph, graph.sink, NULL);
		sleep(2); //remove
		edmonds_karp(&graph);
		sleep(2); //remove
	}
	return (free_graph_input_and_return(0, &graph, &input));
}
