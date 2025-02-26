/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:54:04 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/26 14:52:48 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"
#include "../printf/includes/ft_printf.h"

int send_char(int pid, unsigned int num, int t)
{
    int a;

    if (t == 0)
    {
        if (num % 2)
            a = kill(pid, SIGUSR2);
        else
            a = kill(pid, SIGUSR1);
        usleep(1000);
        if (a == -1)
        {
            ft_printf("Error: Signal sending failed\n");
            return (-1);
        }
        return (a);
    }
    if (send_char(pid, num / 2, t -1) == -1)
        return (-1);
    if (num % 2)
        a = kill(pid, SIGUSR2);
    else
        a = kill(pid, SIGUSR1);
    usleep(1000);
    if (a == -1)
    {
        ft_printf("Error: Signal sending falied\n");
        return (-1);
    }
    return (0);
}

int push_kill(pid_t pid, unsigned char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (send_char(pid, (unsigned int)str[i], 7) == -1)
            return (1);
        i++;
    }
    send_char(pid, '\0', 7);
    return (0);
}

int check_pid(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if(!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}

void handl(int sig)
{
    (void)sig;
    ft_printf("Success\n");
}

int main(int ac, char *av[])
{
    int num;
    struct sigaction sigl;

    if (ac != 3 || !check_pid(av[1]))
    {
        ft_printf("Error: Please confirm PID\n");
        exit(1);
    }
    sigemptyset(&sigl.sa_mask);
    sigl.sa_handler = handl;
    sigl.sa_flags = 0;
    sigaction(SIGUSR1, &sigl, NULL);
    num = ft_atoi(av[1]);
    if (push_kill(num, (unsigned char *)av[2]) == -1)
    {
        ft_printf("Error: Check PID");
        exit(1);
    }
    if (usleep(1000) == -1)
    {
        ft_printf("Error: Some signals are missing\n");
        exit(1);
    }
}