/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:06:19 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/04 18:19:04 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "hashtable.h"

# define SCORE content_size

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
	int				hops;
	int				visited;
	int				used;
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

typedef struct	s_path
{
	unsigned int	threshold;
	t_vert			*start;
}				t_path;

typedef struct	s_graph
{
	unsigned int	ant_count;
	unsigned int	vert_count;
	unsigned int	path_count;
	t_vert			*vert_list;
	t_edge			*edge_list;
	t_hmap			*vertices;
	t_vert			*source;
	t_vert			*sink;
	t_path			**paths;
}				t_graph;

typedef struct	s_ant
{
	char			*name;
	t_vert			*current_vert;
	struct s_ant	*next;
}				t_ant;

typedef struct	s_ant_list
{
	t_ant			*first_ant;
	t_ant			*last_ant;
}				t_ant_list;

int				strdel_and_return(int ret, char **str);
int				strarrdel_and_return(int ret, char ***strarr);
int				strarrdel_edgedel_and_return(int ret, char ***strarr,
				t_edge **edge);
int				free_graph_input_and_return(int ret, t_graph *graph,
				t_input_info *input);
int				graph_del_and_return(int ret, t_graph *graph);

int				graph_new(t_graph *graph, t_input_info *input);
int				edge_new(char **input_line, t_graph *graph);

int				ft_isint(char *str);
void			ft_strarrdel(char ***arr);

int				strdel_and_return(int ret, char **str);
int				strarrdel_and_return(int ret, char ***strarr);
int				strarrdel_edgedel_and_return(
					int ret, char ***strarr, t_edge **edge);
int				free_graph_input_and_return(int ret, t_graph *graph,
				t_input_info *input);

void			graph_del(t_graph *graph);
void			vert_del(t_vert **vert);
void			edge_del(t_edge **edge);
void			path_del(t_graph *graph);

void			input_del(t_input_info *input);
int				input_read(t_input_info *input);
t_input_line	*input_line_add(t_input_info *input, char *line);

void			distance_set(t_graph *graph, t_vert *vert, t_vert *prev_vert);
int				path_new(t_graph *graph, t_vert *new_start);

unsigned int	threshold(t_path **paths, unsigned int idx,
				unsigned int placeholder);
void			set_thresholds(t_path **paths, unsigned int path_count);

int				keep_searching(t_graph *graph, t_vert *new_start);

void			edmonds_karp(t_graph *graph);
t_list			*a_star(t_vert *source, t_vert *sink);
t_list			*a_star_dequeue(t_list **queue);
void			a_star_clear_queue(t_list **queue);

void			init_queue(t_list **queue, t_vert *source);
void			insert_into_queue(t_list **queue, t_list *path);

void			rooms_used_to_false(t_vert *rooms);
int				evaluate(t_list *path);
void			free_path(t_list **path);
t_list			*copy_path(t_list *src);

void			update_visited_status(t_list *path);
void			update_flow(t_graph *graph, t_list *path);
void			revert_flow(t_graph *graph, t_list *path);
void			update_hops(t_vert *s, int hop);

#endif
