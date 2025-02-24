/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:54:04 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/22 19:19:17 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_char(char c, pid_t pid)
{
    int bits;

    bits = 0;
     while (bits < 8)
        {
            if (c & (1 << bits))
            {
                if (kill(pid, SIGUSR1) == -1)
                {
                    perror("kill");
                    exit(1);
                }
            }
            else
            {
                if (kill(pid, SIGUSR2) == -1)
                {
                    perror("kill");
                    exit(1);
                }
            }
            bits++;
            usleep(100);
        }
}

int main(int ac, char **av)
{
    char *message;
    int i;
    pid_t pid;

    if (ac != 3)
    {
        printf("usage :%s <pid> <string>\n",*av);
        exit(1);
    }
    message = av[2];
    pid = atoi(av[1]);
    i = 0;
    while (message[i])
    {
        send_char(message[i], pid);
        i++;
    }
    send_char('\0', pid);
}