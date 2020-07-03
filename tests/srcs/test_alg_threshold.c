/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_alg_threshold.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: moana <moana@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/24 12:34:33 by moana         #+#    #+#                 */
/*   Updated: 2020/04/30 16:23:24 by mmarcell      ########   odam.nl         */
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
	return (SUCCESS);
}

Test(alg_threshold, idx_is_23_4)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 23;
	graph.paths[0]->start->hops = 212;
	graph.paths[1]->start->hops = 412;
	graph.paths[2]->start->hops = 612;
	graph.paths[3]->start->hops = 812;
	graph.paths[4]->start->hops = 1120;
	graph.paths[5]->start->hops = 1122;
	graph.paths[6]->start->hops = 1124;
	graph.paths[7]->start->hops = 1126;
	graph.paths[8]->start->hops = 1128;
	graph.paths[9]->start->hops = 2120;
	graph.paths[10]->start->hops = 1222;
	graph.paths[11]->start->hops = 1224;
	graph.paths[12]->start->hops = 1226;
	graph.paths[13]->start->hops = 1228;
	graph.paths[14]->start->hops = 1230;
	graph.paths[15]->start->hops = 1232;
	graph.paths[16]->start->hops = 1234;
	graph.paths[17]->start->hops = 1236;
	graph.paths[18]->start->hops = 1238;
	graph.paths[19]->start->hops = 1240;
	graph.paths[20]->start->hops = 1242;
	graph.paths[21]->start->hops = 1244;
	graph.paths[22]->start->hops = 1246;
	placeholder = 48;
	threshold_expected = 1;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_23_3)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 23;
	graph.paths[0]->start->hops = 10;
	graph.paths[1]->start->hops = 10;
	graph.paths[2]->start->hops = 10;
	graph.paths[3]->start->hops = 10;
	graph.paths[4]->start->hops = 10;
	graph.paths[5]->start->hops = 10;
	graph.paths[6]->start->hops = 10;
	graph.paths[7]->start->hops = 10;
	graph.paths[8]->start->hops = 10;
	graph.paths[9]->start->hops = 10;
	graph.paths[10]->start->hops = 10;
	graph.paths[11]->start->hops = 10;
	graph.paths[12]->start->hops = 10;
	graph.paths[13]->start->hops = 10;
	graph.paths[14]->start->hops = 10;
	graph.paths[15]->start->hops = 10;
	graph.paths[16]->start->hops = 10;
	graph.paths[17]->start->hops = 10;
	graph.paths[18]->start->hops = 10;
	graph.paths[19]->start->hops = 10;
	graph.paths[20]->start->hops = 10;
	graph.paths[21]->start->hops = 10;
	graph.paths[22]->start->hops = 10;
	placeholder = 10;
	threshold_expected = 24;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_23_2)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 23;
	graph.paths[0]->start->hops = 12;
	graph.paths[1]->start->hops = 14;
	graph.paths[2]->start->hops = 16;
	graph.paths[3]->start->hops = 18;
	graph.paths[4]->start->hops = 110;
	graph.paths[5]->start->hops = 112;
	graph.paths[6]->start->hops = 114;
	graph.paths[7]->start->hops = 116;
	graph.paths[8]->start->hops = 118;
	graph.paths[9]->start->hops = 120;
	graph.paths[10]->start->hops = 122;
	graph.paths[11]->start->hops = 124;
	graph.paths[12]->start->hops = 126;
	graph.paths[13]->start->hops = 128;
	graph.paths[14]->start->hops = 130;
	graph.paths[15]->start->hops = 132;
	graph.paths[16]->start->hops = 134;
	graph.paths[17]->start->hops = 136;
	graph.paths[18]->start->hops = 138;
	graph.paths[19]->start->hops = 140;
	graph.paths[20]->start->hops = 42;
	graph.paths[21]->start->hops = 44;
	graph.paths[22]->start->hops = 46;
	placeholder = 48;
	threshold_expected = 152;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_23_1)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 23;
	graph.paths[0]->start->hops = 2;
	graph.paths[1]->start->hops = 4;
	graph.paths[2]->start->hops = 6;
	graph.paths[3]->start->hops = 8;
	graph.paths[4]->start->hops = 10;
	graph.paths[5]->start->hops = 12;
	graph.paths[6]->start->hops = 14;
	graph.paths[7]->start->hops = 16;
	graph.paths[8]->start->hops = 18;
	graph.paths[9]->start->hops = 20;
	graph.paths[10]->start->hops = 22;
	graph.paths[11]->start->hops = 24;
	graph.paths[12]->start->hops = 26;
	graph.paths[13]->start->hops = 28;
	graph.paths[14]->start->hops = 30;
	graph.paths[15]->start->hops = 32;
	graph.paths[16]->start->hops = 34;
	graph.paths[17]->start->hops = 36;
	graph.paths[18]->start->hops = 38;
	graph.paths[19]->start->hops = 40;
	graph.paths[20]->start->hops = 42;
	graph.paths[21]->start->hops = 44;
	graph.paths[22]->start->hops = 46;
	placeholder = 48;
	threshold_expected = 576;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_3_4)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 3;
	graph.paths[0]->start->hops = 30;
	graph.paths[1]->start->hops = 40;
	graph.paths[2]->start->hops = 60;
	placeholder = 10;
	threshold_expected = 1;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_3_3)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 3;
	graph.paths[0]->start->hops = 4;
	graph.paths[1]->start->hops = 6;
	graph.paths[2]->start->hops = 20;
	placeholder = 10;
	threshold_expected = 13;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_3_2)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 3;
	graph.paths[0]->start->hops = 3;
	graph.paths[1]->start->hops = 18;
	graph.paths[2]->start->hops = 40;
	placeholder = 50;
	threshold_expected = 93;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_3_1)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 3;
	graph.paths[0]->start->hops = 10;
	graph.paths[1]->start->hops = 10;
	graph.paths[2]->start->hops = 10;
	placeholder = 10;
	threshold_expected = 4;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_2_4)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 2;
	graph.paths[0]->start->hops = 30;
	graph.paths[1]->start->hops = 20;
	placeholder = 10;
	threshold_expected = 1;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_2_3)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 2;
	graph.paths[0]->start->hops = 40;
	graph.paths[1]->start->hops = 10;
	placeholder = 30;
	threshold_expected = 22;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_2_2)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 2;
	graph.paths[0]->start->hops = 2;
	graph.paths[1]->start->hops = 4;
	placeholder = 7;
	threshold_expected = 11;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_2_1)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 2;
	graph.paths[0]->start->hops = 0;
	graph.paths[1]->start->hops = 0;
	placeholder = 0;
	threshold_expected = 3;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_1_4)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 1;
	graph.paths[0]->start->hops = 10;
	placeholder = 5;
	threshold_expected = 1;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_1_3)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 1;
	graph.paths[0]->start->hops = 0;
	placeholder = 0;
	threshold_expected = 2;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}

Test(alg_threshold, idx_is_1_2)
{
	t_graph		graph;
	int			idx;
	int			placeholder;
	int			threshold_expected;
	int			threshold_calculated;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 1;
	graph.paths[0]->start->hops = 10;
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

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 1;
	graph.paths[0]->start->hops = 5;
	placeholder = 10;
	threshold_expected = 7;
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

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
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

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
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

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	cr_assert_eq(add_paths(&graph), SUCCESS, "paths couldn't be loaded");
	idx = 0;
	placeholder = 5;
	threshold_expected = 1;
	threshold_calculated = threshold(graph.paths, idx, placeholder);
	cr_expect_eq(threshold_calculated, threshold_expected, "threshold for path with idx = %d incorrect.\nthreshold_expected: %d, threshold_calculated: %d", idx, threshold_expected, threshold_calculated);
	graph_del(&graph);
}
