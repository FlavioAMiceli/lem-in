/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:55:01 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/27 18:51:16 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
** -------------------------------------------------------------------------- **
** reads the next line from stdin and skips the comment lines starting with '#'
**
** params
**	char **line	the pointer to read the next line into
** return
**	0			in case of error
**	-1			when there is a normal next line
**	1			when the following line indicates the start room of the graph
**	2			when the following line indicates the end room of the graph
*/

static int	gnl_skip_comments(char **line)
{
	int		ret;

	if (*line != 0)
		ft_strdel(line);
	ret = get_next_line(0, &line);
	if (ret == -1)
		return (0);
	if (ret == 0)
	{
		ft_strdel(&line);
		return (0);
	}
}

static int	get_ants(unsigned int *ant_no)
{
	char	*line;

	while (line[0] == '#')
	{
		ft_strdel(&line);

	}
	if (ft_is_int(line) == 0)
	{
		ft_strdel(&line);
		return (0);
	}
	*ant_no = ft_atoi(&line);

}

int			read_input(t_room ***graph, unsigned int *ant_no)
{
	if (get_ants(ant_no) == 0)
		return (0);
}
