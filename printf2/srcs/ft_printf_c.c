/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 21:00:17 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/05 00:15:55 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_printf_c(int c)
{
    int ret;

    ret = 0;
    ret += ft_numchar(c);
    return (ret);
}

// int main(void)
// {
//     char c = 'f';
//     printf("\n%d\n", ft_printf_c(c));
//     return(0);
// }
