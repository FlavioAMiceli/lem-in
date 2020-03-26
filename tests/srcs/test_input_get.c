/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_get.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 15:09:27 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/26 18:20:33 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "lem_in.h"
#include "libft.h"

Test(input_read, valid_map_01)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*source = "blu";
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/01", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 1, "reading valid map 01 returns error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
}

Test(input_read, valid_map_02)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*source = "blu";
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/02", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 1, "reading valid map 02 returns error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
}

Test(input_read, valid_map_03)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*source = "3";
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/03", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 1, "reading valid map 03 returns error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
}

Test(input_read, invalid_map_04)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*source = "blu";
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/04", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 1, "reading valid map 04 doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(input_read, invalid_map_11)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/11", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "ivalid map 11 with no ants doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
}

Test(input_read, invalid_map_12)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/12", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 12 with first line empty doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
}

Test(input_read, invalid_map_13)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 3;
	int				link_count = 0;
	char			*source = "blu";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/13", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 13 with empty line doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
}

Test(input_read, invalid_map_14)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/14", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 14 with first char 'L' doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
}

Test(input_read, invalid_map_15)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 4;
	char			*source = "blu";
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/15", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 15 with line starting with 'L' doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
}

Test(input_read, invalid_map_16)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 3;
	int				link_count = 0;
	char			*source = "blu";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/16", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 16 with line starting with 'L' doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
}

Test(input_read, invalid_map_17)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/17", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 17 with line starting with 'L' doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
}

Test(input_read, invalid_map_18)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/18", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 18 room input befor ant number doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
}

Test(input_read, invalid_map_19)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 5;
	int				link_count = 1;
	char			*source = "blu";
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/19", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 19 with room input after link input doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
}

Test(input_read, invalid_map_20)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/20", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 20 with ant number between links doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
}

Test(input_read, invalid_map_21)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/21", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 21 without ##start mark doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
}

Test(input_read, invalid_map_22)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*source = "blu";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/22", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 22 without ##end mark doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
}

Test(input_read, invalid_map_23)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/23", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 23 without ##start room doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
}

Test(input_read, invalid_map_24)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*source = "blu";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/24", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 24 without ##end room doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
}
