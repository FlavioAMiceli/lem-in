/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_create_free.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/28 17:38:18 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/03 18:23:01 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

t_input_line	*add_input_line(t_input_info *input, char *line)
{
	t_input_line	*new_line;

	new_line = (t_input_line*)malloc(sizeof(t_input_line));
	if (new_line == 0)
		return (0);
	ft_bzero(new_line, sizeof(t_input_info));
	new_line->line = ft_strdup(line);
	if (input->list == 0)
		input->list = new_line;
	if (input->last_line != 0)
		input->last_line->next_line = new_line;
	input->last_line = new_line;
	return (new_line);
}

static void		free_input_line(t_input_line **input_line)
{
	ft_strdel(&((*input_line)->line));
	ft_bzero((*input_line), sizeof(t_input_line));
	free(*input_line);
	*input_line = 0;
}

void			free_input(t_input_info *input)
{
	t_input_line	*tmp;
	t_input_line	*to_free;

	to_free = input->list;
	while (to_free != 0)
	{
		tmp = to_free->next_line;
		free_input_line(&to_free);
		to_free = tmp;
	}
	ft_bzero(input, sizeof(t_input_info));
}
