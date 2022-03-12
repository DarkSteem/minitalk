/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 12:56:39 by nberen            #+#    #+#             */
/*   Updated: 2021/10/25 10:46:23 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* may used for split a string without 'set'
at the begining and at the end */

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*s;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[start]) && s1[start])
		start++;
	while (ft_strchr(set, s1[end]) && end > start)
		end--;
	s = (char *)malloc(end - start + 2);
	if (!s)
		return (NULL);
	while (start <= end)
		s[i++] = s1[start++];
	s[i] = '\0';
	return (s);
}
