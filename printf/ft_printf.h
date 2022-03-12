/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nberen <nberen@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 15:08:57 by nberen            #+#    #+#             */
/*   Updated: 2022/01/09 13:10:12 by nberen           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *in, ...);
int		ft_parser(const char *s, va_list ap);
int		ft_identification(const char *s, va_list ap);
int		ft_print_char(char c);
int		ft_print_string(char *s);
int		ft_print_int(long int nbr);
int		ft_print_16(unsigned long int nbr, int c);
int		ft_print_pointer(void *ptr);

#endif
