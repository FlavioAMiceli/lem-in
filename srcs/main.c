/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:09:39 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/04/08 12:24:22 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>			//REMOVE
#include <unistd.h>			//REMOVE
#include "lem_in.h"
#include "libft.h"

int		main(void)
{
	t_graph			graph;
	t_input_info	input;

	int fd = open("tests/maps/valid_normal", O_RDONLY);
	if (fd < 0)
	{
		ft_printf("map doesn't exist\n");
		return (0);
	}
	dup2(fd, 0);
	ft_bzero(&graph, sizeof(graph));
	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	if (input_read(&input) == ERROR ||
		graph_set(&graph, &input) == ERROR)
	{
		ft_dprintf(2, "Error\n");
		return (free_graph_input_and_return(0, &graph, &input));
	}
	ft_printf("map is valid\n");
	distance_set(&graph, graph.sink, NULL);
	return (free_graph_input_and_return(0, &graph, &input));
}
