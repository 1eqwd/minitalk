/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 10:26:35 by sumedai           #+#    #+#             */
/*   Updated: 2024/05/22 21:15:44 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *src, int c)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if ((unsigned char)src[i] == (unsigned char)c)
			return ((char *)&src[i]);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)&src[i]);
	else
		return (NULL);
}

// int main(void)
// {

// 	printf("%p\n",ft_strchr(0x109a7da40: "teste", 1024: '\0'));
// 	printf("%p\n",ft_strchr(0x109a7da40: "teste", 1024: '\0'));

// 	return (0);
// }