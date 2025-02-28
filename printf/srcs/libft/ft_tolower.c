/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 13:31:33 by sumedai           #+#    #+#             */
/*   Updated: 2024/05/04 17:57:47 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && 'Z' >= c)
	{
		c += 'a' - 'A';
		return (c);
	}
	else
		return (c);
}

// #include<stdio.h>
// #include<ctype.h>
// int main(void)
// {
//     printf("%c\n", tolower('A'));
//     printf("%c\n", ft_tolwer('A'));
//     return(0);
// }
