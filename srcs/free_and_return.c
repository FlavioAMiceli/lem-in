/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_and_return.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 16:34:08 by mmarcell       #+#    #+#                */
/*   Updated: 2020/04/01 18:53:31 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int	strdel_and_return(int ret, char **str)
{
	ft_strdel(str);
	return (ret);
}

int	free_graph_input_and_return(int ret, t_graph *graph, t_input_info *input)
{
	graph_del(graph);
	input_del(input);
	return (ret);
}

int	strarrdel_and_return(int ret, char ***strarr)
{
	ft_strarrdel(strarr);
	return (ret);
}

int	strarrdel_edgedel_and_return(int ret, char ***strarr, t_edge **edge)
{
	edge_del(edge);
	ft_strarrdel(strarr);
	return (ret);
}
