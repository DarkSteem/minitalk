/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:15:30 by nberen            #+#    #+#             */
/*   Updated: 2021/10/24 17:01:43 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		if (str[i] == c)
			i++;
		else
		{
			k++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
	}
	return (k);
}

static char	*count_letters(const char *str, char c)
{
	int		i;
	char	*letters;

	i = 0;
	while (*str && *str == c)
		str++;
	while (str[i] && str[i] != c)
		i++;
	letters = malloc(sizeof(char) * (i + 1));
	if (letters == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		letters[i] = str[i];
		i++;
	}
	letters[i] = '\0';
	return (letters);
}

static void	free_words(int i, char **str)
{
	while (i > 0)
	{
		free(str[i - 1]);
		i--;
	}
	free(str);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr_words;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	ptr_words = malloc(sizeof(char *) * (words + 1));
	if (ptr_words == NULL)
		return (NULL);
	i = 0;
	while (i < words)
	{
		while (*s && *s == c)
			s++;
		ptr_words[i] = count_letters(s, c);
		if (ptr_words[i] == NULL)
			free_words(i, ptr_words);
		while (*s && *s != c)
			s++;
		i++;
	}
	ptr_words[i] = NULL;
	return (ptr_words);
}
