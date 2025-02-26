/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:02:21 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/05 00:32:24 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_printf_p(unsigned long long n)
{
    int     ret;

    ret = 0; 
    if (n == 0)
    {
        ret += ft_numstr("(nil)");
        return (ret);
    }
    ret += ft_numstr("0x");
    if (ret == -1)
        return (-1);
    ret += ft_putunbr_base(n, BASE16_MIN);
    if (ret == -1)
        return (-1);
    return (ret);
}

// int main(void)
// {
//     char *c = NULL;
//     printf("%p\n", c);
//     return(0);
// }
