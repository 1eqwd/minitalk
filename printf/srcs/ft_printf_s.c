/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:01:49 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 21:37:52 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_printf_s(char *s)
{
	int	ret;

	ret = 0;
	if (s == NULL)
		s = "(null)";
	ret += ft_numstr(s);
	if (ret == -1)
		return (-1);
	return (ret);
}
