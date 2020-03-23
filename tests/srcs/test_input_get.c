/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_get.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 15:09:27 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/23 15:47:42 by moana         ########   odam.nl         */
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
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/01", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(read_input(&input), 1, "reading normal map doesn't return 1");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
}