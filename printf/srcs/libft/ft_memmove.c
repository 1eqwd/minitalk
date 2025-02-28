/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:08:17 by sumedai           #+#    #+#             */
/*   Updated: 2024/05/23 16:35:45 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t size)
{
	size_t	i;

	if (!dst && !src)
		return (NULL);
	if (src < dst && (char *)dst < (const char *)src + size)
	{
		i = size;
		while (i > 0)
		{
			((char *)dst)[i - 1] = ((const char *)src)[i - 1];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < size)
		{
			((char *)dst)[i] = ((const char *)src)[i];
			i++;
		}
	}
	return (dst);
}

// //  int main(void)
// //  {
// //      char a[] = "abcdef";
// //      char *b =ft_memmove(a+2,a,4);
// //      char *c = memmove(a+2,a,4);
// //      printf("%s\n",b);
// //      printf("%s\n",c);
// //      return(0);
// // }
