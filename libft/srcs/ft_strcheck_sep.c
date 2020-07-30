/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcheck_sep.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 11:12:10 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/07/30 13:03:25 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcheck_sep(char *str, char sep)
{
	unsigned int	i;
	unsigned int	len;

	if (str == NULL)
		return (SUCCESS);
	len = ft_strlen(str);
	if (str[0] == sep || (len > 0 && str[len - 1] == sep))
		return (ERROR);
	i = 0;
	if (len < 2)
		return (SUCCESS);
	while (i < len - 2)
	{
		if (str[i] == sep && str[i + 1] == sep)
			return (ERROR);
		++i;
	}
	return (SUCCESS);
}
