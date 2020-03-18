/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isint.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/26 18:03:46 by mmarcell       #+#    #+#                */
/*   Updated: 2020/03/04 14:59:39 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isint(char *str)
{
	int				idx;
	long int		nbr;
	unsigned int	count_zero;

	if (str == 0 || str[0] == 0)
		return (0);
	idx = 0;
	while (str[idx] != 0)
	{
		if (!(ft_isdigit(str[idx]) ||
			((str[idx] == '-' || str[idx] == '+') && ft_isdigit(str[idx + 1]) &&
			idx == 0)))
			return (0);
		++idx;
	}
	count_zero = (str[0] == '-' || str[0] == '+');
	while (str[count_zero] == '0')
		++count_zero;
	if (idx - count_zero > 11)
		return (0);
	nbr = ft_atoi(str);
	return (-2147483648 <= nbr && nbr <= 2147483647);
}
