#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

int ft_putnbr_u(unsigned int nb){
     int i;

    i = 0;
     if (nb == UINT_MAX) {
        ft_putstr("4294967295");  // Affiche directement la valeur minimale
        return 10;  // Longueur de "-2147483648"
    }
	if (nb >= 10)           //condition si le nb est plus grand ou égale à 10. Maintenant que la conversion est faite et que nb est plus grand que 10. On peut commencer la récursion.
	{
                   
		ft_putnbr_d_i(nb / 10); //appel recursive de la partie entière de nb. ex : (123 / 10) == 12
		ft_putnbr_d_i(nb % 10); //appel recursive de la dernière partie de nb. ex : (123 % 10) == 3
	}
	else{
        i += 1;
        ft_putchar(nb + '0'); //affiche le chifre correspondant à nb. '1' '2' '3'.
    }
    return(i);
}