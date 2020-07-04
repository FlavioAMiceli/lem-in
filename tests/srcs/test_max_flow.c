/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_max_flow.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/04 16:07:35 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/04 17:55:50 by mmarcell      ########   odam.nl         */
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
	graph_del(&graph);
}

Test(max_flow, valid_normal_2_ants_1)
{
	t_graph		graph;

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
	graph_del(&graph);
}

Test(max_flow, valid_normal_2_ants_2)
{
	t_graph		graph;

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
	cr_assert_eq(graph.paths[1]->start, path_2, "first path saved: %s is not equal to first path expected: %s\n", graph.paths[0]->start->name, path_2->name);
	cr_assert_eq(graph.paths[1]->start->hops, hops_2, "first path hops saved: %d is not equal to first path hops expected: %d\n", graph.paths[0]->start->hops, hops_2);
	cr_assert_eq(graph.paths[1]->threshold, thresh_2, "threshold %d for first path doesn't match expected threshold %d\n", graph.paths[0]->threshold, thresh_2);
	graph_del(&graph);
}
