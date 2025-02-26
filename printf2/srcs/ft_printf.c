/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sumedai <sumedai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 17:10:00 by sumedai           #+#    #+#             */
/*   Updated: 2024/08/05 01:09:47 by sumedai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int ft_specifier(const char *fmt, va_list ap)
{
    fmt++;
    if (*fmt == 'c')
        return (ft_printf_c(va_arg(ap, int))); /*OK*/
    if (*fmt == 's')
        return (ft_printf_s(va_arg(ap, char*))); /*OK*/
    if (*fmt == 'x')
        return (ft_printf_x(va_arg(ap, unsigned int))); /*OK*/
    if (*fmt == 'X')
        return (ft_printf_larx(va_arg(ap, unsigned int))); /*OK:*/
    if (*fmt == 'i' || *fmt == 'd')
        return (ft_printf_id(va_arg(ap, int))); /*OK*/
    if (*fmt == 'u')
        return (ft_printf_u(va_arg(ap, unsigned int))); /*OK*/
    if (*fmt == 'p')
        return (ft_printf_p(va_arg(ap, unsigned long long))); /*OK*/
    if (*fmt == '%')
        return (ft_numchar('%'));
    return (0);
}

static int ft_putstr_n(const char *str,int start, char c)
{
    int ret;

    ret = 0;
    while (str[start] && str[start] != c)
    {
        ret += ft_numchar(str[start]);
        start++;
    }
    return(ret);
}

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    int check;
    int i;
    int n;

    n = 0;
    i = 0;
    if (!fmt)
        return (-1);
    va_start(ap, fmt);
    while (fmt[i])
    {
        if (fmt[i] != '%')
        {
            check = ft_putstr_n(fmt, i, '%');
            if (check == -1)
                return(-1);
            n += check; 
            i += check;
        }
        else
        {
            check = ft_specifier(&fmt[i], ap);
            if (check == -1)
                return (-1);
            n += check; 
            i+=2;
        }
    }
    va_end(ap);
    return (n);
}

// int main(void)
// {
    /*test1*/
    // char a = 'a';
    // int n = -1;
    // printf("%c %c\n", a, n);
    // ft_printf("%c %c\n", a, n);
    /*test2*/
    // char str[] = "ABCDEFG";
    // char *s = NULL;
    // printf("%s %s\n",str,s);
    // ft_printf("%s %s\n",str,s);
    /*test3*/
    // int i;
    // char d;
    // printf("%p %p %p\n",&i,&d,NULL); 
    // ft_printf("%p %p %p\n",&i,&d,NULL);
    /*test4*/
    // printf("%i %i %d %d\n", INT_MAX , INT_MIN, 32767, -32768);
    // ft_printf("%i %i %i %i\n", INT_MAX , INT_MIN, 32767, -32768);
    // /*test5*/
    // printf("%x %x %X %X\n",UINT_MAX, INT_MIN,UINT_MAX, INT_MIN);
    // ft_printf("%x %x %X %X\n",UINT_MAX,INT_MIN,UINT_MAX, INT_MIN);
    /*test6*/
    // printf("%u %u\n",UINT_MAX,65535);
    // ft_printf("%u %u\n",UINT_MAX,65535);
    // /*test7*/
    // int i = -100;
    // ft_printf("%%d = %d %%p = %p\n",i,&i);
    // printf("%%d = %d %%p = %p\n", i,&i);
//     return (0); 
// }