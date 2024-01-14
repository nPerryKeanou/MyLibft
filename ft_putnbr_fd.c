#include "libft.h"

void    ft_putnbr_fd(int n, int fd){
    if (n < 0)
	{
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_fd((n / 10),1);
		ft_putnbr_fd((n % 10),1);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
