/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:32:07 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 21:33:42 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_numstr(const char *str)
{
	int	i;
	int	ret;
	int	check;

	i = 0;
	ret = 0;
	while (str[i])
	{
		check = ft_numchar(str[i]);
		if (check == -1)
			return (-1);
		ret += check;
		i++;
	}
	return (ret);
}
