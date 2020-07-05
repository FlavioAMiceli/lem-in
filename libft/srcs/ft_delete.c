/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_delete.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mmarcell <mmarcell@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/09 17:23:15 by mmarcell      #+#    #+#                 */
/*   Updated: 2020/06/09 17:28:55 by mmarcell      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void		ft_delete(void *ptr, size_t size)
{
	ft_bzero(ptr, size);
	free(ptr);
}
