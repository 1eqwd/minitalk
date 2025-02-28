/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:24:32 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 22:44:01 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_n(const char *str, int start, char c)
{
	int	ret;

	ret = 0;
	while (str[start] && str[start] != c)
	{
		ret += ft_numchar(str[start]);
		start++;
	}
	return (ret);
}
