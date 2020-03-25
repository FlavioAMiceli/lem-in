/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hmap_del.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 21:26:51 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/09 21:26:51 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

/*
**	params:	pointer to hmap struct, key of slot to remove.
**	return:
*/
void    hmap_del(t_hmap *hmap, char *key)
{
	unsigned long	hash;
	unsigned int	checked;
	int				i;
	t_slot			*slot;

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
	slot = hmap->slots[i];
	if (ft_strequ(slot->key, key))
	{
		hmap->del(slot->val);
		ft_strdel(&(slot->key));
		free(slot);
		hmap->slots[i] = NULL;
	}
}
