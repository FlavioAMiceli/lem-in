/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_graph_set.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:48:16 by mmarcell       #+#    #+#                */
/*   Updated: 2020/04/01 18:01:07 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "lem_in.h"
#include "libft.h"

Test(graph_set, invalid_link_incorrect_room_name_3)
{
	t_graph         graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_link_incorrect_room_name_3", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "incorrect room name does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_link_incorrect_room_name_2)
{
	t_graph         graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_link_incorrect_room_name_2", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "incorrect room name does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_link_incorrect_room_name_1)
{
	t_graph         graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_link_incorrect_room_name_1", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "incorrect room name does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_link_multiple_minus_3)
{
	t_graph         graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_link_multiple_minus_3", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "too many '-' charackters does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_link_multiple_minus_2)
{
	t_graph         graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_link_multiple_minus_2", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "too many '-' charackters does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_link_multiple_minus_1)
{
	t_graph         graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_link_multiple_minus_1", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "too many '-' charackters does not return error");
	input_del(&input);
	graph_del(&graph);
}

//////////////////////////////////////////////////////////////////////////////////////////

// Test(vert_new, valid_pos)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("donaudampfschifffahrtsgesellschaft 21 42", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert->x_coord, 21, "incorrect x_coord for vert, it is %d and it should be %d", vert->x_coord, 21);
// 	cr_expect_eq(vert->y_coord, 42, "incorrect y_coord for vert, it is %d and it should be %d", vert->y_coord, 42);
// 	cr_expect_str_eq(vert->name, "donaudampfschifffahrtsgesellschaft", "incorrect name for vert, it is %s and it should be %s", vert->name, "donaudampfschifffahrtsgesellschaft");
// 	cr_expect_eq(vert->distance, -1, "distance not initialized to -1");
// 	cr_expect_eq(vert->conn_count, 0, "conn_count not initialized to 0");
// 	cr_expect_eq(vert->connections, 0, "*connections not initialized to 0");
// }

// Test(vert_new, valid_neg)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("0 -21 -42", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert->x_coord, -21, "incorrect x_coord for vert, it is %d and it should be %d", vert->x_coord, -21);
// 	cr_expect_eq(vert->y_coord, -42, "incorrect y_coord for vert, it is %d and it should be %d", vert->y_coord, -42);
// 	cr_expect_str_eq(vert->name, "0", "incorrect name for vert, it is %s and it should be %s", vert->name, "0");
// 	cr_expect_eq(vert->distance, -1, "distance not initialized to -1");
// 	cr_expect_eq(vert->conn_count, 0, "conn_count not initialized to 0");
// 	cr_expect_eq(vert->connections, 0, "*connections not initialized to 0");
// }

// Test(vert_new, valid_mix)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("xyz 21 -42", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert->x_coord, 21, "incorrect x_coord for vert, it is %d and it should be %d", vert->x_coord, 21);
// 	cr_expect_eq(vert->y_coord, -42, "incorrect y_coord for vert, it is %d and it should be %d", vert->y_coord, -42);
// 	cr_expect_str_eq(vert->name, "xyz", "incorrect name for vert, it is %s and it should be %s", vert->name, "xyz");
// 	cr_expect_eq(vert->distance, -1, "distance not initialized to -1");
// 	cr_expect_eq(vert->conn_count, 0, "conn_count not initialized to 0");
// 	cr_expect_eq(vert->connections, 0, "*connections not initialized to 0");
// }

// Test(vert_new, valid_multiple_spaces)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("ladida   21  42", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert->x_coord, 21, "incorrect x_coord for vert, it is %d and it should be %d", vert->x_coord, 21);
// 	cr_expect_eq(vert->y_coord, 42, "incorrect y_coord for vert, it is %d and it should be %d", vert->y_coord, 42);
// 	cr_expect_str_eq(vert->name, "ladida", "incorrect name for vert, it is %s and it should be %s", vert->name, "ladida");
// 	cr_expect_eq(vert->distance, -1, "distance not initialized to -1");
// 	cr_expect_eq(vert->conn_count, 0, "conn_count not initialized to 0");
// 	cr_expect_eq(vert->connections, 0, "*connections not initialized to 0");
// }

// Test(vert_new, valid_int_max)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("ladida 2147483647 2147483647", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert->x_coord, 2147483647, "incorrect x_coord for vert, it is %d and it should be %d", vert->x_coord, 2147483647);
// 	cr_expect_eq(vert->y_coord, 2147483647, "incorrect y_coord for vert, it is %d and it should be %d", vert->y_coord, 2147483647);
// 	cr_expect_str_eq(vert->name, "ladida", "incorrect name for vert, it is %s and it should be %s", vert->name, "ladida");
// 	cr_expect_eq(vert->distance, -1, "distance not initialized to -1");
// 	cr_expect_eq(vert->conn_count, 0, "conn_count not initialized to 0");
// 	cr_expect_eq(vert->connections, 0, "*connections not initialized to 0");
// }

// Test(vert_new, valid_int_min)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("ladida -2147483648 42", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert->x_coord, -2147483648, "incorrect x_coord for vert, it is %d and it should be %ld", vert->x_coord, -2147483648);
// 	cr_expect_eq(vert->y_coord, 42, "incorrect y_coord for vert, it is %d and it should be %d", vert->y_coord, 42);
// 	cr_expect_str_eq(vert->name, "ladida", "incorrect name for vert, it is %s and it should be %s", vert->name, "ladida");
// 	cr_expect_eq(vert->distance, -1, "distance not initialized to -1");
// 	cr_expect_eq(vert->conn_count, 0, "conn_count not initialized to 0");
// 	cr_expect_eq(vert->connections, 0, "*connections not initialized to 0");
// }

// Test(vert_new, valid_L_in_name)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("donauLgesellschaft 21 42", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert->x_coord, 21, "incorrect x_coord for vert, it is %d and it should be %d", vert->x_coord, 21);
// 	cr_expect_eq(vert->y_coord, 42, "incorrect y_coord for vert, it is %d and it should be %d", vert->y_coord, 42);
// 	cr_expect_str_eq(vert->name, "donauLgesellschaft", "incorrect name for vert, it is %s and it should be %s", vert->name, "donau#gesellschaft");
// 	cr_expect_eq(vert->distance, -1, "distance not initialized to -1");
// 	cr_expect_eq(vert->conn_count, 0, "conn_count not initialized to 0");
// 	cr_expect_eq(vert->connections, 0, "*connections not initialized to 0");
// }

// Test(vert_new, valid_hash_in_name)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("s#thing 21 42", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert->x_coord, 21, "incorrect x_coord for vert, it is %d and it should be %d", vert->x_coord, 21);
// 	cr_expect_eq(vert->y_coord, 42, "incorrect y_coord for vert, it is %d and it should be %d", vert->y_coord, 42);
// 	cr_expect_str_eq(vert->name, "s#thing", "incorrect name for vert, it is %s and it should be %s", vert->name, "s#thing");
// 	cr_expect_eq(vert->distance, -1, "distance not initialized to -1");
// 	cr_expect_eq(vert->conn_count, 0, "conn_count not initialized to 0");
// 	cr_expect_eq(vert->connections, 0, "*connections not initialized to 0");
// }

// Test(vert_new, invalid_empty1)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "empty input is invalid");
// }

// Test(vert_new, invalid_empty2)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = 0;
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "empty input is invalid");
// }

// Test(vert_new, invalid_gt_int_max)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("something 2147483648 21474836", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "input coordinate > int_max is invalid");
// }

// Test(vert_new, invalid_st_int_min)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("name -783 -2147483649", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "input coordinate < int_min is invalid");
// }

// Test(vert_new, invalid_coord_non_num_char)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("ladida 24g 2", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "input with non numerical char as coordinate is invalid");
// }

// Test(vert_new, invalid_coord_non_num_sign1)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("bla 1 2-2", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "input with nonsense sign is invalid");
// }

// Test(vert_new, invalid_coord_non_num_sign2)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("hi 1- 2", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "input with nonsense sign is invalid");
// }

// Test(vert_new, invalid_coord_non_num_sign3)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("some_great_name +-25 4", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "input with nonsense sign is invalid");
// }

// Test(vert_new, invalid_1_arg)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("2", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "input too little information is invalid");
// }

// Test(vert_new, invalid_2_arg)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("1 2", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "input too little information is invalid");
// }

// Test(vert_new, invalid_4_arg)
// {
// 	t_vert	*vert;
// 	char	**room_info;

// 	room_info = ft_strsplit("1 4 7 3", ' ');
// 	vert = vert_new(room_info);
// 	cr_expect_eq(vert, 0, "input too much information is invalid");
// }
