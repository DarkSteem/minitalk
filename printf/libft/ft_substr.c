/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:52:08 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:48:53 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Returns a substring of the 'string' string
starting with the 'start' character by count
and the length of the 'length' characters */

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s0;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	if (j < len)
		len = j;
	s0 = malloc(len + 1);
	if (start > j)
		len = 0;
	if (!s0)
		return (NULL);
	while (i < len && s[start + i])
	{
		s0[i] = s[start + i];
		i++;
	}
	s0[i] = '\0';
	return (s0);
}
