/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:53:04 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:20:12 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Repeats the ’lst' list and applies
the 'f' function to the contents of each element.
Creates a new list resulting from successive applications
of the ’f' function. The 'del' function is used to
delete the contents of the element, if necessary */

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_elem;

	if (f == NULL)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_elem = ft_lstnew(f(lst->content));
		if (new_elem == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_elem);
		lst = lst->next;
	}
	return (new_list);
}
