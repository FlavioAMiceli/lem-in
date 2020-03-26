/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hmap_set.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 21:08:55 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/09 21:08:56 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

/*
**	params:	pointer to hmap struct, key and value to store.
**	return:	0 if key didn't exist yet, 1 if value for key was replaced.
**			-1 if hmap is full
*/
int	hmap_set(t_hmap *hmap, char *key, void *value)
{
	unsigned long	hash;
	int				i;

	hash = hmap_hash(key, hmap->n);
	i = hash % hmap->n;
	while (hmap->slots[i] != NULL &&
		!ft_strequ(hmap->slots[i]->key, key) && hmap->len < hmap->n)
	{
		i = ((5 * i) + 1) + hash;
		hash >>= PERTURB_SHIFT;
	}
	if (ft_strequ(hmap->slots[i]->key, key))
	{
		hmap->del(hmap->slots[i]->val);
		hmap->slots[i]->val = value;
		return (1);
	}
	else if (hmap->slots[i] == NULL)
	{
		hmap->slots[i] = (t_slot*)ft_memalloc(sizeof(t_slot));
		hmap->slots[i]->key = ft_strdup(key);
		hmap->slots[i]->val = value;
		hmap->len = hmap->len + 1;
		return (0);
	}
	return (-1);
}
