/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_alg_threshold.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/24 12:34:33 by moana         #+#    #+#                 */
/*   Updated: 2020/04/30 15:25:51 by mmarcell      ########   odam.nl         */
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
	return (OK);
}

static int		add_paths(t_graph *graph)
{
	t_vert		*path;

	// add path_1
	path = hmap_get(graph->vertices, "B");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_2
	path = hmap_get(graph->vertices, "C");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_3
	path = hmap_get(graph->vertices, "D");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_4
	path = hmap_get(graph->vertices, "E");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_5
	path = hmap_get(graph->vertices, "F");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_6
	path = hmap_get(graph->vertices, "G");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_7
	path = hmap_get(graph->vertices, "H");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_8
	path = hmap_get(graph->vertices, "I");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_9
	path = hmap_get(graph->vertices, "J");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_10
	path = hmap_get(graph->vertices, "K");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_11
	path = hmap_get(graph->vertices, "M");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_12
	path = hmap_get(graph->vertices, "N");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_13
	path = hmap_get(graph->vertices, "O");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_14
	path = hmap_get(graph->vertices, "P");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_15
	path = hmap_get(graph->vertices, "Q");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_16
	path = hmap_get(graph->vertices, "R");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_17
	path = hmap_get(graph->vertices, "S");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_18
	path = hmap_get(graph->vertices, "T");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_19
	path = hmap_get(graph->vertices, "U");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_20
	path = hmap_get(graph->vertices, "V");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_21
	path = hmap_get(graph->vertices, "W");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_22
	path = hmap_get(graph->vertices, "X");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	// add path_23
	path = hmap_get(graph->vertices, "Y");
	if (path == NULL)
		return (ERROR);
	path->hops = 10;
	if (path_new(graph, path) == ERROR)
		return (ERROR);
	return (OK);
}

Test(alg_threshold, idx_is_1_2)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), OK, "paths couldn't be loaded");
	graph.paths[0]->start->hops = 10;
	idx = 1;
	placeholder = 10;
	threshold_expected = 2;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_1_1)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), OK, "paths couldn't be loaded");
	graph.paths[0]->start->hops = 5;
	idx = 1;
	placeholder = 10;
	threshold_expected = 7;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_0_4)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), OK, "paths couldn't be loaded");
	idx = 0;
	placeholder = 10;
	threshold_expected = 1;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_0_3)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), OK, "paths couldn't be loaded");
	idx = 0;
	placeholder = 0;
	threshold_expected = 1;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_0_2)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), OK, "paths couldn't be loaded");
	idx = 0;
	placeholder = 20;
	threshold_expected = 1;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_0_1)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), OK, "paths couldn't be loaded");
	idx = 0;
	placeholder = 5;
	threshold_expected = 1;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}
