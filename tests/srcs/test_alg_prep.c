/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_alg_prep.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/07 16:28:03 by moana         #+#    #+#                 */
/*   Updated: 2020/04/09 12:50:40 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>
#include <unistd.h>
#include "lem_in.h"
#include "libft.h"

Test(distance_set, valid_deadend_4)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	t_vert			*vert;
	char			*room_name;
	int				distance;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_deadend_4", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), OK, "couldn't read map, formatting error?\nlast line was: %s, room count = %d, link count = %d", input.last_line->line, input.room_count, input.link_count);
	cr_expect_eq(graph_set(&graph, &input), OK, "normal map returns error");
	distance_set(&graph, graph.sink, NULL);
	room_name = "snk";
	distance = 0;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "src";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "M";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "I";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "F";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "O";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "H";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "E";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "C";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	room_name = "B";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "K";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "G";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "D";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "A";
	distance = 4;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "N";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "Q";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "P";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	input_del(&input);
	graph_del(&graph);
}

Test(distance_set, valid_deadend_3)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	t_vert			*vert;
	char			*room_name;
	int				distance;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_deadend_3", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), OK, "couldn't read map, formatting error?\nlast line was: %s, room count = %d, link count = %d", input.last_line->line, input.room_count, input.link_count);
	cr_expect_eq(graph_set(&graph, &input), OK, "normal map returns error");
	distance_set(&graph, graph.sink, NULL);
	room_name = "snk";
	distance = 0;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "src";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "M";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "I";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "F";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "O";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "H";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "E";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "C";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	room_name = "B";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "K";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "G";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "D";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "A";
	distance = 4;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "N";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "Q";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "P";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	input_del(&input);
	graph_del(&graph);
}

Test(distance_set, valid_deadend_2)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	t_vert			*vert;
	char			*room_name;
	int				distance;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_deadend_2", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), OK, "couldn't read map, formatting error?\nlast line was: %s, room count = %d, link count = %d", input.last_line->line, input.room_count, input.link_count);
	cr_expect_eq(graph_set(&graph, &input), OK, "normal map returns error");
	distance_set(&graph, graph.sink, NULL);
	room_name = "snk";
	distance = 0;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "src";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "M";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "I";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "F";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "O";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "H";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "E";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "C";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	room_name = "B";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "K";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "G";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "D";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "A";
	distance = 4;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "N";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "Q";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "P";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	input_del(&input);
	graph_del(&graph);
}

Test(distance_set, valid_deadend_1)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	t_vert			*vert;
	char			*room_name;
	int				distance;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_deadend_1", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), OK, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), OK, "normal map returns error");
	distance_set(&graph, graph.sink, NULL);
	room_name = "3";
	distance = 0;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "devil";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "room";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "some_room";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "bla";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "dead_end";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "blu";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	input_del(&input);
	graph_del(&graph);
}

Test(distance_set, valid_normal_2)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	t_vert			*vert;
	char			*room_name;
	int				distance;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_normal_2", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), OK, "couldn't read map, formatting error?\nlast line was: %s, room count = %d, link count = %d", input.last_line->line, input.room_count, input.link_count);
	cr_expect_eq(graph_set(&graph, &input), OK, "normal map returns error");
	distance_set(&graph, graph.sink, NULL);
	room_name = "snk";
	distance = 0;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "src";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "M";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "I";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "F";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "O";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "H";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "E";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "C";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	room_name = "B";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "K";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "G";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "D";
	distance = 3;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "A";
	distance = 4;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	input_del(&input);
	graph_del(&graph);
}

Test(distance_set, valid_normal)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	t_vert			*vert;
	char			*room_name;
	int				distance;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_normal", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), OK, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), OK, "normal map returns error");
	distance_set(&graph, graph.sink, NULL);
	room_name = "3";
	distance = 0;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "devil";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "room";
	distance = 1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "some_room";
	distance = 2;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "bla";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	room_name = "blu";
	distance = -1;
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "couldn't find room \"%s\"", room_name);
	cr_expect_eq(vert->distance, distance, "distance for \"%s\" is incorrect. Expected = %d, calculated = %d", room_name, distance, vert->distance);
	input_del(&input);
	graph_del(&graph);
}
