/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_hashtable.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/12 20:10:09 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/07/04 12:51:48 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "hashtable.h"

Test(hashtable, new)
{
	t_hmap	*hmap;

	hmap = hmap_new(100);
	cr_expect(hmap, "hmap_new did not return an adress.");
	cr_expect_eq(hmap->n, 150, "hmap->n is not 3/2 times the input size. Is %d and shoudl be %d", hmap->n, 150);
}

Test(hashtable, set_and_get)
{
	t_hmap	*hmap;
	int		*i;
	int		r;

	hmap = hmap_new(100);
	i = (int*)ft_memalloc(sizeof(int*));
	*i = 5;
	r = hmap_set(hmap, "Some key", i);
	i = hmap_get(hmap, "Some key");
	cr_expect_eq(*i, 5, "incorrect value, it is %d and it should be %d", *i, 5);
	cr_expect_eq(r, 0, "incorrect return value, it is %d and it should be %d", r, 0);
}

Test(hashtable, set_overwrite)
{
	t_hmap	*hmap;
	int		*i;
	int		*j;
	int		r;

	hmap = hmap_new(100);
	i = (int*)ft_memalloc(sizeof(int*));
	*i = 5;
	r = hmap_set(hmap, "Some key", i);
	cr_expect_eq(r, 0, "incorrect return value, it is %d and it should be %d", r, 0);
	j = (int*)ft_memalloc(sizeof(int*));
	*j = 7;
	r = hmap_set(hmap, "Some key", j);
	// cr_expect_eq(i, 0, "Original value was not safely freed");
	i = hmap_get(hmap, "Some key");
	cr_expect_eq(*i, 7, "incorrect value, it is %d and it should be %d", *i, 7);
}

Test(hashtable, set_on_full_hmap)
{
	t_hmap	*hmap;
	int		*i;
	int		r;

	hmap = hmap_new(1);
	i = (int*)ft_memalloc(sizeof(int*));
	*i = 5;
	r = hmap_set(hmap, "Some key", i);
	cr_expect_eq(r, 0, "incorrect return value, it is %d and it should be %d", r, 0);
	// r = hmap_set(hmap, "Some other key", i);
	// cr_expect_eq(r, 0, "incorrect return value, it is %d and it should be %d", r, 0);
	r = hmap_set(hmap, "Yet some other key", i);
	cr_expect_eq(r, -1, "incorrect return value, it is %d and it should be %d", r, -1);
}

Test(hashtable, set_and_overwrite)
{
	t_hmap	*hmap;
	int		*i;
	int		*j;

	hmap = hmap_new(100);
	i = (int*)ft_memalloc(sizeof(int*));
	j = (int*)ft_memalloc(sizeof(int*));
	*i = 5;
	hmap_set(hmap, "Some key", i);
	*j = 42;
	hmap_set(hmap, "Some key", j);
	j = hmap_get(hmap, "Some key");
	cr_expect_eq(*j, 42, "incorrect value, it is %d and it should be %d", *j, 42);
	// cr_expect_eq(i, NULL, "Originally stored value not freed properly");
}

// Test(hashtable, clear)
// {
// 	t_hmap	*hmap;
// 	char	*tmp;
// 	char	*itoa;
// 	char	*str;
// 	int		i;

// 	hmap = hmap_new(100);
// 	i = 0;
// 	while (i < 100)
// 	{
// 		if (tmp)
// 			ft_strdel(&tmp);
// 		if (itoa)
// 			ft_strdel(&itoa);
// 		if (str)
// 			ft_strdel(&str);
// 		tmp = ft_strdup("This is the string for key: ");
// 		itoa = ft_itoa(i);
// 		str = ft_strjoin(tmp, ft_itoa(i));
// 		hmap_set(hmap, itoa, ft_strdup(str));
// 	}
// 	i = 0;
// 	while (i < 100)
// 	{
// 		if (itoa)
// 			ft_strdel(&itoa);
// 		if (str)
// 			ft_strdel(&str);
// 		itoa = ft_itoa(i);
// 		str = hmap_get(hmap, itoa);
// 		cr_expect_eq(str, itoa, "string for %d is incorrect", i);
// 	}
// }
