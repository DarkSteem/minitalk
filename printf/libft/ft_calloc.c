/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:08:55 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:23:40 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* allocates a block of memory for an array of size
count elements, each of which occupies
a size byte, and initializes all its bits to zeros */

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char *)malloc(size * count);
	if (result == NULL)
		return (NULL);
	while (i < count * size)
	{
		result[i] = 0;
		i++;
	}
	return (result);
}
