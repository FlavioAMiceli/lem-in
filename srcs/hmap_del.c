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
	int				i;
	t_slot			*slot;

	hash = hmap_hash(key, hmap->n);
	i = hash % hmap->n;
	slot = hmap->slots[i];
	if (!ft_strequ(slot->key, key))
		slot = hmap->slots[hmap_probe(hmap, key, hash)];
	if (ft_strequ(slot->key, key))
	{
		hmap->del(slot->val);
		ft_strdel(&(slot->key));
		ft_memdel(&slot);
	}
}
