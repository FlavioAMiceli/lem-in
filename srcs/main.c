/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:09:39 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/02 17:00:29 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int		main(void)
{
	t_room			**graph;
	t_input_info	input;

	graph = 0;
	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	if (read_input(&input) == 0)
		return (free_graph_input_and_return(0, &graph, &input));
	return (0);
}
