/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 13:16:11 by nberen            #+#    #+#             */
/*   Updated: 2021/10/24 13:24:41 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs(int num)
{
	if (num <= 0)
		num = -num;
	return (num);
}

static int	ft_count(int count)
{
	size_t	len;

	len = 0;
	if (count <= 0)
		len++;
	while (count != 0)
	{
		count /= 10;
		len++;
	}
	return (len);
}

static void	ft_rev(char *str)
{
	int		i;
	int		len;
	char	src;

	i = 0;
	len = ft_strlen(str);
	while (i < len / 2)
	{
		src = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = src;
		i++;
	}	
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	int		sign;
	size_t	i;

	sign = 1;
	i = 0;
	len = ft_count(n);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		sign *= -1;
	if (n == 0)
		str[0] = '0';
	while (n != 0)
	{
		str[i++] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (sign == -1)
		str[i] = '-';
	ft_rev(str);
	return (str);
}
