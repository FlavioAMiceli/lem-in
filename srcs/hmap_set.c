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
**	return:
*/
void	hmap_set(t_hmap *hmap, char *key, void *value)
{
	unsigned long	hash;
	unsigned int	checked;
	int				i;

	hash = hmap_hash(key, hmap->n);
	i = hash % hmap->n;
	checked = 0;
	while (hmap->slots[i] != NULL &&
		!ft_strequ(hmap->slots[i]->key, key) && checked <= hmap->n)
	{
		i = ((5 * i) + 1) + hash;
		hash >>= PERTURB_SHIFT;
		if (hash == 0)
			checked++;
	}
	if (ft_strequ(hmap->slots[i]->key, key))
		hmap->del(hmap->slots[i]->val);
	else if (hmap->slots[i] == NULL)
	{
		hmap->slots[i] = (t_slot*)ft_memalloc(sizeof(t_slot));
		hmap->slots[i]->key = ft_strdup(key);
	}
	else
		return ;
	hmap->slots[i]->val = value;
}
