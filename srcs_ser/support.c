/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:12:42 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/26 13:46:51 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

extern t_sigl sigl;

void	handler_sigusr1(int sig, siginfo_t *si, void *unused)
{
	(void)sig;
	(void)unused;
	sigl.ans = sigl.ans * 2;
	sigl.pid = si->si_pid;
}

void	handler_sigusr2(int sig, siginfo_t *si, void *unused)
{
	(void)si;
	(void)unused;
	(void)sig;
	sigl.ans = sigl.ans * 2 + 1;
}

void	set_act(void)
{
	struct sigaction	sig1;
	struct sigaction	sig2;

	sigemptyset(&sig1.sa_mask);
	sig1.sa_sigaction = handler_sigusr1;
	sig1.sa_flags = SA_SIGINFO;
	sigemptyset(&sig2.sa_mask);
	sig2.sa_sigaction = handler_sigusr2;
	sig2.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sig1, NULL);
	sigaction(SIGUSR2, &sig2, NULL);
}

void get_byte(void)
{
    int n;

    n = 0;
    sigl.ans = 0;
    while (n < 8)
    {
        pause();
        sigl.ch = 1;
        sigl.ch2 = 1;
        n++;
    }
}

int ccal(void)
{
    get_byte();
	if (sigl.ans == 0)
		return (-1);
	if (sigl.ans < 192)
		byte1();
	else if (sigl.ans < 224)
		byte2();
	else if (sigl.ans < 240)
		byte3();
	else
		byte4();
    return (0);
}