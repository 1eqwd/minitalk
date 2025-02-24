/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:54:08 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/22 19:19:58 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// struct sigaction 
//{
//     void     (*sa_handler)(int); // シグナルを受信した時に実行される関数を指定する
//     void     (*sa_sigaction)(int, siginfo_t *, void *); // sa_flagsにSA_SIGINFOが入っているときに使用され、シグナル番号、シグナルに関する追加情報を含む
//     sigset_t   sa_mask; // シグナルハンドラが実行中に他のシグナルが割り込まないようにするために使用されている
//     int        sa_flags; // シグナルハンドラの動作を制御するフラグ
//     void     (*sa_restorer)(void); // 今はあんま使われてないらしい
// };

void signal_handler(int signal)
{
    static int bits;
    static char let;
    
    if (signal == SIGUSR1)
        let |= (1 << bits);
    bits++;
    if (bits == 8)
    {
        write(1, &let, 1);
        bits = 0;
        let = 0;
    }
}

int main(void)
{
    pid_t pid;
    struct sigaction sa;

    pid = getpid();
    if (pid == -1)
    {
        perror("pid");
        exit(1);
    }
    printf("pid:%d\n",pid);
    if (-1 == sigemptyset(&sa.sa_mask))
    {
        perror("sigemptyset");
        exit(1);
    }
    sa.sa_handler = signal_handler;
    sa.sa_flags = 0;
    if (-1 == sigaction(SIGUSR1, &sa, NULL) 
    || -1 == sigaction(SIGUSR2, &sa, NULL))
    {
        perror("sigaction");
        exit(1);
    }
    while (1)
    {
        pause();
    }
    return (0);
}