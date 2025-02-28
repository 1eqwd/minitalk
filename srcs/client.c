/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:24:32 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/28 11:03:11 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

volatile sig_atomic_t	g_flag;

void	handler(int signum)
{
	if (signum == SIGUSR1)
		g_flag = 1;
	else if (signum == SIGUSR2)
		g_flag = -1;
}

void	send_bit(pid_t pid, int bit)
{
	int	sig;
	int	usleep_count;

	if (bit == 0)
		sig = SIGUSR1;
	else
		sig = SIGUSR2;
	g_flag = 0;
	usleep_count = 0;
	kill(pid, sig);
	while (g_flag == 0)
	{
		if (usleep(100) == 0)
		{
			if (kill(pid, 0) == -1)
				proc_err(ERR_SERVER_TERMINATED);
			if (++usleep_count >= 10000)
				proc_err(ERR_CLIENT_RESP_TIMEOUT);
		}
	}
}

void	send_char(pid_t pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = c >> i;
		bit = bit & 1;
		send_bit(pid, bit);
		i--;
	}
}

void	proc_send(pid_t pid, char *meg)
{
	int	i;

	i = 0;
	while (meg[i])
	{
		send_char(pid, meg[i]);
		i++;
	}
	send_char(pid, '\0');
}

int	main(int ac, char *av[])
{
	struct sigaction	sa;
	pid_t				pid;

	if (ac != 3)
		proc_err((ERR_ARGC));
	pid = ft_atoi(av[1]);
	if (pid <= 1 || kill(pid, 0) == -1)
		proc_err(ERR_SERVER_PID);
	ft_memset(&sa, 0, sizeof(struct sigaction));
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	proc_send(pid, av[2]);
	return (0);
}
