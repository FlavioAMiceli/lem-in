/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_get.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 16:30:44 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/07 16:24:46 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

/*
** -------------------------------------------------------------------------- **
** checks if both rooms for the link are in fact room names
**
** params
**
** return
**	0			in case of error
**	1			when everything went fine
*/

static int	add_link(t_input_info *input, t_input_line *input_line)
{
	if (input->rooms == 0)
		return (0);
	input_line->next_link = input->links;
	input->links = input_line;
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** adds the new input_line - link to the room list in the input struct,
** counts the rooms,
** saves the start and end room
**
** params
**
** return
**	0			in case of error
**	1			when everything went fine
*/


static int	add_room(t_input_info *input, t_input_line *input_line, char *name)
{
	++(input->room_count);
	if (input_line == 0)
		return (0);
	input_line->next_room = input->rooms;
	input->rooms = input_line;
	if (input->start != NULL && input->start != 0 && input_line->room_name == 0)
		input->start = input_line;
	if (input->end != NULL && input->end != 0 && input_line->room_name == 0)
		input->end = input_line;
	input_line->room_name = ft_strdup(name);
	if (input_line == 0)
		return (0);
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** - appends every input line to the input struct
** - marks if the following room is a start or end room
** - checks if the input is for a room or a link calls the appropriate function
**   to add room or link
** - returns error if there is input for a room after a link has been added
**
** params
**
** return
**	0			in case of error
**	1			when everything went fine
*/

static int	create_input_list(t_input_info *input, char **line,
			t_input_line *input_line)
{
	if (line == 0 || *line == 0 || line[0][0] == 'L')
		return (strarrdel_and_return(0, &line));
	else if (ft_strequ(line[0], "##start") && line[1] == 0 && input->start == 0)
	{
		input->start = input_line;
		if (input->start == 0)
			return (strarrdel_and_return(0, &line));
		return (strarrdel_and_return(1, &line));
	}
	else if (ft_strequ(line[0], "##end") && line[1] == 0 && input->end == 0)
	{
		input->end = input_line;
		if (input->end == 0)
			return (strarrdel_and_return(0, &line));
		return (strarrdel_and_return(1, &line));
	}
	else if (line[0][0] == '#' && !(ft_strequ(line[0], "##end") &&
		ft_strequ(line[0], "##start") && line[1] == 0))
		return (strarrdel_and_return(1, &line));
	else if (line[0][0] != '#' && line[1] != 0 && ft_isint(line[1]) && line[2] != 0
		&& ft_isint(line[2]) && input->ant_no >= 0 && input->links == 0 &&
		add_room(input, input_line, line[0]) == 1)
		return (strarrdel_and_return(1, &line));
	else if (line[0][0] != '#' && line[1] == 0 && ft_strchr(line[0], '-') != 0 &&
		input->rooms != 0 && add_link(input, input_line) == 1)
		return (strarrdel_and_return(1, &line));
	return (strarrdel_and_return(0, &line));
}

/*
** -------------------------------------------------------------------------- **
** reads the input from stdin to save it in input list
** saves the number of ants if no input for rooms or link has been added
**
** params
**
** return
**	0			in case of error
**	1			when everything went fine
*/

int			read_input(t_input_info *input)
{
	int				ret;
	char			*line;
	t_input_line	*input_line;

	ret = get_next_line(0, &line);
	if (ret == 0)
		return (0);
	while (ret != 0)
	{
		if (ret == -1)
			return (0);
		input_line = add_input_line(input, line);
		if (ft_isint(line) &&
			input->ant_no == -1 && input->rooms == 0 && input->links == 0)
			input->ant_no = ft_atoi(line);
		else
		{
			if (input_line == 0 ||
			create_input_list(input, ft_strsplit(line, ' '), input_line) == 0)
				return (0);
		}
		ret = get_next_line(0, &line);
	}
	return (1 && input->ant_no >= 0);
}
