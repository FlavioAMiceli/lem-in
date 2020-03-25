/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hmap_new.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 20:03:13 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/09 20:03:13 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

/*
**	params:	number of expected keys, pointer to deletion function for values.
**	return:	Pointer to newly allocated hmap struct.
*/
t_hmap  *hmap_new(int n, void (*del)(void *))
{
	t_hmap	*hmap;

	if (n <= 0 || del == NULL)
		return (NULL);
	hmap = (t_hmap*)ft_memalloc(sizeof(t_hmap));
	if (!hmap)
		return (NULL);
	hmap->slots = (t_slot**)ft_memalloc(sizeof(t_slot*) * ((n * 3) / 2));
	if (!hmap->slots)
	{
		free(hmap);
		return (NULL);
	}
	hmap->del = del;
	hmap->n = (n * 3) / 2;
	return (hmap);
}
