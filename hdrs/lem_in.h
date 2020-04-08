/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:06:19 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/04/07 19:04:53 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "hashtable.h"

# define TRUE 1
# define FALSE 0
# define OK 1
# define ERROR 0

typedef struct	s_input_line
{
	struct s_input_line	*next_line;
	struct s_input_line	*next_room;
	struct s_input_line	*next_link;
	char				*line;
	char				*room_name;
}				t_input_line;

typedef struct	s_input_info
{
	int				ant_no;
	int				room_count;
	int				link_count;
	t_input_line	*start;
	t_input_line	*end;
	t_input_line	*list;
	t_input_line	*last_line;
	t_input_line	*rooms;
	t_input_line	*links;
}				t_input_info;

typedef struct	s_vert
{
	int				x_coord;
	int				y_coord;
	int				distance;
	int				visited;
	int				conn_count;
	struct s_edge	*connections;
	struct s_vert	*next_vert;
	char			*name;
}				t_vert;

typedef struct	s_edge
{
	int				flow;
	t_vert			*tail;
	t_vert			*head;
	struct s_edge	*invert;
	struct s_edge	*next_edge;
	struct s_edge	*next_conn;
}				t_edge;

typedef struct	s_graph
{
	int				ant_count;
	int				vert_count;
	t_vert			*vert_list;
	t_edge			*edge_list;
	t_hmap			*vertices;
	t_vert			*source;
	t_vert			*sink;
}				t_graph;

int				ft_isint(char *str);
void			ft_strarrdel(char ***arr);

int				strdel_and_return(int ret, char **str);
int				strarrdel_and_return(int ret, char ***strarr);
int				strarrdel_edgedel_and_return(int ret, char ***strarr, t_edge **edge);
int				free_graph_input_and_return(int ret, t_graph *graph,
				t_input_info *input);

int				graph_set(t_graph *graph, t_input_info *input);

void			graph_del(t_graph *graph);
void			vert_del(t_vert **vert);
void			edge_del(t_edge **edge);

void			input_del(t_input_info *input);
int				input_read(t_input_info *input);
t_input_line	*input_line_add(t_input_info *input, char *line);

int				distance_set(t_graph *graph, t_vert *vert, int prev_distance);

#endif
