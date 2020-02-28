/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:09:39 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/28 17:30:42 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		exit_function(t_room ***graph, t_input_info *input)
{
	free_graph(graph);
	free_input(input);
	return (0);
}

int		main(void)
{
	t_room			**graph;
	t_input_info	input;

	graph = 0;
	ft_bzero(&input, sizeof(input));
	if (read_input(&input) == 0)
		return (exit_function(&graph, &input));
	return (0);
}
