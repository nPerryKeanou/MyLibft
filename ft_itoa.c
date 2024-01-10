#include "stdio.h"
#include "stdlib.h"


/**
Alloue (avec malloc(3)) et retourne une chaîne
de caractères représentant l’entier ’n’ reçu en
argument. Les nombres négatifs doivent être gérés.
*/
//transformer chaque chiffre de nb en char.
//pour check chaque chiffre un par un, je dois diviser le nb par 10 pour passer perdre une unités a chaque fois et faire le modulo 10
//pour récuprer le reste de la division et de le transformer en char.
//je dois aussi gerer les négatifs.
//je dois aussi gerer que ce ne dépasse pas la valeurs des int (attentions selon le systeme d'exploitation et des valeurs des octets.)
// valeur int max: 2147483647  && min : -2147483648

long long ft_len_nb(int nb){
    long long i;
    long long rslt;

    i = 0;
    while(nb > 0){
        nb = nb / 10;
        i++;
    }
    //i sera le nb de boucle fait pour que nb / 10 soit == ou < que 0
    return(i);
}

char    *ft_itoa(int nb){
    int rslt_div;
    int rslt_mod;
    int len_malloc;
    int i;
    char *rslt_str;

    rslt_div = 0;
    rslt_mod = 0;
    len_malloc = ft_len_nb(nb);
    i = ft_len_nb(nb) - 1;
    if(nb < 0){
        len_malloc += 1;
    }
    rslt_str = (char*)malloc(len_malloc +  1 * sizeof(char));
    if(rslt_str == NULL){
        return(0);
    }
    rslt_str[i] = '\0';
    i--;
    while(nb > 0){
        rslt_mod = nb % 10;
        //il faut mettre rslt_mod dans la derniere place de rslt_str et puis décrémenter pour arriver à l'index 0
        rslt_str[i] = rslt_mod;
        rslt_div / 10;
    }
    return(rslt_str);
}