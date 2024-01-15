#include "libft.h"

/*
DESCRIPTION
La fonction strlen() calcule la longueur de la chaîne de caractères s. 
La fonction strnlen() tente de calculer la longueur de s, mais ne parcourt jamais au-delà des premiers maxlen octets de s.

VALEURS DE RETOUR
La fonction strlen() renvoie le nombre de caractères qui précèdent le caractère NUL de terminaison.
 La fonction strnlen() renvoie soit le même résultat que strlen(), soit maxlen, selon lequel est plus petit.
*/
size_t  ft_strlen(char *s){
    size_t i;

    i = 0;
    while(s[i] != '\0'){
        i++;
    }
    return(i);
}