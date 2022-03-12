/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chyoda <chyoda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 11:55:56 by chyoda            #+#    #+#             */
/*   Updated: 2022/03/12 12:07:10 by chyoda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	cont(int sig)
{
	(void)sig;
	usleep(20);
}

void	success(int sig)
{
	(void)sig;
	ft_printf("The message has been sent!\n");
}

void	main_handler(int pid, const char byte)
{
	int	counter;
	int	checker;

	counter = 0;
	checker = 0;
	while (counter < 8)
	{
		if ((byte >> counter) & 1)
			checker = kill(pid, SIGUSR1);
		else
			checker = kill(pid, SIGUSR2);
		if (checker == -1)
		{
			ft_printf("WRONG PID!\n");
			exit(1);
		}
		pause();
		counter++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		ft_printf("You must keybord pid and message.\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, cont);
	signal(SIGUSR2, success);
	while (argv[2][i])
		main_handler(pid, argv[2][i++]);
	main_handler(pid, '\0');
	return (0);
}
