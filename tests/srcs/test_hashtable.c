/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_hashtable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 20:10:09 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/03/12 20:10:14 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "hashtable.h"

Test(hashtable, new)
{
	t_hmap	*hmap;

	hmap = hmap_new(100, free);
	cr_expect(hmap, "hmap_new did not return an adress.");
	cr_expect_eq(hmap->del, ft_memdel, "hmap->del does not point to free function");
	cr_expect_eq(hmap->n, 150, "hmap->n is not 3/2 times the input size. Is %d and shoudl be %d");
}

Test(hashtable, set_and_get)
{
	t_hmap	*hmap;
	int		*i;

	hmap = hmap_new(100, free);
	i = (int*)ft_memalloc(sizeof(int*));
	*i = 5;
	hmap_set(hmap, "Some key", i);
	i = hmap_get(hmap, "Some key");
	cr_expect_eq(*i, 5, "incorrect value, it is %d and it should be %d", i, 5);
}

Test(hashtable, set_and_overwrite)
{
	t_hmap	*hmap;
	int		*i;
	int		*j;

	hmap = hmap_new(100, ft_memdel);
	i = (int*)ft_memalloc(sizeof(int*));
	j = (int*)ft_memalloc(sizeof(int*));
	*i = 5;
	hmap_set(hmap, "Some key", i);
	*j = 42;
	hmap_set(hmap, "Some key", j);
	j = hmap_get(hmap, "Some key");
	cr_expect_eq(*j, 42, "incorrect value, it is %d and it should be %d", i, 42);
	cr_expect_eq(i, NULL, "Originally stored value not freed properly");
}

Test(hashtable, clear)
{
	t_hmap	*hmap;
	char	*tmp;
	char	*itoa;
	char	*str;
	int		i;

	hmap = hmap_new(100, ft_strdel);
	i = 0;
	while (i < 100)
	{
		if (tmp)
			ft_memdel(&tmp);
		if (itoa)
			ft_memdel(&itoa);
		if (str)
			ft_memdel(&str);
		tmp = ft_strdup("This is the string for key: ");
		itoa = ft_itoa(i);
		str = ft_strjoin(tmp, ft_itoa(i));
		hmap_set(hmap, itoa, ft_memdup(str));
	}
	i = 0;
	while (i < 100)
	{
		if (itoa)
			ft_memdel(&itoa);
		if (str)
			ft_memdel(&str);
		itoa = ft_itoa(i);
		str = hmap_get(hmap, itoa);
		cr_expect_eq(str, "This is the string for key: %d", i);
	}
}
