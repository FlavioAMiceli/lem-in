/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem_in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:06:19 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/24 16:26:00 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# define TRUE 1
# define FALSE 0
# define OK 1
# define ERROR 0

typedef struct	s_room
{
	int				x_coord;
	int				y_coord;
	int				distance;
	int				link_count;
	struct s_room	*links;
	char			*name;
}				t_room;

typedef struct	s_link
{
	t_room	*src;
	t_room	*dst;
	int		flow;
}				t_link;

typedef struct	s_graph
{
	int		ant_count;
	int		room_count;
	int		link_count;
	t_room	**rooms;
	char	*source;
	char	*sink;
}				t_graph;

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

int				ft_isint(char *str);
void			ft_strarrdel(char ***arr);
int				strdel_and_return(int ret, char **str);
int				strarrdel_and_return(int ret, char ***strarr);
void			free_graph(t_graph *graph);
void			free_input(t_input_info *input);
int				free_graph_input_and_return(int ret, t_graph *graph,
				t_input_info *input);
int				read_input(t_input_info *input);
t_input_line	*add_input_line(t_input_info *input, char *line);
t_room			*create_room(char **room_info);

#endif
