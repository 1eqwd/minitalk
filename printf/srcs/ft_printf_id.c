/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:44:09 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 21:35:51 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_id(int num)
{
	int	ret;

	ret = 0;
	ret += ft_putnbr_base(num, BASE_10);
	if (ret == -1)
		return (ret);
	return (ret);
}
