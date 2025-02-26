/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 15:54:08 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/26 14:38:33 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_sigl sigl;

// struct sigaction 
//{
//     void     (*sa_handler)(int); // シグナルを受信した時に実行される関数を指定する
//     void     (*sa_sigaction)(int, siginfo_t *, void *); // sa_flagsにSA_SIGINFOが入っているときに使用され、シグナル番号、シグナルに関する追加情報を含む
//     sigset_t   sa_mask; // シグナルハンドラが実行中に他のシグナルが割り込まないようにするために使用されている
//     int        sa_flags; // シグナルハンドラの動作を制御するフラグ
//     void     (*sa_restorer)(void); // 今はあんま使われてないらしい
// };

int main(void)
{
    pid_t pid;
    
    
    sigl.ch = 0;
    sigl.ch2 = 0;
    sigl.ans = 0;
    pid = getpid();
    if (pid <= 0)
    {
        ft_printf("Error: PID faliure");
        exit(1);
    }
    ft_printf("PID:%d\n",pid);
    ft_printf("waiting for client\n");
    set_act();
    while (42)
    {
        pid = ccal();
        if (pid == -1)
        {
            kill(sigl.pid, SIGUSR1);
            write(1, "\n", 1);
            sigl.ch = 0;
            sigl.ch2 = 0;
        }
    }
    return (0);
}