/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:39:16 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 21:32:09 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_numchar(const char c)
{
	int	ret;

	ret = 0;
	ret += write(1, &c, 1);
	if (ret == -1)
		return (-1);
	return (ret);
}
