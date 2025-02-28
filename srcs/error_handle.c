/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 14:38:23 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/27 17:56:57 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	proc_err(t_err_code err_code)
{
	if (err_code == ERR_ARGC)
	{
		ft_printf("Error: Invalid number of arguments\n");
		ft_printf("Usage: ./client SERVER_PID MESSAGE\n");
		exit(2);
	}
	else if (err_code == ERR_SERVER_PID)
		ft_printf("Error: Invalid server PID\n");
	else if (err_code == ERR_MULI_CLIENTS)
		ft_printf("Error: Server stopped reponding\n");
	else if (err_code == ERR_SERVER_TERMINATED)
		ft_printf("Error: Server was terminated\n");
	else if (err_code == ERR_SERVER_RESP_TIMEOUT)
		ft_printf("Error: Server did not respond within expected time\n");
	else if (err_code == ERR_CLIENT_RESP_TIMEOUT)
		ft_printf("Error: No signal received form the client\n");
	else if (err_code == ERR_WRITE)
		ft_printf("Error: Faild to write to standard output\n");
	exit(EXIT_FAILURE);
}
