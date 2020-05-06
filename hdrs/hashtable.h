/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hashtable.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/03 21:33:05 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/03 21:33:06 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASHTABLE_H

# define HASHTABLE_H

# include "../libft/libft.h"

# define PERTURB_SHIFT 5

typedef struct		s_slot
{
	char			*key;
	void			*val;
}					t_slot;

typedef struct		s_hmap
{
	t_slot			**slots;
	void			(*del)(void *);
	unsigned int	len;
	unsigned int	n;
}					t_hmap;

t_hmap			*hmap_new(int max_len, void (*del)(void *));
void			hmap_clear(t_hmap **hmap);

int				hmap_set(t_hmap *hmap, char *key, void *value);
void			*hmap_get(t_hmap *hmap, char *key);
void			hmap_del(t_hmap *hmap, char *key);

unsigned long	hmap_hash(char *key, int n);

#endif
