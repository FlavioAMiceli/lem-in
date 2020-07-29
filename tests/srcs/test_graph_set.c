/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_graph_set.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:48:16 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/28 21:15:02 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "lem_in.h"
#include "libft.h"

Test(graph_new, valid_flow_one)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	unsigned int	vert_count = 276;
	unsigned int	ant_count = 1;
	char			*source = "Ucf5";
	char			*sink = "Tgr7";
	t_vert			*vert;


	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_flow_one", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_assert_eq(graph_new(&graph, &input), SUCCESS, "normal map returns error");
	cr_expect_eq(graph.vert_count, vert_count, "rooms read = %d, rooms expected = %d", graph.vert_count, vert_count);
	cr_expect_eq(graph.ant_count, ant_count, "incorrect amount of ants. Expecter = %d, read = %d", ant_count, graph.ant_count);
	cr_expect_str_eq(graph.source->name, source, "source read = %s, source expected = %s", graph.source->name, source);
	cr_expect_str_eq(graph.sink->name, sink, "sink read = %s, sink expected = %s", graph.sink->name, sink);
	//
	// test room and links
	char	*room_name = "Ucf5";
	int		link_count = 3;
	char	*link1 = "Xbj0";
	char	*link2 = "D_p2";
	char	*link3 = "Dbe5";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link3), vert->connections->next_conn->next_conn->head, "third connection for %s expected: %s, found: %s", room_name, link3, vert->connections->next_conn->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "Ukq0";
	link_count = 5;
	link1 = "Zho6";
	link2 = "Nsp0";
	link3 = "Mgy7";
	char	*link4 = "Ggv0";
	char	*link5 = "P_x8";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link3), vert->connections->next_conn->next_conn->head, "third connection for %s expected: %s, found: %s", room_name, link3, vert->connections->next_conn->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link4), vert->connections->next_conn->next_conn->next_conn->head, "fourth connection for %s expected: %s, found: %s", room_name, link4, vert->connections->next_conn->next_conn->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link5), vert->connections->next_conn->next_conn->next_conn->next_conn->head, "fifth connection for %s expected: %s, found: %s", room_name, link5, vert->connections->next_conn->next_conn->next_conn->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->head->name);
	room_name = "Ozu2";
	link_count = 2;
	link1 = "Tr_3";
	link2 = "Jc_3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "S_j8";
	link_count = 2;
	link1 = "Axu1";
	link2 = "Qji0";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "Czq6";
	link_count = 1;
	link1 = "Nte9";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "Hsx0";
	link_count = 1;
	link1 = "Wpg6";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_new, valid_link_duplicate_2)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	unsigned int	vert_count = 6;
	unsigned int	ant_count = 79;
	char			*source = "blu";
	char			*sink = "3";
	t_vert			*vert;


	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_link_duplicate_2", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_assert_eq(graph_new(&graph, &input), SUCCESS, "normal map returns error");
	cr_expect_eq(graph.vert_count, vert_count, "rooms read = %d, rooms expected = %d", graph.vert_count, vert_count);
	cr_expect_eq(graph.ant_count, ant_count, "incorrect amount of ants. Expecter = %d, read = %d", ant_count, graph.ant_count);
	cr_expect_str_eq(graph.source->name, source, "source read = %s, source expected = %s", graph.source->name, source);
	cr_expect_str_eq(graph.sink->name, sink, "sink read = %s, sink expected = %s", graph.sink->name, sink);
	//
	// test room and links
	char	*room_name = "some_room";
	int		link_count = 3;
	char	*link1 = "bla";
	char	*link2 = "room";
	char	*link3 = "blu";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link3), vert->connections->next_conn->next_conn->head, "third connection for %s expected: %s, found: %s", room_name, link3, vert->connections->next_conn->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "room";
	link_count = 2;
	link1 = "some_room";
	link2 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_new, valid_link_duplicate_1)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	unsigned int	vert_count = 6;
	unsigned int	ant_count = 79;
	char			*source = "blu";
	char			*sink = "3";
	t_vert			*vert;


	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_link_duplicate_1", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_assert_eq(graph_new(&graph, &input), SUCCESS, "normal map returns error");
	cr_expect_eq(graph.vert_count, vert_count, "rooms read = %d, rooms expected = %d", graph.vert_count, vert_count);
	cr_expect_eq(graph.ant_count, ant_count, "incorrect amount of ants. Expecter = %d, read = %d", ant_count, graph.ant_count);
	cr_expect_str_eq(graph.source->name, source, "source read = %s, source expected = %s", graph.source->name, source);
	cr_expect_str_eq(graph.sink->name, sink, "sink read = %s, sink expected = %s", graph.sink->name, sink);
	//
	// test room and links
	char	*room_name = "some_room";
	int		link_count = 3;
	char	*link1 = "bla";
	char	*link2 = "room";
	char	*link3 = "blu";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link3), vert->connections->next_conn->next_conn->head, "third connection for %s expected: %s, found: %s", room_name, link3, vert->connections->next_conn->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "room";
	link_count = 2;
	link1 = "some_room";
	link2 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_new, valid_link_head_equal_tail)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	unsigned int	vert_count = 6;
	unsigned int	ant_count = 79;
	char			*source = "blu";
	char			*sink = "3";
	t_vert			*vert;


	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_link_head_equal_tail", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_assert_eq(graph_new(&graph, &input), SUCCESS, "normal map returns error");
	cr_expect_eq(graph.vert_count, vert_count, "rooms read = %d, rooms expected = %d", graph.vert_count, vert_count);
	cr_expect_eq(graph.ant_count, ant_count, "incorrect amount of ants. Expecter = %d, read = %d", ant_count, graph.ant_count);
	cr_expect_str_eq(graph.source->name, source, "source read = %s, source expected = %s", graph.source->name, source);
	cr_expect_str_eq(graph.sink->name, sink, "sink read = %s, sink expected = %s", graph.sink->name, sink);
	//
	// test room and links
	char	*room_name = "some_room";
	int		link_count = 3;
	char	*link1 = "bla";
	char	*link2 = "room";
	char	*link3 = "blu";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link3), vert->connections->next_conn->next_conn->head, "third connection for %s expected: %s, found: %s", room_name, link3, vert->connections->next_conn->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "room";
	link_count = 2;
	link1 = "some_room";
	link2 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_new, valid_same_start_end)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	unsigned int	vert_count = 6;
	unsigned int	ant_count = 79;
	char			*source = "3";
	char			*sink = "3";
	t_vert			*vert;


	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_start_eq_end", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_assert_eq(graph_new(&graph, &input), SUCCESS, "normal map returns error");
	cr_expect_eq(graph.vert_count, vert_count, "rooms read = %d, rooms expected = %d", graph.vert_count, vert_count);
	cr_expect_eq(graph.ant_count, ant_count, "incorrect amount of ants. Expecter = %d, read = %d", ant_count, graph.ant_count);
	cr_expect_str_eq(graph.source->name, source, "source read = %s, source expected = %s", graph.source->name, source);
	cr_expect_str_eq(graph.sink->name, sink, "sink read = %s, sink expected = %s", graph.sink->name, sink);
	//
	// test room and links
	char	*room_name = "some_room";
	int		link_count = 3;
	char	*link1 = "bla";
	char	*link2 = "room";
	char	*link3 = "blu";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link3), vert->connections->next_conn->next_conn->head, "third connection for %s expected: %s, found: %s", room_name, link3, vert->connections->next_conn->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "room";
	link_count = 2;
	link1 = "some_room";
	link2 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_new, valid_normal)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	unsigned int	vert_count = 6;
	unsigned int	ant_count = 79;
	char			*source = "blu";
	char			*sink = "3";
	t_vert			*vert;


	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_normal", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_assert_eq(graph_new(&graph, &input), SUCCESS, "normal map returns error");
	cr_expect_eq(graph.vert_count, vert_count, "rooms read = %d, rooms expected = %d", graph.vert_count, vert_count);
	cr_expect_eq(graph.ant_count, ant_count, "incorrect amount of ants. Expecter = %d, read = %d", ant_count, graph.ant_count);
	cr_expect_str_eq(graph.source->name, source, "source read = %s, source expected = %s", graph.source->name, source);
	cr_expect_str_eq(graph.sink->name, sink, "sink read = %s, sink expected = %s", graph.sink->name, sink);
	//
	// test room and links
	char	*room_name = "some_room";
	int		link_count = 3;
	char	*link1 = "bla";
	char	*link2 = "room";
	char	*link3 = "blu";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link3), vert->connections->next_conn->next_conn->head, "third connection for %s expected: %s, found: %s", room_name, link3, vert->connections->next_conn->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	room_name = "room";
	link_count = 2;
	link1 = "3";
	link2 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head->name);
	input_del(&input);
	graph_del(&graph);
}


////////////////////////////////////////////////////////////////////////////////
//	INVALID		INVALID		INVALID		INVALID		INVALID		INVALID		  //
////////////////////////////////////////////////////////////////////////////////

Test(input_read, invalid_room_duplicate_1)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_room_duplicate_1";
	t_graph			graph;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), SUCCESS, "reading map %s should return SUCCESS", map);
	cr_expect_eq(graph_new(&graph, &input), ERROR, "setting graph for map %s should return ERROR", map);
	input_del(&input);
}

Test(input_read, invalid_room_duplicate_2)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_room_duplicate_2";
	t_graph			graph;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), SUCCESS, "reading map %s should return SUCCESS", map);
	cr_expect_eq(graph_new(&graph, &input), ERROR, "setting graph for map %s should return ERROR", map);
	input_del(&input);
}

Test(input_read, invalid_room_duplicate_3)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_room_duplicate_3";
	t_graph			graph;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), SUCCESS, "reading map %s should return SUCCESS", map);
	cr_expect_eq(graph_new(&graph, &input), ERROR, "setting graph for map %s should return ERROR", map);
	input_del(&input);
}

Test(input_read, invalid_room_duplicate_4)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_room_duplicate_4";
	t_graph			graph;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), SUCCESS, "reading map %s should return SUCCESS", map);
	cr_expect_eq(graph_new(&graph, &input), ERROR, "setting graph for map %s should return ERROR", map);
	input_del(&input);
}

Test(input_read, invalid_link_incorrect_room_name_1)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_link_incorrect_room_name_1";
	t_graph			graph;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), SUCCESS, "reading map %s should return SUCCESS", map);
	cr_expect_eq(graph_new(&graph, &input), ERROR, "setting graph for map %s should return ERROR", map);
	input_del(&input);
}

Test(input_read, invalid_link_incorrect_room_name_2)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_link_incorrect_room_name_2";
	t_graph			graph;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), SUCCESS, "reading map %s should return SUCCESS", map);
	cr_expect_eq(graph_new(&graph, &input), ERROR, "setting graph for map %s should return ERROR", map);
	input_del(&input);
}

Test(input_read, invalid_link_incorrect_room_name_3)
{
	int				fd;
	t_input_info	input;
	char			*map = "tests/maps/invalid_link_incorrect_room_name_3";
	t_graph			graph;

	ft_bzero(&input, sizeof(input));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	cr_assert_gt(fd, 0, "couldn't open %s", map);
	dup2(fd, 0);
	cr_expect_eq(input_read(&input), SUCCESS, "reading map %s should return SUCCESS", map);
	cr_expect_eq(graph_new(&graph, &input), ERROR, "setting graph for map %s should return ERROR", map);
	input_del(&input);
}

