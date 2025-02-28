/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:33:26 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/27 18:17:39 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "../printf/includes/ft_printf.h"
# include "../printf/includes/libft.h"
# include <signal.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

typedef enum e_err_code
{
	ERR_ARGC,
	ERR_SERVER_PID,
	ERR_MULI_CLIENTS,
	ERR_SERVER_TERMINATED,
	ERR_SERVER_RESP_TIMEOUT,
	ERR_CLIENT_RESP_TIMEOUT,
	ERR_WRITE,
}	t_err_code;

void	proc_err(t_err_code err_code);

#endif
