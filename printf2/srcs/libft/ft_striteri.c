/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:56:08 by sumedai           #+#    #+#             */
/*   Updated: 2024/06/05 11:36:20 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	len;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

// void ft_ad_index(unsigned int index, char *c)
// {
//     c = c + index;
// }

// int main(void)
// {
//     char *a = "aldjf;asl";
//     ft_striteri(a,ft_ad_index)
//     return(0);
// }