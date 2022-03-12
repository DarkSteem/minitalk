/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 17:34:42 by nberen            #+#    #+#             */
/*   Updated: 2021/10/24 18:04:47 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	a;
	size_t	k;
	size_t	m;

	k = 0;
	m = 0;
	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	a = ft_strlen(s2);
	s = malloc(sizeof(char) * (i + a) + 1);
	if (!s)
		return (NULL);
	while (s1[k] != '\0')
		s[m++] = (char)s1[k++];
	k = 0;
	while (s2[k] != '\0')
		s[m++] = (char)s2[k++];
	s[i + a] = '\0';
	return (s);
}
