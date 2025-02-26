/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 19:16:34 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/26 14:08:52 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

typedef struct s_sigl
{
    int	ch;
	int	ch2;
	int	ans;
	int	pid;
}   t_sigl;

#include <signal.h>
#include "../printf/includes/ft_printf.h"

void	byte1(void);
void	byte2(void);
void	byte3(void);
void	byte4(void);
void	handler_sigusr1(int sig, siginfo_t *si, void *unused);
void	handler_sigusr2(int sig, siginfo_t *si, void *unused);
void	set_act(void);
void    get_byte(void);
int     ccal(void);
#endif