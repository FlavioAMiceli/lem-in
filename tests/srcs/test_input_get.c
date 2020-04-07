/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_get.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 15:09:27 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/04/07 12:08:16 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "lem_in.h"
#include "libft.h"

Test(input_read, valid_flow_one)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 1;
	int				room_count = 276;
	int				link_count = 277;
	char			*source = "Ucf5";
	char			*sink = "Tgr7";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/valid_flow_one", O_RDONLY);
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
	input_del(&input);
}

Test(input_read, valid_flow_ten)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 10;
	int				room_count = 738;
	int				link_count = 749;
	char			*source = "Fog1";
	char			*sink = "Gll7";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/valid_flow_ten", O_RDONLY);
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
	input_del(&input);
}

Test(input_read, valid_big)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 280;
	int				room_count = 2494;
	int				link_count = 3284;
	char			*source = "J_m1";
	char			*sink = "Zhw2";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/valid_big", O_RDONLY);
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
	input_del(&input);
}

Test(input_read, valid_big_2)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 312;
	int				room_count = 4628;
	int				link_count = 4700;
	char			*source = "Tag4";
	char			*sink = "Xxq8";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/valid_big_2", O_RDONLY);
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
	input_del(&input);
}

Test(input_read, valid_normal)
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
	fd = open("tests/maps/valid_normal", O_RDONLY);
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
	input_del(&input);
}

Test(input_read, valid_same_start_end)
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
	fd = open("tests/maps/valid_same_start_end", O_RDONLY);
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
	input_del(&input);
}

Test(input_read, valid_many_comments)
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
	fd = open("tests/maps/valid_many_comments", O_RDONLY);
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
	input_del(&input);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Test(input_read, invalid_missing_ant_count)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_missing_ant_count", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "ivalid map 11 with no ants doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	input_del(&input);
}

Test(input_read, invalid_empty_line_1)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_empty_line_1", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 12 with first line empty doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	input_del(&input);
}

Test(input_read, invalid_empty_line_2)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 3;
	int				link_count = 0;
	char			*source = "blu";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_empty_line_2", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 13 with empty line doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	input_del(&input);
}

Test(input_read, invalid_first_line_start_with_L_1)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_start_with_L_1", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 14 with first char 'L' doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	input_del(&input);
}

Test(input_read, invalid_start_with_L_1)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_start_with_L_1", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 15 with line starting with 'L' doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	input_del(&input);
}

Test(input_read, invalid_start_with_L_3)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 3;
	int				link_count = 0;
	char			*source = "blu";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_start_with_L_3", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 16 with line starting with 'L' doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	input_del(&input);
}

Test(input_read, invalid_start_with_L_4)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_start_with_L_4", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 17 with line starting with 'L' doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	input_del(&input);
}

Test(input_read, invalid_start_with_L_5)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_start_with_L_5", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 18 room input befor ant number doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	input_del(&input);
}

Test(input_read, invalid_incorrect_order_1)
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
	fd = open("tests/maps/invalid_incorrect_order_1", O_RDONLY);
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
	input_del(&input);
}

Test(input_read, invalid_incorrect_order_2)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_incorrect_order_2", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 20 with ant number between links doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	input_del(&input);
}

Test(input_read, invalid_missing_start_mark)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_missing_start_mark", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 21 without ##start mark doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
	input_del(&input);
}

Test(input_read, invalid_missing_end_mark)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*source = "blu";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_missing_end_mark", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 22 without ##end mark doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	input_del(&input);
}

Test(input_read, invalid_incorrect_order_3)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*sink = "3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_incorrect_order_3", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 23 without ##start room doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.end->room_name, sink, "sink read = %s, sink expected = %s", input.end->room_name, sink);
	input_del(&input);
}

Test(input_read, invalid_incorrect_order_4)
{
	int				fd;
	t_input_info	input;
	int				ant_no = 79;
	int				room_count = 6;
	int				link_count = 5;
	char			*source = "blu";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_incorrect_order_4", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "invalid map 24 without ##end room doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	cr_expect_str_eq(input.start->room_name, source, "source read = %s, source expected = %s", input.start->room_name, source);
	input_del(&input);
}

Test(input_read, invalid_empty)
{
	int				fd;
	t_input_info	input;
	int				ant_no = -1;
	int				room_count = 0;
	int				link_count = 0;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_empty", O_RDONLY);
	if (fd == -1)
   		ft_printf ("Error: %s\n", strerror(errno));
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), 0, "empty map doesn't return error");
	cr_expect_eq(input.ant_no, ant_no, "ants read = %d, ants expected = %d", input.ant_no, ant_no);
	cr_expect_eq(input.room_count, room_count, "rooms read = %d, rooms expected = %d", input.room_count, room_count);
	cr_expect_eq(input.link_count, link_count, "links read = %d, links expected = %d", input.link_count, link_count);
	input_del(&input);
}
