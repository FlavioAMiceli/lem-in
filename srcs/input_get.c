/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_get.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 16:30:44 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/02 21:32:20 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** -------------------------------------------------------------------------- **
** adds the new input_line - link to the room list,
** counts the rooms,
** checks for duplicate room names,
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
	t_input_line	**walk;

	++(input->room_count);
	walk = &(input->rooms);
	while ((*walk) != 0)
	{
		if (ft_strequ((*walk)->room_name, name) == 1)
			return (0);
		walk = &((*walk)->next_room);
	}
	*walk = input_line;
	input_line->room_name = ft_strdup(name);
	if (input_line == 0)
		return (0);
	if (input->start != 0 && input->start[0] == '#')
	{
		ft_strdel(input->start);
		input->start = ft_strdup(name);
	}
	if (input->end != 0 && input->end[0] == '#')
	{
		ft_strdel(input->end);
		input->end = ft_strdup(name);
	}
	return (1);
}

/*
** -------------------------------------------------------------------------- **
** skips comments,
** marks if the following room is a start or end room
** checks if the input is for a room or a link
** returns error if there is input for a room after a link has been added
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
		strarrdel_and_return(0, &line);
	if (ft_strequ(line[0], "##start") && line[1] == 0 && input->start == 0)
	{
		if (ft_strdup(input->start) == 0)
			strarrdel_and_return(0, &line);
		strarrdel_and_return(1, &line);
	}
	if (ft_strequ(line[0], "##end") && line[1] == 0 && input->end == 0)
	{
		if (ft_strdup(input->end) == 0)
			strarrdel_and_return(0, &line);
		strarrdel_and_return(1, &line);
	}
	if (line[0][0] == '#' && !(ft_strequ(line[0], "##end") &&
		ft_strequ(line[0], "##start") && line[1] == 0))
		strarrdel_and_return(1, &line);
	if (line[0][0] != '#' && line[1] != 0 && ft_isint(line[1]) && line[2] != 0
		&& ft_isint(line[2]) && input->ant_no >= 0 && input->links == 0 &&
		add_room(input, input_line, line[0]) == 1)
		strarrdel_and_return(1, &line);
	if (line[0][0] != '#' && line[1] == 0 && ft_strchr(line[0], '-') != 0 &&
		input->rooms != 0 && add_link(input, input_line) == 1)
		strarrdel_and_return(1, &line);
	strarrdel_and_return(0, &line);
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

	ret = get_next_line(&line);
	if (ret == 0)
		return (0);
	while (ret != 0)
	{
		if (ret == -1)
			return (strdel_and_return(-1, &line));
		if (ft_isint(&line) &&
			input->ant_no == -1 && input->rooms == 0 && input->links == 0)
			input->ant_no = ft_atoi(line);
		else
		{
			input_line = add_input_line(input, line);
			if (input_line == 0 ||
			create_input_list(input, ft_strsplit(line, ' '), input_line) == 0)
				return (strdel_and_return(-1, &line));
		}
		ft_strdel(&line);
		ret = get_next_line(&line);
	}
	return (strdel_and_return(1, &line));
}

