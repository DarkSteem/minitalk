/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyoda <chyoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 11:55:56 by chyoda            #+#    #+#             */
/*   Updated: 2022/03/12 12:07:06 by chyoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	clear(int *a, int *b, char *c)
{
	if (a)
		*a = 0;
	if (b)
		*b = 0;
	if (c)
		*c = 0;
}

int	receiving(char byte, int num)
{
	return (byte | (1 << num));
}

void	out(int pid, int check, char *buf)
{
	ft_printf("%s", buf);
	if (!check)
		kill(pid, SIGUSR2);
}

void	main_handler(int sig, siginfo_t *info, void *context)
{
	static char	buf[128];
	static char	byte;
	static int	cur_bit;
	static int	len;
	static int	check;

	(void)context;
	if (check != 1 || len == 127)
		clear(&len, &cur_bit, &byte);
	check = 1;
	if (sig == SIGUSR1)
		byte = receiving(byte, cur_bit);
	if (cur_bit++ == 7)
	{
		if (byte == 0)
			check = 0;
		buf[len++] = byte;
		clear(&cur_bit, 0, &byte);
	}
	if (len == 127 || !check)
		out(info->si_pid, check, buf);
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	process;

	process.sa_sigaction = main_handler;
	process.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &process, NULL);
	sigaction(SIGUSR2, &process, NULL);
	ft_printf("Process id: %i\n", getpid());
	while (1)
		pause();
	return (0);
}
