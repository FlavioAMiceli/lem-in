/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/27 15:55:01 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/28 17:26:16 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static int	strdel_and_return(int ret, char **str)
{
	ft_strdel(str);
	return (ret);
}

/*
** -------------------------------------------------------------------------- **
** reads the next line from stdin and checks if the input is valid
**
** params
**	char **line	the pointer to read the next line into
** return
**	-1			in case of a line starting with 'L' or a reading error
**	0			when nothing has been read
**	1			when a non empty line has been read
*/

static int	gnl_check_input(char **line)
{
	int		ret;

	ret = get_next_line(0, &line);
	if (ret == -1)
		return (-1);
	if (ret == 0)
		return (0);
	if ((*line)[0] == 'L')
		return (-1);
}

/*
** -------------------------------------------------------------------------- **
** reads the input from stdin
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

	ret = gnl_check_input(&line);
	if (ret == 0)
		return (0);
	while (ret != 0)
	{
		if (ret == -1)
			return (strdel_and_return(-1, &line));
		if (create_input_list(input) == 0)
			return (strdel_and_return(-1, *line));
		ft_strdel(&line);
		ret = gnl_check_input(&line);
	}
	return (strdel_and_return(1, &line));
}
