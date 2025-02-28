/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 19:43:53 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/24 22:36:47 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define BASE16_MAX "0123456789ABCDEF"
# define BASE16_MIN "0123456789abcdef"
# define BASE_10 "0123456789"

# include "libft.h"
# include <ctype.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>

int	ft_printf(const char *fmt, ...);
int	ft_numchar(const char c);
int	ft_printf_s(char *s);
int	ft_numstr(const char *str);
int	ft_printf_c(int c);
int	ft_printf_x(unsigned int n);
int	ft_printf_larx(unsigned int n);
int	ft_printf_id(int num);
int	ft_printf_p(unsigned long long n);
int	ft_printf_u(unsigned int n);
int	ft_putnbr_base(long long num, char *base);
int	ft_putunbr_base(unsigned long long n, char *base);
int	ft_putstr_n(const char *str, int start, char c);

#endif
