/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:35:12 by nberen            #+#    #+#             */
/*   Updated: 2022/01/09 13:09:58 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c)
{
	return (write(1, &c, 1));
}

int	ft_print_string(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		write (1, &s[i++], 1);
	return (i);
}

int	ft_print_int(long int nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		i += ft_print_char('-');
		nbr *= -1;
	}
	if (nbr > 9)
		i += ft_print_int(nbr / 10);
	i += ft_print_char(nbr % 10 + '0');
	return (i);
}

int	ft_print_16(unsigned long int nbr, int c)
{
	int		i;
	char	*k;

	i = 0;
	k = "0123456789abcdef";
	if (c == 'X')
		k = "0123456789ABCDEF";
	if (nbr > 15)
		i += ft_print_16(nbr / 16, c);
	i += ft_print_char(k[nbr % 16]);
	return (i);
}

int	ft_print_pointer(void *ptr)
{
	size_t	nbr;
	int		i;
	char	*c;

	if (!ptr)
		return (ft_print_string("0x0"));
	nbr = (size_t)ptr;
	i = 0;
	i += ft_print_string("0x");
	c = "0123456789abcdef";
	i += ft_print_16(nbr, 'x');
	return (i);
}
