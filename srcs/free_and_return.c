/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_return.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 16:34:08 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/02 18:09:30 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int	strdel_and_return(int ret, char **str)
{
	ft_strdel(str);
	return (ret);
}

int	free_graph_input_and_return(int ret, t_room ***graph, t_input_info *input)
{
	free_graph(graph);
	free_input(input);
	return (ret);
}

int	strarrdel_and_return(int ret, char ***strarr)
{
	ft_strarrdel(strarr);
	return (ret);
}
