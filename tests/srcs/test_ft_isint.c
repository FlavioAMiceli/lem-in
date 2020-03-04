/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_isint.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:12:50 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/04 14:56:45 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "lem_in.h"
#include "libft.h"

Test(ft_isint, valid_pos)
{
	cr_assert_eq(ft_isint("245"), 1, "incorrect return for positive number");
}

Test(ft_isint, valid_neg)
{
	cr_assert_eq(ft_isint("-245"), 1, "incorrect return for negative number");
}

Test(ft_isint, valid_null)
{
	cr_assert_eq(ft_isint("0"), 1, "incorrect return for 0");
}

Test(ft_isint, valid_plus_null)
{
	cr_assert_eq(ft_isint("+0"), 1, "incorrect return for 0");
}

Test(ft_isint, valid_minus_null)
{
	cr_assert_eq(ft_isint("-0"), 1, "incorrect return for 0");
}

Test(ft_isint, valid_long_pos)
{
	cr_assert_eq(ft_isint("+000000000000000000000000000000000000000001650245"), 1, "incorrect return for long positive number");
}

Test(ft_isint, valid_long_neg)
{
	cr_assert_eq(ft_isint("-00000000000000000000000000000000000000000075820245"), 1, "incorrect return for long negative number");
}

Test(ft_isint, valid_int_max)
{
	cr_assert_eq(ft_isint("2147483647"), 1, "incorrect return for int_max");
}

Test(ft_isint, valid_int_min)
{
	cr_assert_eq(ft_isint("-2147483648"), 1, "incorrect return for int_min");
}

Test(ft_isint, valid_int_max_with_zero)
{
	cr_assert_eq(ft_isint("00000000000000000000000000002147483647"), 1, "incorrect return for int_max starting with zeros");
}

Test(ft_isint, valid_int_min_with_zero)
{
	cr_assert_eq(ft_isint("-00000000000000000000000000002147483648"), 1, "incorrect return for int_min starting with zeros");
}

Test(ft_isint, invalid_gt_int_max)
{
	cr_assert_eq(ft_isint("2147483648"), 0, "incorrect return for number greater than int_max");
}

Test(ft_isint, invalid_st_int_min)
{
	cr_assert_eq(ft_isint("-2147483649"), 0, "incorrect return for number smaller than int_min");
}

Test(ft_isint, invalid_gt_int_max_with_zero)
{
	cr_assert_eq(ft_isint("0000000002147483648"), 0, "incorrect return for number greater than int_max");
}

Test(ft_isint, invalid_st_int_min_with_zero)
{
	cr_assert_eq(ft_isint("-0000000000002147483649"), 0, "incorrect return for number smaller than int_min");
}

Test(ft_isint, invalid_gt_int_max2)
{
	cr_assert_eq(ft_isint("214748364835452"), 0, "incorrect return for number greater than int_max");
}

Test(ft_isint, invalid_st_int_min2)
{
	cr_assert_eq(ft_isint("-214748364926262"), 0, "incorrect return for number smaller than int_min");
}

Test(ft_isint, invalid_non_num_char_beg)
{
	cr_assert_eq(ft_isint("h432"), 0, "incorrect return for non numerical char in the beginning");
}

Test(ft_isint, invalid_non_num_char_mid)
{
	cr_assert_eq(ft_isint("43-2"), 0, "incorrect return for non numerical char in the middle");
}

Test(ft_isint, invalid_non_num_char_end)
{
	cr_assert_eq(ft_isint("432 "), 0, "incorrect return for non numerical char in the end");
}

Test(ft_isint, invalid_double_sign1)
{
	cr_assert_eq(ft_isint("+-432"), 0, "incorrect return for double sign char in the beginning");
}

Test(ft_isint, invalid_double_sign2)
{
	cr_assert_eq(ft_isint("-+432"), 0, "incorrect return for double sign char in the beginning");
}

Test(ft_isint, invalid_double_sign3)
{
	cr_assert_eq(ft_isint("++432"), 0, "incorrect return for double sign char in the beginning");
}

Test(ft_isint, invalid_double_sign4)
{
	cr_assert_eq(ft_isint("--432"), 0, "incorrect return for double sign char in the beginning");
}

Test(ft_isint, invalid_empty)
{
	cr_assert_eq(ft_isint(""), 0, "incorrect return for empty input");
}
