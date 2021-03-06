/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_launcher_n.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/03 17:06:09 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/04/22 17:44:58 by moana         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** -------------------------------------------------------------------------- **
** launches the n conversion, saves the number of printed bytes in the given
** integer pointer
**
** params
**	va_list			ap		lisaddress for the next argument
**	t_buffer		*buf	addres of the struct holding all info for the buffer
**	t_flags			*flags	address of struct with the flags for current
**							conversion
** return
**	VOID
*/

void	launch_n(va_list ap, t_buffer *buf, t_flags *flags)
{
	int		*n;

	if (flags->conv == 'n')
	{
		n = va_arg(ap, int*);
		*n = buf->count;
	}
}
