/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:08:14 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:42:52 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* compares the chars and outputs the difference */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*src;
	unsigned char	*str;

	i = 0;
	src = (unsigned char *)s1;
	str = (unsigned char *)s2;
	while (i < n)
	{
		if (src[i] != str[i])
			return (src[i] - str[i]);
		if (!src[i] || !str[i])
			return (0);
		i++;
	}
	return (0);
}
