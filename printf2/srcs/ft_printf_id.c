

#include "../includes/ft_printf.h"

int ft_printf_id(int num)
{
    int ret;

    ret = 0;
    ret += ft_putnbr_base(num, BASE_10);
    if(ret == -1)
        return (ret);
    return (ret);
}

// int main(void)
// {
//     printf("%d\n",-2147483648);
//     printf("%i\n",-32768);
//     return(0);
// }
