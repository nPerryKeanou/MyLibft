#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

static int		check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (base[0] == '\0' || base[1] == '\0') //Si la base est vide ou ne contient qu'un seul caractère, on return 0. Car une base valide doit contenur au moin deux caractères.
		return (0);
	while (base[i])//La boucle intérieure compare base[i] avec chaque caractère suivant base[j] pour s'assurer qu'il n'y a pas de duplicata dans la base.
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		if (base[i] < 32 || base[i] > 126)
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(long int nbr, char *base)//lorsque vous effectuez une opération modulo par rapport à la taille de la base, le résultat (le reste) sera toujours compris entre 0 et taille de la base-1.
{
	int	len;
	int	nbr_final[100];
	int	i;

	i = 0;
	len = 0;
	if (check_base(base))
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr = -nbr;
		}
		while (base[len]) //Calcule la longueur de la base
			len++;
		if (nbr == 0)
		{
			ft_putchar(base[0]); // Si nbr est zéro, imprime directement le premier caractère de la base
			return (1); // Retourne 1 car un seul caractère a été imprimé (le cas spécial)
		}
		while (nbr)
		{
			nbr_final[i] = nbr % len; 	//stocker le dernier chiffre dans le nouveau tableau
			nbr = nbr / len;			//élimine le dernier chiffre déjà récupéré
			i++;
		}
		len = i ;
		while (--i >= 0) //affiche le resultat en ordre inverse pour avoir les chiffres dans le bonnes ordre final.
			ft_putchar(base[nbr_final[i]]);
	}
    return(len);
}