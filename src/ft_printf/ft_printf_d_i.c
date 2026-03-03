#include <stdio.h>
#include <stdarg.h>
#include "libftprintf.h"

//On va ici utiliser la fonction ft_putnbr pour afficher un décimal et aussi retourner le nb de chiffre du décimal qui sera la variable i.
/*
     un int sur 32 bits :

La valeur maximale positive est 2 147 483 647.
La valeur minimale négative est -2 147 483 648.
*/

int ft_putnbr_d_i(int nb){
    int i;

    i = 0;
     if (nb == INT_MIN) {
        ft_putstr("-2147483648");  // Affiche directement la valeur minimale
        return 11;  // Longueur de "-2147483648"
    }
    if(nb == INT_MAX){
        ft_putstr("2147483647");
        return(10);
    }
    if (nb < 0)             //condition si le nb est négatif.
	{
		ft_putchar('-'); //affiche le signe négatif.
        
		nb = -nb;           //transforme le nb négatif en positif.
        i += 1;             //incrémente la variable à retourner.
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

/*
    Explication  de la récursive avec des piles :
        
    1) Appel Initial : ft_putnbr(-123)

        Pile : ft_putnbr(-123) est en haut de la pile.

        nb est négatif, donc ft_putchar('-') est exécuté pour afficher -.

        nb devient 123.

    2) Premier Appel Récursif : ft_putnbr(123 / 10)

        Pile : Maintenant, ft_putnbr(123) est empilée sur la pile au-dessus de ft_putnbr(-123).

        123 / 10 = 12, donc ft_putnbr(12) est appelée.

    3) Second Appel Récursif : ft_putnbr(123 % 10)

        Pile : ft_putnbr(12) est maintenant au-dessus de ft_putnbr(-123) et ft_putnbr(123).

        123 % 10 = 3, donc ft_putnbr(3) est appelée.

    4) Affichage des Chiffres :

        ft_putnbr(3) affiche 3.

            Après affichage, ft_putnbr(3) se termine et est retirée de la pile.

        Retour à ft_putnbr(12 % 10) qui est ft_putnbr(2).

            ft_putnbr(2) affiche 2.

            Après affichage, ft_putnbr(2) se termine et est retirée de la pile.

        Retour à ft_putnbr(12).

            ft_putnbr(12) a déjà affiché 1 (résultat de ft_putnbr(12 / 10)).

            Maintenant, ft_putnbr(12 % 10) est traitée, donc 3 est affiché.

            Après affichage, ft_putnbr(12) se termine et est retirée de la pile.

        Retour à ft_putnbr(-123).

            ft_putchar('-') et les appels récursifs ont terminé, l'affichage complet est -123.

            ft_putnbr(-123) se termine et est retirée de la pile.
*/
