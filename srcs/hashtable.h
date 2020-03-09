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

# include "libft.h"

# define PERTURB_SHIFT 5

typedef struct		s_hmap
{
    t_slot			**slots;
    void			(*del)(void *);
    int				n;
}					t_hmap;

typedef struct		s_slot
{
    char			*key;
	void			*val;
}					t_slot;

t_hmap			*hmap_new(int n, void (*del)(void *));
void			hmap_clear(t_hmap **hmap);


void			hmap_set(t_hmap *hmap, char *key, void *value);
void			*hmap_get(t_hmap *hmap, char *key);
void			hmap_del(t_hmap *hmap, char *key);

unsigned long	hmap_hash(char *key);
int     		hmap_probe(t_dict *hmap, char *key, unsigned long hash);

#endif
