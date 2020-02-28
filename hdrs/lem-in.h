/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lem-in.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 14:06:19 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/28 17:44:33 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct	s_room
{
	int				x_coord;
	int				y_coord;
	int				distance;
	int				start_end;
	int				link_count;
	int				*links;
	char			*name;
	struct s_room	*next;
}				t_room;

typedef struct	s_input_line
{
	char				*line;
	struct s_input_line	*next_line;
	struct s_input_line	*next_room;
	struct s_input_line	*next_link;
}				t_input_line;

typedef struct	s_input_info
{
	int				room_count;
	int				ant_no;
	char			*start_room;
	char			*end_room;
	t_input_line	*list;
	t_input_line	*rooms;
	t_input_line	*links;
}				t_input_info;

int		ft_is_int(char *str);
void	ft_strarrdel(char ***arr);
int		read_input(t_input_info *input);
void	free_graph(t_room ***graph);
t_room	*create_room(char **room_info);

#endif
