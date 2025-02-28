/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:17:43 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 22:17:58 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunbr_base(unsigned long long n, char *base)
{
	unsigned long long	base_len;
	int					ret;

	ret = 0;
	base_len = (unsigned long long)ft_strlen(base);
	if (n >= base_len)
		ret += ft_putunbr_base(n / base_len, base);
	ret += ft_numchar(base[n % base_len]);
	return (ret);
}
