/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_larx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 22:04:18 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/05 01:09:03 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_printf_larx(unsigned int n)
{
    int ret;

    ret = 0;
    ret += ft_putunbr_base(n, BASE16_MAX);
    if(ret == -1)
        return (-1);
    return (ret);
}

// int main(void)
// {

// }
