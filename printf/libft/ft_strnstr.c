/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 13:10:38 by nberen            #+#    #+#             */
/*   Updated: 2021/10/24 18:23:46 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* searches for the same character,
if one line is empty or does not find
a similar character, it returns 0 */

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (!needle[0])
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] && needle[j] && \
				i + j < len && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char *)haystack + i);
		i++;
		j = 0;
	}
	return (0);
}
