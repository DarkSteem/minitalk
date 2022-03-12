/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:47:23 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:18:03 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* going through the list applies
the function 'f' to each element */

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*element;

	element = lst;
	if (!lst)
		return ;
	if (element->next)
		ft_lstiter(lst->next, f);
	f(lst->content);
}
