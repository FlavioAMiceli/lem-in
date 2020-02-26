/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_isnumber.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:12:50 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/26 18:46:46 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "libft.h"

Test(ft_is_int, valid_pos)
{
	cr_assert_eq(ft_is_int("245", 1, "incorrect return for positive number"));
}

Test(ft_is_int, valid_neg)
{
	cr_assert_eq(ft_is_int("-245", 1, "incorrect return for negative number"));
}

Test(ft_is_int, valid_null)
{
	cr_assert_eq(ft_is_int("0", 1, "incorrect return for 0"));
}

Test(ft_is_int, valid_+null)
{
	cr_assert_eq(ft_is_int("+0", 1, "incorrect return for 0"));
}

Test(ft_is_int, valid_-null)
{
	cr_assert_eq(ft_is_int("-0", 1, "incorrect return for 0"));
}

Test(ft_is_int, valid_long_pos)
{
	cr_assert_eq(ft_is_int("+000000000000000000000000000000000000000001650245", 1, "incorrect return for long positive number"));
}

Test(ft_is_int, valid_long_neg)
{
	cr_assert_eq(ft_is_int("-00000000000000000000000000000000000000000075820245", 1, "incorrect return for long negative number"));
}
