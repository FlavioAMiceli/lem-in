/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_get.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/02 16:30:44 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/02 18:35:49 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

int			create_input_list(t_input_info *input, char **line)
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
	if (line[1] == 0 && add_link(input, ft_strsplit(line[0], '-')) == 1)
		strarrdel_and_return(1, &line);
	if (line[0][0] != '#' && line[1] != 0 && ft_isint(line[1]) &&
		line[2] != 0 && ft_isint(line[2]) && add_room(input, line) == 1)
		strarrdel_and_return(1, &line);
	strarrdel_and_return(0, &line);
}

/*
** -------------------------------------------------------------------------- **
** reads the input from stdin to save it in input list
**
** params
**
** return
**	0			in case of error
**	1			when everything went fine
*/

int			read_input(t_input_info *input)
{
	int		ret;
	char	*line;

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
		if (add_input_line(input, line) == 0 ||
			create_input_list(input, ft_strsplit(line, ' ')) == 0)
			return (strdel_and_return(-1, &line));
		ft_strdel(&line);
		ret = get_next_line(&line);
	}
	return (strdel_and_return(1, &line));
}

