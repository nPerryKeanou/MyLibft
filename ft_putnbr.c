#include "libft.h"

static void	ft_putchar(char c){
	write (1, &c, 1);
}

void	ft_putnbr(int nb){
	if (nb < 0)
	{
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}