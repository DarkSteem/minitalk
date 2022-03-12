/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:09:27 by nberen            #+#    #+#             */
/*   Updated: 2021/10/24 13:08:15 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	if (!s && !n)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
