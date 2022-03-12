/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:08:07 by nberen            #+#    #+#             */
/*   Updated: 2022/01/09 13:09:59 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_identification(const char *s, va_list ap)
{
	int	i;

	i = 0;
	if (*s == 'c')
		i += ft_print_char(va_arg(ap, int));
	else if (*s == 's')
		i += ft_print_string(va_arg(ap, char *));
	else if (*s == 'd' || *s == 'i')
		i += ft_print_int(va_arg(ap, int));
	else if (*s == 'u')
		i += ft_print_int(va_arg(ap, unsigned int));
	else if (*s == 'x' || *s == 'X')
		i += ft_print_16(va_arg(ap, unsigned int), *s);
	else if (*s == 'p')
		i += ft_print_pointer(va_arg(ap, void *));
	else if (*s == '%')
		i += ft_print_char('%');
	else if (*s == ' ')
		i = 0;
	else
		i += ft_print_char(*(s + 1));
	return (i);
}

int	ft_parser(const char *s, va_list ap)
{
	int	i;

	i = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			i += ft_identification(s, ap);
		}
		else
		{
			ft_print_char(*s);
			i++;
		}
		s++;
	}
	return (i);
}

int	ft_printf(const char *in, ...)
{
	va_list	ap;
	int		i;

	va_start(ap, in);
	i = ft_parser(in, ap);
	va_end(ap);
	return (i);
}
