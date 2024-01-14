#include "libft.h"

/*
*
La fonction strncmp compare les n premiers caractères des chaînes de caractères s1 et s2. 
Elle renvoie un entier négatif si s1 est inférieur à s2, 0 si les deux chaînes sont égales, et un entier positif si s1 est supérieur à s2.

Le paramètre n spécifie le nombre maximal de caractères à comparer. Si n est égal à zéro, la fonction renvoie 0, 
indiquant que les chaînes sont considérées comme égales.

Le comportement de strncmp est sensible à la casse, ce qui signifie qu'elle fait une distinction entre majuscules et 
minuscules lors de la comparaison des caractères.
*/

int ft_strncmp(const char *s1, const char *s2, size_t n){
    size_t i;

    i = 0;
    if(n == 0 || s1 == NULL || s2 == NULL){
        return(0);
    }
    while(i < n && s1[i] == s2[i] && s1[i] != '\0'){
        i++;
    }
    return(s1[i] - s2[i]);
}
//ou
/*
int ft_strncmp(const char *s1, const char *s2, size_t n) {
    size_t i = 0;

    while (i < n && s1[i] == s2[i] && s1[i] != '\0') {
        i++;
    }

    if (i == n) {
        return 0;  // Les premiers n caractères sont identiques
    }

    return (unsigned char)s1[i] - (unsigned char)s2[i];
}
*/