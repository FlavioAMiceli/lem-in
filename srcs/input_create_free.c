/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_create_free.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 17:38:18 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/02 20:55:22 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"
#include "libft.h"
#include <stdlib.h>

t_input_line	*add_input_line(t_input_info *input, char *line)
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
		walk = &((*walk)->next_line);
	*walk = new_line;
	return (new_line);
}
