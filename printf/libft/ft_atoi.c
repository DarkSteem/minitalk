/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 15:44:21 by nberen            #+#    #+#             */
/*   Updated: 2021/10/24 13:24:32 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char str)
{
	if ((str == '\f') || (str == '\n') || (str == '\r') || \
	(str == '\t') || (str == '\v') || (str == ' '))
		return (1);
	return (0);
}

static int	ft_digit(char str)
{
	if (str >= '0' && str <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	num;
	int					count;

	sign = 1;
	num = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str == '0')
		str++;
	count = 0;
	while (ft_digit(*str))
	{
		if (count > 18 && sign == -1)
			return (0);
		if (count++ > 18)
			return (-1);
		num = (num * 10) + (*str - 48);
		str++;
	}
	return (num * sign);
}
