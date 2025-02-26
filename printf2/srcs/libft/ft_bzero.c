/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 14:55:02 by sumedai           #+#    #+#             */
/*   Updated: 2024/05/01 15:58:49 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *b, size_t len)
{
	ft_memset(b, 0, len);
}

// int main(void)
// {
//     char c[] = "asddcxz";
//     char d[] = "asddcxz";
//     bzero(c+3, 3);
//     ft_bzero(d+3, 3);
//     printf("%s\n",c );
//     printf("%s\n",d);
//     return(0);
// }
