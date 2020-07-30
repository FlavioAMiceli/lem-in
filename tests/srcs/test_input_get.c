/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_input_get.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/04 15:09:27 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/30 13:12:45 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "lem_in.h"
#include "libft.h"

////////////////////////////////////////////////////////////////////////////////
//	INVALID		INVALID		INVALID		INVALID		INVALID		INVALID		  //
////////////////////////////////////////////////////////////////////////////////

Test(input_read, invalid_too_many_spaces_4)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_too_many_spaces_4";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_too_many_spaces_3)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_too_many_spaces_3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_too_many_spaces_2)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_too_many_spaces_2";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_too_many_spaces_1)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_too_many_spaces_1";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_empty)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_empty";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_empty_line_1)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_empty_line_1";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_empty_line_2)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_empty_line_2";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_incorrect_order_1)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_incorrect_order_1";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_incorrect_order_2)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_incorrect_order_2";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_incorrect_order_3)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_incorrect_order_3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_incorrect_order_4)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_incorrect_order_4";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_link_missing_room_1)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_link_missing_room_1";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_link_missing_room_2)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_link_missing_room_2";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_link_missing_room_3)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_link_missing_room_3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_link_multiple_minus_1)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_link_multiple_minus_1";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_link_multiple_minus_2)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_link_multiple_minus_2";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_link_multiple_minus_3)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_link_multiple_minus_3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_missing_ant_count)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_missing_ant_count";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_missing_end_mark)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_missing_end_mark";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_missing_start_mark)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_missing_start_mark";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_room_double_end)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_room_double_end";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_room_double_start)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_room_double_start";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_room_start_with_L_1)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_start_with_L_1";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_start_with_L_2)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_start_with_L_2";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_start_with_L_3)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_start_with_L_3";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_start_with_L_4)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_start_with_L_4";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

Test(input_read, invalid_start_with_L_5)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_start_with_L_5";

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), ERROR, "reading map %s doesn't return error", map);
	input_del(&input);
}

////////////////////////////////////////////////////////////////////////////////
//	VALID	VALID	VALID	VALID	VALID	VALID	VALID	VALID	VALID	  //
////////////////////////////////////////////////////////////////////////////////

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


Test(input_read, valid_big_1)
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
	fd = open("tests/maps/valid_big_1", O_RDONLY);
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

Test(input_read, valid_super_11)
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
	fd = open("tests/maps/valid_super_11", O_RDONLY);
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
	fd = open("tests/maps/valid_start_eq_end", O_RDONLY);
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
