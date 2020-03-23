/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_get.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 15:09:27 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/23 11:20:45 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "lem_in.h"
#include "libft.h"

Test(read_input, valid_01)
{
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	fd = open("maps/01", O_RDONLY);
  	if (fd == -1)
   	 ft_printf ("Error\n %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(read_input(&input), 1, "reading normal map doesn't return 1");
}