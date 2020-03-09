/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hmap_clear.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 20:18:54 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/09 20:18:54 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

/*
**	params:	addr of hmap pointer
**	return:
*/
void	hmap_clear(t_hmap **hmap)
{
	int		i;
	t_hmap	mp;

	i = 0;
	mp = *hmap;
	while (i < mp->n)
	{
		mp->del(mp->slots[i]->val);
		ft_strdel(&(mp->slots[i]->key));
		ft_memdel(&(mp->slots[i]));
		i++;
	}
	mp->slots = NULL;
	mp->del = NULL;
	mp->n = 0;
	ft_memdel(hmap);
}
