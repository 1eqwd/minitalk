/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 22:08:47 by sumedai           #+#    #+#             */
/*   Updated: 2025/02/26 13:45:04 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

extern t_sigl sigl;

void	byte1(void)
{
	if (sigl.ans == 0)
	{
		sigl.ch2 = 0;
		return ;
	}
	write(1, (unsigned char *)&sigl.ans, 1);
}

void	byte2(void)
{
	write(1, (unsigned char *)&sigl.ans, 1);
	get_byte();
	write(1, (unsigned char *)&sigl.ans, 1);
}

void	byte3(void)
{
	write(1, (unsigned char *)&sigl.ans, 1);
	get_byte();
	write(1, (unsigned char *)&sigl.ans, 1);
	get_byte();
	write(1, (unsigned char *)&sigl.ans, 1);
}

void	byte4(void)
{
	write(1, (unsigned char *)&sigl.ans, 1);
	get_byte();
	write(1, (unsigned char *)&sigl.ans, 1);
	get_byte();
	write(1, (unsigned char *)&sigl.ans, 1);
	get_byte();
	write(1, (unsigned char *)&sigl.ans, 1);
}
