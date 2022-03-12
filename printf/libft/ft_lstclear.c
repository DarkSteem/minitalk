/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:29:20 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:16:20 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* we clean each element of the list using
the 'del' function and 'free' clean */

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*elem;
	t_list	*elem_emp;

	if (lst != NULL)
	{
		elem = *lst;
		while (elem != NULL)
		{
			del(elem -> content);
			elem_emp = elem;
			elem = elem -> next;
			free(elem_emp);
		}
		*lst = NULL;
	}
}
