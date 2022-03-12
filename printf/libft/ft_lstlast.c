/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 19:30:42 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:19:17 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* returns the last element in the list */

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == (NULL))
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
