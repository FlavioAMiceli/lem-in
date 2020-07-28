/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_max_flow.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/04 16:07:35 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/28 20:38:49 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include <fcntl.h>
#include <unistd.h>
#include "lem_in.h"
#include "libft.h"

static int		load_map(t_graph *graph, char *map)
{
	int				fd;
	t_input_info	input;

	ft_bzero(&input, sizeof(input));
	ft_bzero(graph, sizeof(t_graph));
	input.ant_no = -1;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ERROR);
	dup2(fd, 0);
	if (input_read(&input) == ERROR)
		return (ERROR);
	if (graph_new(graph, &input) == ERROR)
		return (ERROR);
	input_del(&input);
	return (SUCCESS);
}

Test(max_flow, valid_normal)
{
	t_graph		graph;
	t_edge		*edge;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_normal"), SUCCESS, "graph couldn't be build");

	unsigned int	paths = 1;
	t_vert			*path_1 = hmap_get(graph.vertices, "some_room");
	int				hops_1 = 2;
	unsigned int	thresh_1 = 1;
	cr_assert_neq(path_1, NULL, "couldn't find vertix");

	distance_set(&graph, graph.sink, NULL);
	edmonds_karp(&graph);
	cr_assert_eq(graph.path_count, paths, "number of paths %d doesn't match expected number of paths %d", graph.path_count, paths);

	cr_assert_eq(graph.paths[0]->start, path_1, "first path saved: %s is not equal to first path expected: %s\n", graph.paths[0]->start->name, path_1->name);
	cr_assert_eq(graph.paths[0]->start->hops, hops_1, "first path hops saved: %d is not equal to first path hops expected: %d\n", graph.paths[0]->start->hops, hops_1);
	cr_assert_eq(graph.paths[0]->threshold, thresh_1, "threshold %d for first path doesn't match expected threshold %d\n", graph.paths[0]->threshold, thresh_1);
	//check first path
	edge = path_1->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "room", "room after 'some_room' is %s. Expected room is 'room'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "3", "room after 'room' is %s. Expected room is '3'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge)
	{
		cr_expect_neq(edge->flow, 1, "connection from sink to %s hs flow of 1", edge->head->name);
		edge = edge->next_conn;
	}

	graph_del(&graph);
}

Test(max_flow, valid_normal_2_ants_1)
{
	t_graph		graph;
	t_edge		*edge;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_deadend_2"), SUCCESS, "graph couldn't be build");

	unsigned int	paths = 1;
	t_vert			*path_1 = hmap_get(graph.vertices, "D");
	int				hops_1 = 3;
	unsigned int	thresh_1 = 1;
	cr_assert_neq(path_1, NULL, "couldn't find vertix");

	distance_set(&graph, graph.sink, NULL);
	edmonds_karp(&graph);
	cr_assert_eq(graph.path_count, paths, "number of paths %d doesn't match expected number of paths %d", graph.path_count, paths);

	cr_assert_eq(graph.paths[0]->start, path_1, "first path saved: %s is not equal to first path expected: %s\n", graph.paths[0]->start->name, path_1->name);
	cr_assert_eq(graph.paths[0]->start->hops, hops_1, "first path hops saved: %d is not equal to first path hops expected: %d\n", graph.paths[0]->start->hops, hops_1);
	cr_assert_eq(graph.paths[0]->threshold, thresh_1, "threshold %d for first path doesn't match expected threshold %d\n", graph.paths[0]->threshold, thresh_1);
	//check first path
	edge = path_1->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "E", "room after 'D' is %s. Expected room is 'E'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "F", "room after 'E' is %s. Expected room is 'F'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "snk", "room after 'F' is %s. Expected room is 'snk'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge)
	{
		cr_expect_neq(edge->flow, 1, "connection from sink to %s hs flow of 1", edge->head->name);
		edge = edge->next_conn;
	}

	graph_del(&graph);
}

Test(max_flow, valid_normal_2_ants_2)
{
	t_graph		graph;
	t_edge		*edge;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_deadend_3"), SUCCESS, "graph couldn't be build");

	unsigned int	paths = 2;
	t_vert			*path_1 = hmap_get(graph.vertices, "D");
	int				hops_1 = 3;
	unsigned int	thresh_1 = 1;
	cr_assert_neq(path_1, NULL, "couldn't find vertix");
	t_vert			*path_2 = hmap_get(graph.vertices, "G");
	int				hops_2 = 3;
	unsigned int	thresh_2 = 2;
	cr_assert_neq(path_2, NULL, "couldn't find vertix");

	distance_set(&graph, graph.sink, NULL);
	edmonds_karp(&graph);
	cr_assert_eq(graph.path_count, paths, "number of paths %d doesn't match expected number of paths %d", graph.path_count, paths);

	cr_assert_eq(graph.paths[0]->start, path_1, "first path saved: %s is not equal to first path expected: %s\n", graph.paths[0]->start->name, path_1->name);
	cr_assert_eq(graph.paths[0]->start->hops, hops_1, "first path hops saved: %d is not equal to first path hops expected: %d\n", graph.paths[0]->start->hops, hops_1);
	cr_assert_eq(graph.paths[0]->threshold, thresh_1, "threshold %d for first path doesn't match expected threshold %d\n", graph.paths[0]->threshold, thresh_1);
	//check first path
	edge = path_1->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "E", "room after 'D' is %s. Expected room is 'E'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "F", "room after 'E' is %s. Expected room is 'F'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "snk", "room after 'F' is %s. Expected room is 'snk'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge)
	{
		cr_expect_neq(edge->flow, 1, "connection from sink to %s hs flow of 1", edge->head->name);
		edge = edge->next_conn;
	}

	cr_assert_eq(graph.paths[1]->start, path_2, "second path saved: %s is not equal to second path expected: %s\n", graph.paths[1]->start->name, path_2->name);
	cr_assert_eq(graph.paths[1]->start->hops, hops_2, "second path hops saved: %d is not equal to second path hops expected: %d\n", graph.paths[1]->start->hops, hops_2);
	cr_assert_eq(graph.paths[1]->threshold, thresh_2, "threshold %d for second path doesn't match expected threshold %d\n", graph.paths[1]->threshold, thresh_2);

	graph_del(&graph);
}

Test(max_flow, valid_normal_2_ants_4)
{
	t_graph		graph;
	t_edge		*edge;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_deadend_4"), SUCCESS, "graph couldn't be build");

	unsigned int	paths = 2;
	t_vert			*path_1 = hmap_get(graph.vertices, "D");
	int				hops_1 = 3;
	unsigned int	thresh_1 = 1;
	cr_assert_neq(path_1, NULL, "couldn't find vertix");
	t_vert			*path_2 = hmap_get(graph.vertices, "G");
	int				hops_2 = 3;
	unsigned int	thresh_2 = 2;
	cr_assert_neq(path_2, NULL, "couldn't find vertix");

	distance_set(&graph, graph.sink, NULL);
	edmonds_karp(&graph);
	cr_assert_eq(graph.path_count, paths, "number of paths %d doesn't match expected number of paths %d", graph.path_count, paths);

	cr_assert_eq(graph.paths[0]->start, path_1, "first path saved: %s is not equal to first path expected: %s\n", graph.paths[0]->start->name, path_1->name);
	cr_assert_eq(graph.paths[0]->start->hops, hops_1, "first path hops saved: %d is not equal to first path hops expected: %d\n", graph.paths[0]->start->hops, hops_1);
	cr_assert_eq(graph.paths[0]->threshold, thresh_1, "threshold %d for first path doesn't match expected threshold %d\n", graph.paths[0]->threshold, thresh_1);
	//check first path
	edge = path_1->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "E", "room after 'D' is %s. Expected room is 'E'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "F", "room after 'E' is %s. Expected room is 'F'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "snk", "room after 'F' is %s. Expected room is 'snk'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge)
	{
		cr_expect_neq(edge->flow, 1, "connection from sink to %s hs flow of 1", edge->head->name);
		edge = edge->next_conn;
	}

	cr_assert_eq(graph.paths[1]->start, path_2, "second path saved: %s is not equal to second path expected: %s\n", graph.paths[1]->start->name, path_2->name);
	cr_assert_eq(graph.paths[1]->start->hops, hops_2, "second path hops saved: %d is not equal to second path hops expected: %d\n", graph.paths[1]->start->hops, hops_2);
	cr_assert_eq(graph.paths[1]->threshold, thresh_2, "threshold %d for second path doesn't match expected threshold %d\n", graph.paths[1]->threshold, thresh_2);
	//check second path
	edge = path_2->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "H", "room after 'G' is %s. Expected room is 'H'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "I", "room after 'H' is %s. Expected room is 'I'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "snk", "room after 'I' is %s. Expected room is 'snk'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge)
	{
		cr_expect_neq(edge->flow, 1, "connection from sink to %s hs flow of 1", edge->head->name);
		edge = edge->next_conn;
	}

	graph_del(&graph);
}

Test(max_flow, valid_normal_2_ants_5)
{
	t_graph		graph;
	t_edge		*edge;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_deadend_5"), SUCCESS, "graph couldn't be build");

	unsigned int	paths = 3;
	t_vert			*path_1 = hmap_get(graph.vertices, "D");
	int				hops_1 = 4;
	unsigned int	thresh_1 = 1;
	cr_assert_neq(path_1, NULL, "couldn't find vertix");
	t_vert			*path_2 = hmap_get(graph.vertices, "G");
	int				hops_2 = 4;
	unsigned int	thresh_2 = 2;
	cr_assert_neq(path_2, NULL, "couldn't find vertix");
	t_vert			*path_3 = hmap_get(graph.vertices, "A");
	int				hops_3 = 4;
	unsigned int	thresh_3 = 3;
	cr_assert_neq(path_3, NULL, "couldn't find vertix");

	distance_set(&graph, graph.sink, NULL);
	edmonds_karp(&graph);
	cr_assert_eq(graph.path_count, paths, "number of paths %d doesn't match expected number of paths %d", graph.path_count, paths);

	cr_assert_eq(graph.paths[0]->start, path_1, "first path saved: %s is not equal to first path expected: %s\n", graph.paths[0]->start->name, path_1->name);
	cr_assert_eq(graph.paths[0]->start->hops, hops_1, "first path hops saved: %d is not equal to first path hops expected: %d\n", graph.paths[0]->start->hops, hops_1);
	cr_assert_eq(graph.paths[0]->threshold, thresh_1, "threshold %d for first path doesn't match expected threshold %d\n", graph.paths[0]->threshold, thresh_1);
	//check first path
	edge = path_1->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "E", "room after 'D' is %s. Expected room is 'E'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "H", "room after 'E' is %s. Expected room is 'H'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "I", "room after 'H' is %s. Expected room is 'I'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "snk", "room after 'I' is %s. Expected room is 'snk'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge)
	{
		cr_expect_neq(edge->flow, 1, "connection from sink to %s hs flow of 1", edge->head->name);
		edge = edge->next_conn;
	}

	cr_assert_eq(graph.paths[1]->start, path_2, "second path saved: %s is not equal to second path expected: %s\n", graph.paths[1]->start->name, path_2->name);
	cr_assert_eq(graph.paths[1]->start->hops, hops_2, "first path hops saved: %d is not equal to first path hops expected: %d\n", graph.paths[1]->start->hops, hops_2);
	cr_assert_eq(graph.paths[1]->threshold, thresh_2, "threshold %d for first path doesn't match expected threshold %d\n", graph.paths[1]->threshold, thresh_2);
	//check second path
	edge = path_2->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "K", "room after 'G' is %s. Expected room is 'K'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "O", "room after 'K' is %s. Expected room is 'O'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "M", "room after 'O' is %s. Expected room is 'M'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "snk", "room after 'M' is %s. Expected room is 'snk'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge)
	{
		cr_expect_neq(edge->flow, 1, "connection from sink to %s hs flow of 1", edge->head->name);
		edge = edge->next_conn;
	}

	cr_assert_eq(graph.paths[2]->start, path_3, "third path saved: %s is not equal to third path expected: %s\n", graph.paths[2]->start->name, path_3->name);
	cr_assert_eq(graph.paths[2]->start->hops, hops_3, "third path hops saved: %d is not equal to third path hops expected: %d\n", graph.paths[2]->start->hops, hops_3);
	cr_assert_eq(graph.paths[2]->threshold, thresh_3, "threshold %d for third path doesn't match expected threshold %d\n", graph.paths[2]->threshold, thresh_3);
	//check third path
	edge = path_3->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "B", "room after 'A' is %s. Expected room is 'B'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "C", "room after 'B' is %s. Expected room is 'C'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "F", "room after 'C' is %s. Expected room is 'F'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge->flow != 1)
		edge = edge->next_conn;
	cr_assert_str_eq(edge->head->name, "snk", "room after 'F' is %s. Expected room is 'snk'\n", edge->head->name);
	edge = edge->head->connections;
	while (edge)
	{
		cr_expect_neq(edge->flow, 1, "connection from sink to %s hs flow of 1", edge->head->name);
		edge = edge->next_conn;
	}

	graph_del(&graph);
}
