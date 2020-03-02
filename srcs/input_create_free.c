/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   create_free_input.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 17:38:18 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/28 17:55:43 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"
#include <stdlib.h>

int		append_input_line(t_input_info *input, char *line)
{
	t_input_line	*new_line;
	t_input_line	**walk;

	new_line = (t_input_line*)malloc(sizeof(t_input_line));
	if (new_line == 0)
		return (0);
	ft_bzero(new_line, sizeof(t_input_info));
	new_line->line = ft_strdup(line);
	walk = &(input->list);
	while (*walk != 0)
		(*walk) = (*walk)->next_line;
	*walk = new_line;
	return (1);
}
