/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 09:24:52 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:17:04 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* clean only one elemen of the list */

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst->content);
		free(lst);
	}
}
