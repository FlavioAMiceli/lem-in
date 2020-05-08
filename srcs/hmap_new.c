/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hmap_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 20:03:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/04/10 17:12:16 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include <stdlib.h>

/*
**	params:	number of expected keys, pointer to deletion function for values.
**	return:	Pointer to newly allocated hmap struct.
*/

t_hmap	*hmap_new(int n)
{
	t_hmap	*hmap;

	if (n <= 0)
		return (NULL);
	hmap = (t_hmap*)ft_memalloc(sizeof(t_hmap));
	if (!hmap)
		return (NULL);
	hmap->slots = (t_slot**)ft_memalloc(sizeof(t_slot*) * ((n * 3) / 2));
	if (!(hmap->slots))
	{
		free(hmap);
		return (NULL);
	}
	hmap->n = (n * 3) / 2;
	hmap->len = 0;
	return (hmap);
}
