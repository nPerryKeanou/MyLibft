#include "libft.h"

void ft_putnbr_base(unsigned long long int n, char *base, int *count)
{
    if (n >= ft_strlen(base))
    {
        *count++;
        ft_putnbr_base(n / ft_strlen(base), base, count);
    }
    ft_putchar(base[n % ft_strlen(base)]);
}