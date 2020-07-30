/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_get.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 16:30:44 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/30 13:20:54 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

/*
** -------------------------------------------------------------------------- **
** - adds the given struct for the input line to the list of links
** - counts the links
**
** params
**	t_input_info *input			struct holding all information from input
**	t_input_line *input_line	list item for this input line
**
** return
**	SUCCESS
**	ERROR
*/

static int	add_link(t_input_info *input, t_input_line *input_line)
{
	if (input->rooms == NULL || input->ant_no == -1 \
		|| input_line->line[0] == '-' \
		|| input_line->line[ft_strlen(input_line->line) - 1] == '-')
		return (ERROR);
	++(input->link_count);
	input_line->next_link = input->links;
	input->links = input_line;
	return (SUCCESS);
}

/*
** -------------------------------------------------------------------------- **
** - adds the new input_line - link to the room list in the input struct and
**   saves its relevant information,
** - counts the rooms,
** - saves the start and end room
**
** params
**	t_input_info *input			struct holding all information from input
**	t_input_line *input_line	list item for this input line
**	char *name					the name of the room to be added
**
** return
**	SUCCESS
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
	return (SUCCESS);
}

/*
** -------------------------------------------------------------------------- **
** - sets primers for the next room to be the start or end of the graph
** - returns error if there are multiple start or end primers
**
** params
**	t_input_info *input			struct holding all information from input
**	char **line					the line of input split at ' '
**	t_input_line *input_line	list item for this input line
**
** return
**	SUCCESS
**	ERROR
*/

static int	add_start_end(t_input_info *input, char **line,
			t_input_line *input_line)
{
	if (ft_strequ(line[0], "##start") && line[1] == NULL \
		&& input->start == NULL)
	{
		input->start = input_line;
		return (strarrdel_and_return(SUCCESS, &line));
	}
	else if (ft_strequ(line[0], "##end") && line[1] == NULL \
		&& input->end == NULL)
	{
		input->end = input_line;
		return (strarrdel_and_return(SUCCESS, &line));
	}
	return (strarrdel_and_return(ERROR, &line));
}

/*
** -------------------------------------------------------------------------- **
** - appends every line of input to the input struct
** - marks if the following room is a start or end room
** - checks if the read line contains information for a room or a link calls
**   the appropriate function to add room or link
** - checks for the order of the input
**
** params
**	t_input_info *input			struct holding all information from input
**	char **line					the line of input split at ' '
**	t_input_line *input_line	list item for this input line
**
** return
**	SUCCESS
**	ERROR
*/

static int	create_input_list(t_input_info *input, char **line,
			t_input_line *input_line)
{
	if (line == NULL || *line == NULL || line[0][0] == 'L')
		return (strarrdel_and_return(ERROR, &line));
	else if (ft_strequ(line[0], "##start") || ft_strequ(line[0], "##end"))
		return (add_start_end(input, line, input_line));
	else if (line[0][0] == '#')// && line[0][1] != '#')
		return (strarrdel_and_return(SUCCESS, &line));
	else if (line[0][0] != '#' && line[1] && ft_isint(line[1]) && line[2]
		&& ft_isint(line[2]) && add_room(input, input_line, line[0]) == SUCCESS)
		return (strarrdel_and_return(SUCCESS, &line));
	else if (line[0][0] != '#' && ft_strchr(line[0], '-') != NULL
		&& ft_strchr(ft_strchr(line[0], '-') + 1, '-') == NULL
		&& line[1] == NULL && add_link(input, input_line) == 1)
		return (strarrdel_and_return(SUCCESS, &line));
	return (strarrdel_and_return(ERROR, &line));
}

/*
** -------------------------------------------------------------------------- **
** reads the input from stdin
** saves the number of ants
** counts the number of rooms and links
** catches the folllowing input errors:
**	- line doesn't have the required format
**	- wrong order (link before room, ant_no in between the rooms, etc.)
**	- room starts with 'L'
**
** params
**	t_input_info *input	struct holding all information from input
**
** return
**	SUCCESS
**	ERROR
*/

int			input_read(t_input_info *input)
{
	int				ret;
	char			*line;
	t_input_line	*input_line;

	ret = get_next_line(0, &line);
	if (ret == 0)
		return (ERROR);
	while (ret != 0)
	{
		if (ret == -1 || (line[0] != '#' && ft_strcheck_sep(line, ' ') == 0))
			return (ERROR);
		input_line = input_line_add(input, line);
		if (ft_isint(line) && ft_isdigit(line[0]) && input->ant_no == -1 \
			&& input->rooms == NULL && input->links == NULL)
			input->ant_no = ft_atoi(line);
		else
		{
			if (input_line == 0 || line[0] == 'L' || create_input_list(input,
				ft_strsplit(line, ' '), input_line) == ERROR)
				return (ERROR);
		}
		ret = get_next_line(0, &line);
	}
	return (input->ant_no >= 0 && input->start != NULL && input->end != NULL
		&& input->start->room_name != NULL && input->end->room_name != NULL);
}
