/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:00 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 22:39:54 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_specifier(const char *fmt, va_list ap)
{
	fmt++;
	if (*fmt == 'c')
		return (ft_printf_c(va_arg(ap, int)));
	if (*fmt == 's')
		return (ft_printf_s(va_arg(ap, char *)));
	if (*fmt == 'x')
		return (ft_printf_x(va_arg(ap, unsigned int)));
	if (*fmt == 'X')
		return (ft_printf_larx(va_arg(ap, unsigned int)));
	if (*fmt == 'i' || *fmt == 'd')
		return (ft_printf_id(va_arg(ap, int)));
	if (*fmt == 'u')
		return (ft_printf_u(va_arg(ap, unsigned int)));
	if (*fmt == 'p')
		return (ft_printf_p(va_arg(ap, unsigned long long)));
	if (*fmt == '%')
		return (ft_numchar('%'));
	return (0);
}

static int	handle_non_format(const char *fmt, int *i, int *n)
{
	int	check;

	check = ft_putstr_n(fmt, *i, '%');
	if (check == -1)
		return (-1);
	*n += check;
	*i += check;
	return (check);
}

static int	handle_format(const char *fmt, int *i, int *n, va_list ap)
{
	int	check;

	check = ft_specifier(&fmt[*i], ap);
	if (check == -1)
		return (-1);
	*n += check;
	*i += 2;
	return (check);
}

int	ft_printf(const char *fmt, ...)
{
	int		check;
	int		i;
	int		n;
	va_list	ap;

	i = 0;
	n = 0;
	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] != '%')
			check = handle_non_format(fmt, &i, &n);
		else
			check = handle_format(fmt, &i, &n, ap);
	}
	va_end(ap);
	return (n);
}
