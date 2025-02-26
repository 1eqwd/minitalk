/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 18:32:07 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/05 00:33:49 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int ft_numstr(const char *str)
{
    int i;
    int ret;
    int check;

    i = 0;
    ret = 0;
    while(str[i])
    {
        check = ft_numchar(str[i]);
        if (check == -1)
            return (-1);
        ret += check;
        i++;
    }
    return(ret);
}

// int main(void)
// {
//     printf("\n%d\n",ft_putstr_num("(nill)"));
//     return(0);
// }