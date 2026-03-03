#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"


/*
    La taille de 50 octets était arbitraire et prudente pour la plupart des conversions d'entiers ou de chaînes de caractères courantes en base 16. Cela inclut généralement la conversion d'entiers 32 bits (int, unsigned int) et de chaînes de caractères de longueur modérée.
    ft_putnbr_hexadecimal
*/
int printf_nb_pointeur(void *ptr) {
    int i;

    i = 0;
    unsigned long address = (unsigned long)ptr;
    ft_putstr("0x");
    i += 2;
    i += ft_putnbr_base(address, "0123456789abcdef");
    return(i);
}