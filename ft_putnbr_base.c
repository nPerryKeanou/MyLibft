#include "libft.h"

void ft_putnbr_base(unsigned long long int n, char *base, int *count)
{
    // Vérifie si le nombre est supérieur ou égal à la base
    if (n >= ft_strlen(base))
    {
        *count++;
        ft_putnbr_base(n / ft_strlen(base), base, count);
    }

    // Affiche le chiffre correspondant dans la base
    ft_putchar(base[n % ft_strlen(base)]);
}