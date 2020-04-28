/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:09:39 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/04/25 17:09:22 by mmarcell      ########   odam.nl         */
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

	int fd = open("tests/maps/valid_path_threshold", O_RDONLY);
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
		graph_new(&graph, &input) == ERROR)
	{
		ft_dprintf(2, "Error\n");
		return (free_graph_input_and_return(0, &graph, &input));
	}
	ft_printf("map is valid\n");
	distance_set(&graph, graph.sink, NULL);
	t_vert	*path_1 = hmap_get(graph.vertices, "B");
	t_vert	*path_2 = hmap_get(graph.vertices, "C");
	path_1->hops = 3;
	path_2->hops = 1;
	path_new(&graph, path_1);
	path_new(&graph, path_2);
	return (free_graph_input_and_return(0, &graph, &input));
}
