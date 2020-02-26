/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_create_room.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:48:16 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/26 16:48:36 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "lem-in.h"
#include "libft.h"

Test(create_room, valid_pos)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("donaudampfschifffahrtsgesellschaft 21 42", ' ');
	room = create_room(room_info);
	cr_expect_eq(room->x_coord, 21, "incorrect x_coord for room, it is %d and it should be %d", room->x_coord, 21);
	cr_expect_eq(room->y_coord, 42, "incorrect y_coord for room, it is %d and it should be %d", room->y_coord, 42);
	cr_expect_eq(room->name, 42, "incorrect name for room, it is %s and it should be %s", room->name, "donaudampfschifffahrtsgesellschaft");
	cr_expect_eq(room->distance, -1, "distance not initialized to -1");
	cr_expect_eq(room->link_count, -1, "link_count not initialized to -1");
	cr_expect_eq(room->links, 0, "*links not initialized to 0");
}

Test(create_room, valid_neg)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("0 -21 -42", ' ');
	room = create_room(room_info);
	cr_expect_eq(room->x_coord, 21, "incorrect x_coord for room, it is %d and it should be %d", room->x_coord, -21);
	cr_expect_eq(room->y_coord, 42, "incorrect y_coord for room, it is %d and it should be %d", room->y_coord, -42);
	cr_expect_eq(room->name, 42, "incorrect name for room, it is %s and it should be %s", room->name, "0");
	cr_expect_eq(room->distance, -1, "distance not initialized to -1");
	cr_expect_eq(room->link_count, -1, "link_count not initialized to -1");
	cr_expect_eq(room->links, 0, "*links not initialized to 0");
}

Test(create_room, valid_mix)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("xyz 21 -42", ' ');
	room = create_room(room_info);
	cr_expect_eq(room->x_coord, 21, "incorrect x_coord for room, it is %d and it should be %d", room->x_coord, 21);
	cr_expect_eq(room->y_coord, 42, "incorrect y_coord for room, it is %d and it should be %d", room->y_coord, -42);
	cr_expect_eq(room->name, 42, "incorrect name for room, it is %s and it should be %s", room->name, "xyz");
	cr_expect_eq(room->distance, -1, "distance not initialized to -1");
	cr_expect_eq(room->link_count, -1, "link_count not initialized to -1");
	cr_expect_eq(room->links, 0, "*links not initialized to 0");
}

Test(create_room, valid_multiple_spaces)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("ladida   21  42", ' ');
	room = create_room(room_info);
	cr_expect_eq(room->x_coord, 21, "incorrect x_coord for room, it is %d and it should be %d", room->x_coord, 21);
	cr_expect_eq(room->y_coord, 42, "incorrect y_coord for room, it is %d and it should be %d", room->y_coord, 42);
	cr_expect_eq(room->name, 42, "incorrect name for room, it is %s and it should be %s", room->name, "ladida");
	cr_expect_eq(room->distance, -1, "distance not initialized to -1");
	cr_expect_eq(room->link_count, -1, "link_count not initialized to -1");
	cr_expect_eq(room->links, 0, "*links not initialized to 0");
}

Test(create_room, valid_int_max)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("ladida 2147483647 2147483647", ' ');
	room = create_room(room_info);
	cr_expect_eq(room->x_coord, 2147483647, "incorrect x_coord for room, it is %d and it should be %d", room->x_coord, 2147483647);
	cr_expect_eq(room->y_coord, 2147483647, "incorrect y_coord for room, it is %d and it should be %d", room->y_coord, 2147483647);
	cr_expect_eq(room->name, 42, "incorrect name for room, it is %s and it should be %s", room->name, "ladida");
	cr_expect_eq(room->distance, -1, "distance not initialized to -1");
	cr_expect_eq(room->link_count, -1, "link_count not initialized to -1");
	cr_expect_eq(room->links, 0, "*links not initialized to 0");
}

Test(create_room, valid_int_min)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("ladida -2147483648 42", ' ');
	room = create_room(room_info);
	cr_expect_eq(room->x_coord, -2147483648, "incorrect x_coord for room, it is %d and it should be %d", room->x_coord, -2147483648);
	cr_expect_eq(room->y_coord, 42, "incorrect y_coord for room, it is %d and it should be %d", room->y_coord, 42);
	cr_expect_eq(room->name, 42, "incorrect name for room, it is %s and it should be %s", room->name, "ladida");
	cr_expect_eq(room->distance, -1, "distance not initialized to -1");
	cr_expect_eq(room->link_count, -1, "link_count not initialized to -1");
	cr_expect_eq(room->links, 0, "*links not initialized to 0");
}

Test(create_room, valid_L_in_name)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("donau#gesellschaft 21 42", ' ');
	room = create_room(room_info);
	cr_expect_eq(room->x_coord, 21, "incorrect x_coord for room, it is %d and it should be %d", room->x_coord, 21);
	cr_expect_eq(room->y_coord, 42, "incorrect y_coord for room, it is %d and it should be %d", room->y_coord, 42);
	cr_expect_eq(room->name, 42, "incorrect name for room, it is %s and it should be %s", room->name, "donau#gesellschaft");
	cr_expect_eq(room->distance, -1, "distance not initialized to -1");
	cr_expect_eq(room->link_count, -1, "link_count not initialized to -1");
	cr_expect_eq(room->links, 0, "*links not initialized to 0");
}

Test(create_room, valid_hash_in_name)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("s#thing 21 42", ' ');
	room = create_room(room_info);
	cr_expect_eq(room->x_coord, 21, "incorrect x_coord for room, it is %d and it should be %d", room->x_coord, 21);
	cr_expect_eq(room->y_coord, 42, "incorrect y_coord for room, it is %d and it should be %d", room->y_coord, 42);
	cr_expect_eq(room->name, 42, "incorrect name for room, it is %s and it should be %s", room->name, "s#thing");
	cr_expect_eq(room->distance, -1, "distance not initialized to -1");
	cr_expect_eq(room->link_count, -1, "link_count not initialized to -1");
	cr_expect_eq(room->links, 0, "*links not initialized to 0");
}

Test(create_room, invalid_empty1)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "empty input is invalid");
}

Test(create_room, invalid_empty2)
{
	t_room	*room;
	char	**room_info;

	room_info = 0;
	room = create_room(room_info);
	cr_expect_eq(room, 0, "empty input is invalid");
}

Test(create_room, invalid_L_room)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("Ladida 3 0", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "room name starting with 'L' is invalid");
}

Test(create_room, invalid_hash_room)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("#ladida 15 15", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "room name starting with '#' is invalid");
}

Test(create_room, invalid_gt_int_max)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("something 2147483648 21474836", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "input coordinate > int_max is invalid");
}

Test(create_room, invalid_st_int_min)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("name -783 -2147483649", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "input coordinate < int_min is invalid");
}

Test(create_room, invalid_coord_non_num_char)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("ladida 24g 2", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "input with non numerical char as coordinate is invalid");
}

Test(create_room, invalid_coord_non_num_sign1)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("bla 1 2-2", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "input with nonsense sign is invalid");
}

Test(create_room, invalid_coord_non_num_sign2)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("hi 1- 2", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "input with nonsense sign is invalid");
}

Test(create_room, invalid_coord_non_num_sign3)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("some_great_name +-25 4", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "input with nonsense sign is invalid");
}

Test(create_room, invalid_1_arg)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("2", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "input too little information is invalid");
}

Test(create_room, invalid_2_arg)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("1 2", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "input too little information is invalid");
}

Test(create_room, invalid_4_arg)
{
	t_room	*room;
	char	**room_info;

	room_info = ft_strsplit("1 4 7 3", ' ');
	room = create_room(room_info);
	cr_expect_eq(room, 0, "input too much information is invalid");
}
