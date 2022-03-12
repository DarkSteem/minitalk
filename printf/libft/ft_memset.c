/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:09:57 by nberen            #+#    #+#             */
/*   Updated: 2021/10/21 16:34:49 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Fills the first len bytes of the memory
area pointed to by argument b with the character whose
code is indicated by argument c */

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = (unsigned char)c;
		i++;
	}
	return (b);
}
