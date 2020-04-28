/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_path_set.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/04/24 17:35:35 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/04/28 13:33:00 by mmarcell      ########   odam.nl         */
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

Test(path_set, first_path)
{
	t_graph		graph;
	t_vert		*path_1;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix");
	path_1->hops = 3;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.paths[0]->start, path_1, "first path not in paths[0]");
	cr_expect_eq(graph.paths[0]->threshold, 0, "threshold not initialized");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	graph_del(&graph);
}

Test(path_set, second_path_1)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 3;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.paths[0]->start, path_1, "first path not in paths[0]");
	cr_expect_eq(graph.paths[0]->threshold, 0, "threshold not initialized");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 3;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.paths[1]->start, path_2, "first path not in paths[1]");
	cr_expect_eq(graph.paths[1]->threshold, 0, "threshold not initialized");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	graph_del(&graph);
}

Test(path_set, second_path_2)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 3;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.paths[0]->start, path_1, "first path not in paths[0]");
	cr_expect_eq(graph.paths[0]->threshold, 0, "threshold not initialized");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 4;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.paths[1]->start, path_2, "first path not in paths[1]");
	cr_expect_eq(graph.paths[1]->threshold, 0, "threshold not initialized");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	graph_del(&graph);
}

Test(path_set, second_path_3)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 3;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 1;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// check threshold
	cr_expect_eq(graph.paths[0]->threshold, 0, "threshold not initialized");
	cr_expect_eq(graph.paths[1]->threshold, 0, "threshold not initialized");
	// check order
	cr_expect_eq(graph.paths[0]->start, path_2, "shortest path not in paths[0]");
	cr_expect_eq(graph.paths[1]->start, path_1, "second shortest path not in paths[1]");
	graph_del(&graph);
}

Test(path_set, second_path_4)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 3;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_1->hops = 5;
	path_2->hops = 4;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, third_path_1)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 4;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 4;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_3->hops = 4;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, third_path_2)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 20;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 30;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_1->hops = 20;
	path_2->hops = 30;
	path_3->hops = 40;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, third_path_3)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 20;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 30;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_1->hops = 50;
	path_2->hops = 30;
	path_3->hops = 40;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, third_path_4)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 20;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 30;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_1->hops = 60;
	path_2->hops = 50;
	path_3->hops = 40;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, third_path_5)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 20;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 30;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_1->hops = 20;
	path_2->hops = 50;
	path_3->hops = 40;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, fourth_path_1)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	t_vert		*path_4;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 30;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 30;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_3->hops = 30;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// add path_4
	path_4 = hmap_get(graph.vertices, "E");
	cr_assert_neq(path_4, NULL, "couldn't find vertix for path_4");
	path_1->hops = 30;
	path_2->hops = 30;
	path_3->hops = 30;
	path_4->hops = 30;
	cr_assert_eq(path_new(&graph, path_4), OK, "addding fourth path didn't work");
	cr_expect_eq(graph.path_count, 4, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, fourth_path_2)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	t_vert		*path_4;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 10;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 10;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_3->hops = 10;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// add path_4
	path_4 = hmap_get(graph.vertices, "E");
	cr_assert_neq(path_4, NULL, "couldn't find vertix for path_4");
	path_1->hops = 10;
	path_2->hops = 15;
	path_3->hops = 20;
	path_4->hops = 25;
	cr_assert_eq(path_new(&graph, path_4), OK, "addding fourth path didn't work");
	cr_expect_eq(graph.path_count, 4, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, fourth_path_3)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	t_vert		*path_4;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 10;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 10;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_3->hops = 10;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// add path_4
	path_4 = hmap_get(graph.vertices, "E");
	cr_assert_neq(path_4, NULL, "couldn't find vertix for path_4");
	path_1->hops = 30;
	path_2->hops = 25;
	path_3->hops = 20;
	path_4->hops = 15;
	cr_assert_eq(path_new(&graph, path_4), OK, "addding fourth path didn't work");
	cr_expect_eq(graph.path_count, 4, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, fourth_path_4)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	t_vert		*path_4;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 10;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 10;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_3->hops = 10;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// add path_4
	path_4 = hmap_get(graph.vertices, "E");
	cr_assert_neq(path_4, NULL, "couldn't find vertix for path_4");
	path_1->hops = 25;
	path_2->hops = 10;
	path_3->hops = 20;
	path_4->hops = 15;
	cr_assert_eq(path_new(&graph, path_4), OK, "addding fourth path didn't work");
	cr_expect_eq(graph.path_count, 4, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, fourth_path_5)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	t_vert		*path_4;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 10;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 10;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_3->hops = 10;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// add path_4
	path_4 = hmap_get(graph.vertices, "E");
	cr_assert_neq(path_4, NULL, "couldn't find vertix for path_4");
	path_1->hops = 15;
	path_2->hops = 25;
	path_3->hops = 20;
	path_4->hops = 10;
	cr_assert_eq(path_new(&graph, path_4), OK, "addding fourth path didn't work");
	cr_expect_eq(graph.path_count, 4, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(path_set, many_paths_1)
{
	t_graph		graph;
	t_vert		*path_1;
	t_vert		*path_2;
	t_vert		*path_3;
	t_vert		*path_4;
	t_vert		*path_5;
	t_vert		*path_6;
	t_vert		*path_7;
	t_vert		*path_8;
	t_vert		*path_9;
	t_vert		*path_10;
	t_vert		*path_11;
	t_vert		*path_12;
	t_vert		*path_13;
	t_vert		*path_14;
	t_vert		*path_15;
	t_vert		*path_16;
	t_vert		*path_17;
	t_vert		*path_18;
	t_vert		*path_19;
	t_vert		*path_20;
	t_vert		*path_21;
	t_vert		*path_22;
	t_vert		*path_23;
	int			i;

	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), OK, "graph couldn't be build");
	// add path_1
	path_1 = hmap_get(graph.vertices, "B");
	cr_assert_neq(path_1, NULL, "couldn't find vertix for path_1");
	path_1->hops = 10;
	cr_assert_eq(path_new(&graph, path_1), OK, "addding first path didn't work");
	cr_expect_eq(graph.path_count, 1, "path_count not incremented");
	// add path_2
	path_2 = hmap_get(graph.vertices, "C");
	cr_assert_neq(path_2, NULL, "couldn't find vertix for path_2");
	path_2->hops = 10;
	cr_assert_eq(path_new(&graph, path_2), OK, "addding second path didn't work");
	cr_expect_eq(graph.path_count, 2, "path_count not incremented");
	// add path_3
	path_3 = hmap_get(graph.vertices, "D");
	cr_assert_neq(path_3, NULL, "couldn't find vertix for path_3");
	path_3->hops = 10;
	cr_assert_eq(path_new(&graph, path_3), OK, "addding third path didn't work");
	cr_expect_eq(graph.path_count, 3, "path_count not incremented");
	// add path_4
	path_4 = hmap_get(graph.vertices, "E");
	cr_assert_neq(path_4, NULL, "couldn't find vertix for path_4");
	path_4->hops = 10;
	cr_assert_eq(path_new(&graph, path_4), OK, "addding fourth path didn't work");
	cr_expect_eq(graph.path_count, 4, "path_count not incremented");
	// add path_5
	path_5 = hmap_get(graph.vertices, "F");
	cr_assert_neq(path_5, NULL, "couldn't find vertix for path_5");
	path_5->hops = 10;
	cr_assert_eq(path_new(&graph, path_5), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 5, "path_count not incremented");
	// add path_6
	path_6 = hmap_get(graph.vertices, "G");
	cr_assert_neq(path_6, NULL, "couldn't find vertix for path_6");
	path_6->hops = 10;
	cr_assert_eq(path_new(&graph, path_6), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 6, "path_count not incremented");
	// add path_7
	path_7 = hmap_get(graph.vertices, "H");
	cr_assert_neq(path_7, NULL, "couldn't find vertix for path_7");
	path_7->hops = 10;
	cr_assert_eq(path_new(&graph, path_7), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 7, "path_count not incremented");
	// add path_8
	path_8 = hmap_get(graph.vertices, "I");
	cr_assert_neq(path_8, NULL, "couldn't find vertix for path_8");
	path_8->hops = 10;
	cr_assert_eq(path_new(&graph, path_8), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 8, "path_count not incremented");
	// add path_9
	path_9 = hmap_get(graph.vertices, "J");
	cr_assert_neq(path_9, NULL, "couldn't find vertix for path_9");
	path_9->hops = 10;
	cr_assert_eq(path_new(&graph, path_9), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 9, "path_count not incremented");
	// add path_10
	path_10 = hmap_get(graph.vertices, "K");
	cr_assert_neq(path_10, NULL, "couldn't find vertix for path_10");
	path_10->hops = 10;
	cr_assert_eq(path_new(&graph, path_10), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 10, "path_count not incremented");
	// add path_11
	path_11 = hmap_get(graph.vertices, "M");
	cr_assert_neq(path_11, NULL, "couldn't find vertix for path_11");
	path_11->hops = 10;
	cr_assert_eq(path_new(&graph, path_11), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 11, "path_count not incremented");
	// add path_12
	path_12 = hmap_get(graph.vertices, "N");
	cr_assert_neq(path_12, NULL, "couldn't find vertix for path_12");
	path_12->hops = 10;
	cr_assert_eq(path_new(&graph, path_12), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 12, "path_count not incremented");
	// add path_13
	path_13 = hmap_get(graph.vertices, "O");
	cr_assert_neq(path_13, NULL, "couldn't find vertix for path_13");
	path_13->hops = 10;
	cr_assert_eq(path_new(&graph, path_13), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 13, "path_count not incremented");
	// add path_14
	path_14 = hmap_get(graph.vertices, "P");
	cr_assert_neq(path_14, NULL, "couldn't find vertix for path_14");
	path_14->hops = 10;
	cr_assert_eq(path_new(&graph, path_14), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 14, "path_count not incremented");
	// add path_15
	path_15 = hmap_get(graph.vertices, "Q");
	cr_assert_neq(path_15, NULL, "couldn't find vertix for path_15");
	path_15->hops = 10;
	cr_assert_eq(path_new(&graph, path_15), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 15, "path_count not incremented");
	// add path_16
	path_16 = hmap_get(graph.vertices, "R");
	cr_assert_neq(path_16, NULL, "couldn't find vertix for path_16");
	path_16->hops = 10;
	cr_assert_eq(path_new(&graph, path_16), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 16, "path_count not incremented");
	// add path_17
	path_17 = hmap_get(graph.vertices, "S");
	cr_assert_neq(path_17, NULL, "couldn't find vertix for path_17");
	path_17->hops = 10;
	cr_assert_eq(path_new(&graph, path_17), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 17, "path_count not incremented");
	// add path_18
	path_18 = hmap_get(graph.vertices, "T");
	cr_assert_neq(path_18, NULL, "couldn't find vertix for path_18");
	path_18->hops = 10;
	cr_assert_eq(path_new(&graph, path_18), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 18, "path_count not incremented");
	// add path_19
	path_19 = hmap_get(graph.vertices, "U");
	cr_assert_neq(path_19, NULL, "couldn't find vertix for path_19");
	path_19->hops = 10;
	cr_assert_eq(path_new(&graph, path_19), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 19, "path_count not incremented");
	// add path_20
	path_20 = hmap_get(graph.vertices, "V");
	cr_assert_neq(path_20, NULL, "couldn't find vertix for path_20");
	path_20->hops = 10;
	cr_assert_eq(path_new(&graph, path_20), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 20, "path_count not incremented");
	// add path_21
	path_21 = hmap_get(graph.vertices, "W");
	cr_assert_neq(path_21, NULL, "couldn't find vertix for path_21");
	path_21->hops = 10;
	cr_assert_eq(path_new(&graph, path_21), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 21, "path_count not incremented");
	// add path_22
	path_22 = hmap_get(graph.vertices, "X");
	cr_assert_neq(path_22, NULL, "couldn't find vertix for path_22");
	path_22->hops = 10;
	cr_assert_eq(path_new(&graph, path_22), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 22, "path_count not incremented");
	// add path_23
	path_23 = hmap_get(graph.vertices, "Y");
	cr_assert_neq(path_23, NULL, "couldn't find vertix for path_23");
	path_1->hops = 50;
	path_2->hops = 15;
	path_3->hops = 60;
	path_4->hops = 100;
	path_5->hops = 95;
	path_6->hops = 80;
	path_7->hops = 25;
	path_8->hops = 10;
	path_9->hops = 30;
	path_10->hops = 55;
	path_11->hops = 90;
	path_12->hops = 65;
	path_13->hops = 70;
	path_14->hops = 75;
	path_15->hops = 115;
	path_16->hops = 110;
	path_17->hops = 20;
	path_18->hops = 120;
	path_19->hops = 90;
	path_20->hops = 35;
	path_21->hops = 85;
	path_22->hops = 45;
	path_23->hops = 40;
	cr_assert_eq(path_new(&graph, path_23), OK, "addding path %d didn't work", graph.path_count);
	cr_expect_eq(graph.path_count, 23, "path_count not incremented");
	// check threshold and order
	i = 0;
	cr_expect_eq(graph.paths[i]->threshold, 0, "threshold of paths[0] not initialized");
	while (graph.paths[i] != NULL && graph.paths[i + 1] != NULL)
	{
		cr_expect_leq(graph.paths[i]->start->hops, graph.paths[i + 1]->start->hops, "paths[%d]->start->hops = %d, which is bigger than paths[%d]->start->hops = %d", i, graph.paths[i]->start->hops, i + 1, graph.paths[i + 1]->start->hops);
		cr_expect_eq(graph.paths[i + 1]->threshold, 0, "threshold of paths[%d] not initialized", i + 1);
		++i;
	}
	graph_del(&graph);
}

Test(ft_swap_ptr, test)
{
	int	*a;
	int	*b;
	int	val_a = 1;
	int	val_b = 2;
	a = &val_a;
	b = &val_b;
	ft_swap_ptr((void**)&a, (void**)&b);
	cr_expect_eq(*b, 1, "value of b = %d but should be 1", *b);
	cr_expect_eq(*a, 2, "value of a = %d but should be 2", *a);
}
