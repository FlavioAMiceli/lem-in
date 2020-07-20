/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_get_steps.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/17 11:12:00 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/17 11:12:00 by mmarcell      ########   odam.nl         */
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

static int		add_paths(t_graph *graph, unsigned int path_count, int *hops)
{
	t_vert			*new_path;
	char			*path_name;
	unsigned int	i;

	if (path_count > 23)
		return (ERROR);
	i = 0;
	int flag = 0;
	while (i < path_count)
	{
		new_path = NULL;
		path_name = ft_strnew(1);
		if (i == 10)					// skip room 'L'
		{
			flag = 1;
			++path_count;
		}
		path_name[0] = 'A' + i + flag + 1;
		new_path = hmap_get(graph->vertices, path_name);
		if (new_path == NULL)
		{
			ft_printf("couldn't get room %s, i = %d\n", path_name, i);
			return (ERROR);
		}
		new_path->hops = hops[i];
		if (path_new(graph, new_path) == ERROR)
			return (ERROR);
		ft_strdel(&path_name);
		++i;
	}
	return (SUCCESS);
}

////////////////////////////////////////////////////////////////////////////////
// TESTS	TESTS	TESTS	TESTS	TESTS	TESTS	TESTS	TESTS	TESTS	  //
////////////////////////////////////////////////////////////////////////////////

Test(get_steps, twenty_paths_2)
{
	unsigned int	ant_count = 110;
	unsigned int	path_count = 20;
	int				hops[path_count];
	hops[0] = 1;
	hops[1] = 2;
	hops[2] = 3;
	hops[3] = 4;
	hops[4] = 5;
	hops[5] = 6;
	hops[6] = 7;
	hops[7] = 8;
	hops[8] = 9;
	hops[9] = 10;
	hops[10] = 1;
	hops[11] = 2;
	hops[12] = 3;
	hops[13] = 4;
	hops[14] = 5;
	hops[15] = 6;
	hops[16] = 7;
	hops[17] = 8;
	hops[18] = 9;
	hops[19] = 10;
	int				expected_steps = 11;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, twenty_paths_1)
{
	unsigned int	ant_count = 55;
	unsigned int	path_count = 10;
	int				hops[path_count];
	hops[0] = 1;		//10
	hops[1] = 2;		//9
	hops[2] = 3;		//8
	hops[3] = 4;		//7
	hops[4] = 5;		//6
	hops[5] = 6;		//5
	hops[6] = 7;		//4
	hops[7] = 8;		//3
	hops[8] = 9;		//2
	hops[9] = 10;		//1
	// hops[10] = 1;
	// hops[11] = 2;
	// hops[12] = 3;
	// hops[13] = 4;
	// hops[14] = 5;
	// hops[15] = 6;
	// hops[16] = 7;
	// hops[17] = 8;
	// hops[18] = 9;
	// hops[19] = 10;
	int				expected_steps = 11;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, fifteen_paths_2)
{
	unsigned int	ant_count = 40;
	unsigned int	path_count = 20;
	int				hops[path_count];
	hops[0] = 1;
	hops[1] = 1;
	hops[2] = 1;
	hops[3] = 1;
	hops[4] = 1;
	hops[5] = 1;
	hops[6] = 1;
	hops[7] = 1;
	hops[8] = 1;
	hops[9] = 1;
	hops[10] = 1;
	hops[11] = 1;
	hops[12] = 1;
	hops[13] = 1;
	hops[14] = 1;
	hops[15] = 4;
	hops[16] = 4;
	hops[17] = 4;
	hops[18] = 4;
	hops[19] = 4;
	int				expected_steps = 4;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, fifteen_paths_1)
{
	unsigned int	ant_count = 40;
	unsigned int	path_count = 15;
	int				hops[path_count];
	hops[0] = 1;
	hops[1] = 1;
	hops[2] = 1;
	hops[3] = 1;
	hops[4] = 1;
	hops[5] = 1;
	hops[6] = 1;
	hops[7] = 1;
	hops[8] = 1;
	hops[9] = 1;
	hops[10] = 1;
	hops[11] = 1;
	hops[12] = 1;
	hops[13] = 1;
	hops[14] = 1;
	int				expected_steps = 4;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, ten_paths_3)
{
	unsigned int	ant_count = 55;
	unsigned int	path_count = 10;
	int				hops[path_count];
	hops[0] = 1;
	hops[1] = 2;
	hops[2] = 3;
	hops[3] = 4;
	hops[4] = 5;
	hops[5] = 6;
	hops[6] = 7;
	hops[7] = 8;
	hops[8] = 9;
	hops[9] = 10;
	int				expected_steps = 11;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, ten_paths_2)
{
	unsigned int	ant_count = 40;
	unsigned int	path_count = 10;
	int				hops[path_count];
	hops[0] = 0;
	hops[1] = 0;
	hops[2] = 0;
	hops[3] = 0;
	hops[4] = 0;
	hops[5] = 0;
	hops[6] = 0;
	hops[7] = 0;
	hops[8] = 0;
	hops[9] = 0;
	int				expected_steps = 4;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, ten_paths_1)
{
	unsigned int	ant_count = 40;
	unsigned int	path_count = 10;
	int				hops[path_count];
	hops[0] = 2;
	hops[1] = 2;
	hops[2] = 2;
	hops[3] = 2;
	hops[4] = 2;
	hops[5] = 2;
	hops[6] = 2;
	hops[7] = 2;
	hops[8] = 2;
	hops[9] = 2;
	int				expected_steps = 6;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, ten_paths)
{
	unsigned int	ant_count = 42;
	unsigned int	path_count = 12;
	int				hops[path_count];
	hops[0] = 1;	//
	hops[1] = 2;	//
	hops[2] = 3;	//
	hops[3] = 1;	//
	hops[4] = 2;	//
	hops[5] = 3;	//
	hops[6] = 4;	//
	hops[7] = 4;	//
	hops[8] = 5;	//
	hops[9] = 5;	//
	hops[10] = 6;	//
	hops[11] = 6;	//
	int				expected_steps = 7;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, twelve_paths_1)
{
	unsigned int	ant_count = 2 + 4 + 6 + 8 + 10 + 12;
	unsigned int	path_count = 2 + 2 + 2 + 2 + 2 + 2;
	int				hops[path_count];
	hops[0] = 0;	//2
	hops[1] = 0;	//3
	hops[2] = 1;	//4
	hops[3] = 1;	//2
	hops[4] = 2;	//3
	hops[5] = 2;	//4
	hops[6] = 3;	//5
	hops[7] = 3;	//5
	hops[8] = 4;	//6
	hops[9] = 4;	//6
	hops[10] = 5;	//7
	hops[11] = 5;	//7
	int				expected_steps = 1 + 1 + 1 + 1 + 1 + 1;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

////////////////////////////////////////////////////////////////////////////////

Test(get_steps, three_paths_5)
{
	unsigned int	ant_count = 6;
	unsigned int	path_count = 10;
	int				hops[path_count];
	hops[0] = 70;
	hops[1] = 9;
	hops[2] = 7;
	hops[3] = 312;
	hops[4] = 9;
	hops[5] = 7;
	hops[6] = 9;
	hops[7] = 27;
	hops[8] = 5;
	hops[9] = 17;
	int				expected_steps = 9;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, three_paths_4)
{
	unsigned int	ant_count = 7;
	unsigned int	path_count = 3;
	int				hops[path_count];
	hops[0] = 7;
	hops[1] = 7;
	hops[2] = 7;
	int				expected_steps = 10;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, three_paths_3)
{
	unsigned int	ant_count = 5;
	unsigned int	path_count = 3;
	int				hops[path_count];
	hops[0] = 7;
	hops[1] = 7;
	hops[2] = 7;
	int				expected_steps = 9;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, three_paths_2)
{
	unsigned int	ant_count = 6;
	unsigned int	path_count = 3;
	int				hops[path_count];
	hops[0] = 7;
	hops[1] = 7;
	hops[2] = 7;
	int				expected_steps = 9;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, three_paths_1)
{
	unsigned int	ant_count = 6;
	unsigned int	path_count = 3;
	int				hops[path_count];
	hops[0] = 7;
	hops[1] = 5;
	hops[2] = 7;
	int				expected_steps = 9;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

////////////////////////////////////////////////////////////////////////////////

Test(get_steps, two_paths_4)
{
	unsigned int	ant_count = 10;
	unsigned int	path_count = 2;
	int				hops[path_count];
	hops[0] = 0;
	hops[1] = 5;
	int				expected_steps = 8;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, two_paths_3)
{
	unsigned int	ant_count = 4;
	unsigned int	path_count = 3;
	int				hops[path_count];
	hops[0] = 7;
	hops[1] = 5;
	hops[2] = 5;
	int				expected_steps = 7;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, two_paths_2)
{
	unsigned int	ant_count = 17;
	unsigned int	path_count = 2;
	int				hops[path_count];
	hops[0] = 5;
	hops[1] = 10;
	int				expected_steps = 16;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, two_paths_1)
{
	unsigned int	ant_count = 10;
	unsigned int	path_count = 2;
	int				hops[path_count];
	hops[0] = 5;
	hops[1] = 10;
	int				expected_steps = 13;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

///////////////////////////////////////////////////////////////////////////////

Test(get_steps, one_path_4)
{
	unsigned int	ant_count = 10;
	unsigned int	path_count = 1;
	int				hops[path_count];
	hops[0] = 20;
	int				expected_steps = 30;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, one_path_3)
{
	unsigned int	ant_count = 10;
	unsigned int	path_count = 2;
	int				hops[path_count];
	hops[0] = 20;
	hops[1] = 5;
	int				expected_steps = 15;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, one_path_2)
{
	unsigned int	ant_count = 10;
	unsigned int	path_count = 2;
	int				hops[path_count];
	hops[0] = 5;
	hops[1] = 20;
	int				expected_steps = 15;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}

Test(get_steps, one_path_1)
{
	unsigned int	ant_count = 10;
	unsigned int	path_count = 1;
	int				hops[path_count];
	hops[0] = 5;
	int				expected_steps = 15;

	t_graph	graph;
	ft_bzero(&graph, sizeof(t_graph));
	cr_assert_eq(load_map(&graph, "tests/maps/valid_path_threshold"), SUCCESS, "graph couldn't be build");
	graph.ant_count = ant_count;
	cr_assert_eq(add_paths(&graph, path_count, hops), SUCCESS, "paths couldn't be loaded");
	int	steps = get_steps(graph.paths, path_count, ant_count);
	cr_assert_eq(steps, expected_steps, "steps calculated: %d, expected: %d\n", steps, expected_steps);
	graph_del(&graph);
}
