/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_ft_is_int.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:12:50 by mmarcell       #+#    #+#                */
/*   Updated: 2020/02/27 13:40:36 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <criterion/criterion.h>
#include <criterion/assert.h>
#include "lem-in.h"
#include "libft.h"

Test(ft_is_int, valid_pos)
{
	cr_assert_eq(ft_is_int("245"), 1, "incorrect return for positive number");
}

Test(ft_is_int, valid_neg)
{
	cr_assert_eq(ft_is_int("-245"), 1, "incorrect return for negative number");
}

Test(ft_is_int, valid_null)
{
	cr_assert_eq(ft_is_int("0"), 1, "incorrect return for 0");
}

Test(ft_is_int, valid_plus_null)
{
	cr_assert_eq(ft_is_int("+0"), 1, "incorrect return for 0");
}

Test(ft_is_int, valid_minus_null)
{
	cr_assert_eq(ft_is_int("-0"), 1, "incorrect return for 0");
}

Test(ft_is_int, valid_long_pos)
{
	cr_assert_eq(ft_is_int("+000000000000000000000000000000000000000001650245"), 1, "incorrect return for long positive number");
}

Test(ft_is_int, valid_long_neg)
{
	cr_assert_eq(ft_is_int("-00000000000000000000000000000000000000000075820245"), 1, "incorrect return for long negative number");
}

Test(ft_is_int, valid_int_max)
{
	cr_assert_eq(ft_is_int("2147483647"), 1, "incorrect return for int_max");
}

Test(ft_is_int, valid_int_min)
{
	cr_assert_eq(ft_is_int("-2147483648"), 1, "incorrect return for int_min");
}

Test(ft_is_int, valid_int_max_with_zero)
{
	cr_assert_eq(ft_is_int("00000000000000000000000000002147483647"), 1, "incorrect return for int_max starting with zeros");
}

Test(ft_is_int, valid_int_min_with_zero)
{
	cr_assert_eq(ft_is_int("-00000000000000000000000000002147483648"), 1, "incorrect return for int_min starting with zeros");
}

Test(ft_is_int, invalid_gt_int_max)
{
	cr_assert_eq(ft_is_int("2147483648"), 0, "incorrect return for number greater than int_max");
}

Test(ft_is_int, invalid_st_int_min)
{
	cr_assert_eq(ft_is_int("-2147483649"), 0, "incorrect return for number smaller than int_min");
}

Test(ft_is_int, invalid_gt_int_max2)
{
	cr_assert_eq(ft_is_int("214748364835452"), 0, "incorrect return for number greater than int_max");
}

Test(ft_is_int, invalid_st_int_min2)
{
	cr_assert_eq(ft_is_int("-214748364926262"), 0, "incorrect return for number smaller than int_min");
}

Test(ft_is_int, invalid_non_num_char_beg)
{
	cr_assert_eq(ft_is_int("h432"), 0, "incorrect return for non numerical char in the beginning");
}

Test(ft_is_int, invalid_non_num_char_mid)
{
	cr_assert_eq(ft_is_int("43-2"), 0, "incorrect return for non numerical char in the middle");
}

Test(ft_is_int, invalid_non_num_char_end)
{
	cr_assert_eq(ft_is_int("432 "), 0, "incorrect return for non numerical char in the end");
}

Test(ft_is_int, invalid_double_sign1)
{
	cr_assert_eq(ft_is_int("+-432"), 0, "incorrect return for non numerical char in the beginning");
}

Test(ft_is_int, invalid_double_sign2)
{
	cr_assert_eq(ft_is_int("-+432"), 0, "incorrect return for non numerical char in the beginning");
}

Test(ft_is_int, invalid_double_sign3)
{
	cr_assert_eq(ft_is_int("++432"), 0, "incorrect return for non numerical char in the beginning");
}

Test(ft_is_int, invalid_double_sign4)
{
	cr_assert_eq(ft_is_int("--432"), 0, "incorrect return for non numerical char in the beginning");
}
