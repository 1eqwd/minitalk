/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:22:51 by sumedai           #+#    #+#             */
/*   Updated: 2024/05/22 21:22:01 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && '9' >= c)
		return (1);
	else
		return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int main (void)
{
    printf("%d\n", isdigit('\0'));
    printf("%d\n", ft_isdigit('\0'));
    return(0);
}*/