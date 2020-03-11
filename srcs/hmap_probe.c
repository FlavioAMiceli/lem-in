/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hmap_probe.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 21:53:09 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/09 21:53:09 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

/*
**	params: pointer to hmap, key to find, original hash to key.
**	return: Index where the key was found.
*/
int	hmap_probe(t_dict *hmap, char *key, unsigned long hash)
{
	unsigned long	i;
	unsigned long	perturb;

	perturb = hash;
	i = hash % hmap->n;
	i = ((5 * i) + 1) + perturb;
	while (!ft_strequ(hmap->slots[i % hmap->n]->key, key))
	{
		perturb >>= PERTURB_SHIFT;
		i = ((5 * i) + 1) + perturb;
	}
	return (i % hmap->n);
}
