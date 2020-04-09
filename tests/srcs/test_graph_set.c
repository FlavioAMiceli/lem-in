/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_graph_set.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:48:16 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/04/09 17:27:52 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "lem_in.h"
#include "libft.h"

Test(graph_set, valid_flow_one)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	int				vert_count = 276;
	int				ant_count = 1;
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
	cr_assert_eq(graph_set(&graph, &input), OK, "normal map returns error");
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
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
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
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->head);
	room_name = "Ozu2";
	link_count = 2;
	link1 = "Tr_3";
	link2 = "Jc_3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "S_j8";
	link_count = 2;
	link1 = "Axu1";
	link2 = "Qji0";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "Czq6";
	link_count = 1;
	link1 = "Nte9";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "Hsx0";
	link_count = 1;
	link1 = "Wpg6";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, valid_flow_ten)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	int				vert_count = 738;
	int				ant_count = 10;
	char			*source = "Fog1";
	char			*sink = "Gll7";
	t_vert			*vert;


	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_flow_ten", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_assert_eq(graph_set(&graph, &input), OK, "normal map returns error");
	cr_expect_eq(graph.vert_count, vert_count, "rooms read = %d, rooms expected = %d", graph.vert_count, vert_count);
	cr_expect_eq(graph.ant_count, ant_count, "incorrect amount of ants. Expecter = %d, read = %d", ant_count, graph.ant_count);
	cr_expect_str_eq(graph.source->name, source, "source read = %s, source expected = %s", graph.source->name, source);
	cr_expect_str_eq(graph.sink->name, sink, "sink read = %s, sink expected = %s", graph.sink->name, sink);
	//
	// test room and links
	char	*room_name = "Xua6";
	int		link_count = 3;
	char	*link1 = "Wln7";
	char	*link2 = "Erf1";
	char	*link3 = "I_m9";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link3), vert->connections->next_conn->next_conn->head, "third connection for %s expected: %s, found: %s", room_name, link3, vert->connections->next_conn->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "Ear0";
	link_count = 1;
	link1 = "Pca3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "Ukt1";
	link_count = 1;
	link1 = "Nne4";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "Qkf0";
	link_count = 2;
	link1 = "Oda0";
	link2 = "Hxm2";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "Owd0";
	link_count = 2;
	link1 = "Q_t5";
	link2 = "Cqv2";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, valid_link_duplicate_2)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	int				vert_count = 6;
	int				ant_count = 79;
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
	cr_assert_eq(graph_set(&graph, &input), OK, "normal map returns error");
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
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "room";
	link_count = 2;
	link1 = "some_room";
	link2 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, valid_link_duplicate_1)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	int				vert_count = 6;
	int				ant_count = 79;
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
	cr_assert_eq(graph_set(&graph, &input), OK, "normal map returns error");
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
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "room";
	link_count = 2;
	link1 = "some_room";
	link2 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, valid_link_head_equal_tail)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	int				vert_count = 6;
	int				ant_count = 79;
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
	cr_assert_eq(graph_set(&graph, &input), OK, "normal map returns error");
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
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "room";
	link_count = 2;
	link1 = "some_room";
	link2 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, valid_same_start_end)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	int				vert_count = 6;
	int				ant_count = 79;
	char			*source = "3";
	char			*sink = "3";
	t_vert			*vert;


	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/valid_same_start_end", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_assert_eq(graph_set(&graph, &input), OK, "normal map returns error");
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
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "room";
	link_count = 2;
	link1 = "some_room";
	link2 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, valid_normal)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;
	int				vert_count = 6;
	int				ant_count = 79;
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
	cr_assert_eq(graph_set(&graph, &input), OK, "normal map returns error");
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
	cr_expect_eq(vert->connections->next_conn->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "bla";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "blu";
	link_count = 1;
	link1 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "3";
	link_count = 2;
	link1 = "room";
	link2 = "devil";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "devil";
	link_count = 1;
	link1 = "3";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(vert->connections->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	room_name = "room";
	link_count = 2;
	link1 = "3";
	link2 = "some_room";
	vert = hmap_get(graph.vertices, room_name);
	cr_expect_neq(vert, NULL, "hmap_get didn't get the right room");
	cr_expect_eq(vert->conn_count, link_count, "link count incorrect. Expected: %d, got: %d", link_count, vert->conn_count);
	cr_expect_eq(hmap_get(graph.vertices, link1), vert->connections->head, "first connection for %s expected: %s, found: %s", room_name, link1, vert->connections->head->name);
	cr_expect_eq(hmap_get(graph.vertices, link2), vert->connections->next_conn->head, "second connection for %s expected: %s, found: %s", room_name, link2, vert->connections->next_conn->head->name);
	cr_expect_eq(vert->connections->next_conn->next_conn, NULL, "found too many connections for %s. incorrect connection: %s", room_name, vert->connections->next_conn->next_conn->next_conn->head);
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_room_with_minus)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_room_with_minus", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "room with '-' in name does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_room_duplicate_4)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_room_duplicate_4", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "duplicate room name does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_room_duplicate_3)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_room_duplicate_3", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "duplicate room name does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_room_duplicate_2)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_room_duplicate_2", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "duplicate room name does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_room_duplicate_1)
{
	t_graph			graph;
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(&graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open("tests/maps/invalid_room_duplicate_1", O_RDONLY);
	cr_assert_gt(fd, 0, "open failed, fd is %d", fd);
	dup2(fd, 0);
	cr_assert_eq(input_read(&input), 1, "couldn't read map");
	cr_expect_eq(graph_set(&graph, &input), ERROR, "duplicate room name does not return error");
	input_del(&input);
	graph_del(&graph);
}

Test(graph_set, invalid_link_incorrect_room_name_3)
{
	t_graph			graph;
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
	t_graph			graph;
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
	t_graph			graph;
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
	t_graph			graph;
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
	t_graph			graph;
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
	t_graph			graph;
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
