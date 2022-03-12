/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 18:53:08 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:21:57 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Selects using malloc and returns a new
element. The ’content' variable is initialized
with the value of the 'content' parameter.
The ’next' variable is initialized to NULL */

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
