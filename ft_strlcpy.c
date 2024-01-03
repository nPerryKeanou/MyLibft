#include "stddef.h"


/*
Cette fonction copie jusqu'à dstsize - 1 caractères depuis la chaîne source src vers la destination dst.
Elle garantit que la destination dst est toujours terminée par un caractère nul ('\0').
Si dstsize est 0, la fonction ne fait rien.
Elle renvoie la longueur totale de la chaîne source (src).
*/



size_t  ft_strlcpy(char  *dst, const char *src, size_t dstsize){
    size_t i;

    i = 0;
    if(dst != NULL && src != NULL && dstsize > 0){
        while(i < dstsize - 1 && src[i] != '\0'){
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    //retourne le nb d'octet copié.
    return(i);
}