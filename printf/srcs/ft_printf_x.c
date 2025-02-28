/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:56:00 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 21:43:07 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_x(unsigned int n)
{
	int	ret;

	ret = 0;
	ret += ft_putunbr_base(n, BASE16_MIN);
	if (ret == -1)
		return (-1);
	return (ret);
}
