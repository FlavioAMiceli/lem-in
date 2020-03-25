/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_get.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 16:30:44 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/25 18:07:37 by moana         ########   odam.nl         */
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
**	OK
**	ERROR
*/

static int	add_link(t_input_info *input, t_input_line *input_line)
{
	if (input->rooms == NULL || input->ant_no == -1)
		return (ERROR);
	++(input->link_count);
	input_line->next_link = input->links;
	input->links = input_line;
	return (OK);
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
**	OK
**	ERROR
*/

static int	add_room(t_input_info *input, t_input_line *input_line, char *name)
{
	if (input_line == NULL || input->links != NULL || input->ant_no == -1)
		return (ERROR);
	++(input->room_count);
	input_line->next_room = input->rooms;
	input->rooms = input_line;
	if (input->start != NULL &&
		ft_strequ(input->start->line, "##start") == 1)
		input->start = input_line;
	if (input->end != NULL &&
		ft_strequ(input->end->line, "##end") == 1)
		input->end = input_line;
	input_line->room_name = ft_strdup(name);
	if (input_line == NULL)
		return (ERROR);
	return (OK);
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
**	OK
**	ERROR
*/

static int	create_input_list(t_input_info *input, char **line,
			t_input_line *input_line)
{
	if (line == NULL || *line == NULL || line[0][0] == 'L')
		return (strarrdel_and_return(ERROR, &line));
	else if (ft_strequ(line[0], "##start") && line[1] == NULL &&
		input->start == NULL)
	{
		input->start = input_line;
		return (strarrdel_and_return(OK, &line));
	}
	else if (ft_strequ(line[0], "##end") && line[1] == 0 && input->end == 0)
	{
		input->end = input_line;
		return (strarrdel_and_return(OK, &line));
	}
	else if (line[0][0] == '#' && !(ft_strequ(line[0], "##end") &&
		ft_strequ(line[0], "##start") && line[1] == NULL))
		return (strarrdel_and_return(OK, &line));
	else if (line[0][0] != '#' && line[1] != NULL && ft_isint(line[1]) &&
		line[2] != NULL && ft_isint(line[2]) &&
		add_room(input, input_line, line[0]) == OK)
		return (strarrdel_and_return(OK, &line));
	else if (line[0][0] != '#' && ft_strchr(line[0], '-') != NULL
		&& line[1] == NULL && add_link(input, input_line) == 1)
		return (strarrdel_and_return(OK, &line));
	return (strarrdel_and_return(ERROR, &line));
}

/*
** -------------------------------------------------------------------------- **
** reads the input from stdin to save it in input list
** saves the number of ants if no input for rooms or link has been added
**
** params
**
** return
**	OK
**	ERROR
*/

int			read_input(t_input_info *input)
{
	int				ret;
	char			*line;
	t_input_line	*input_line;

	ret = get_next_line(0, &line);
	if (ret == 0)
		return (ERROR);
	while (ret != 0)
	{
		if (ret == -1)
			return (ERROR);
		input_line = add_input_line(input, line);
		if (ft_isint(line) && input->ant_no == -1 && input->rooms == NULL
			&& input->links == NULL)
			input->ant_no = ft_atoi(line);
		else
		{
			if (input_line == 0 || line[0] == 'L' ||
			create_input_list(input, ft_strsplit(line, ' '), input_line) ==
			ERROR)
				return (ERROR);
		}
		ret = get_next_line(0, &line);
	}
	return (input->ant_no >= 0 && input->start != NULL && input->end != NULL
		&& input->start->room_name != NULL && input->end->room_name != NULL);
}
