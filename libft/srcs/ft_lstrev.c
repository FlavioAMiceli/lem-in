/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/05/06 09:16:00 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/05/06 09:16:31 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list	*ft_lstrev(t_list **alst)
// {
// 	t_list *curr;

// 	if (!alst || !(*alst))
// 		return (NULL);
// 	curr = ft_lstdequeue(alst);
// 	curr->next = NULL;
// 	while (alst)
// 		ft_lstadd(&curr, ft_lstdequeue(alst));
// 	return (curr);
// }

t_list	*ft_lstrev(t_list **alst)
{
	t_list	*curr;
	t_list	*old_list;
	t_list	*new_head;

	if (alst == NULL || *alst == NULL)
		return (NULL);
	old_list = (*alst);
	new_head = NULL;
	while (old_list != NULL)
	{
		curr = old_list;
		old_list = old_list->next;
		curr->next = NULL;
		ft_lstadd(&new_head, curr);
	}
	return (new_head);
}
