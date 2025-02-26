/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:08:39 by sumedai           #+#    #+#             */
/*   Updated: 2024/05/04 18:02:16 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && 'z' >= c)
	{
		c -= 'a' - 'A';
		return (c);
	}
	else
		return (c);
}

// #include<ctype.h>
// #include<stdio.h>
// int main(void)
// {
//     printf("%c\n", toupper('B'));
//     printf("%c\n", ft_toupper('r'));
//     return(0);
// }
