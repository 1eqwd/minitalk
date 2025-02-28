/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:44:22 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 21:48:21 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_u(unsigned int n)
{
	int	ret;

	ret = 0;
	ret += ft_putunbr_base(n, BASE_10);
	if (ret == -1)
		return (-1);
	return (ret);
}
