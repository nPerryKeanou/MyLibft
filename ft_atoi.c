#include "stddef.h"
#include "stdlib.h"
#include "limits.h"
/*

La fonction atoi convertit la partie initiale d'une chaîne de caractères en une représentation entière (int). 
Voici comment elle fonctionne :

Elle parcourt la chaîne de caractères depuis le début jusqu'à ce qu'elle rencontre le premier caractère qui n'est pas un espace (' ')
 ou une caractère numérique.

Elle interprète ensuite les caractères numériques consécutifs jusqu'à atteindre la fin de la séquence numérique ou 
jusqu'à rencontrer un caractère non numérique.

Elle convertit la séquence numérique en une valeur entière de type int.

Elle retourne cette valeur entière.

En cas d'erreur ou si la chaîne de caractères ne commence pas par une séquence numérique valide, la fonction retourne 0.

Il est important de noter que la fonction atoi ne fournit pas de mécanisme robuste pour détecter les erreurs de conversion. 
Si la chaîne de caractères ne peut pas être convertie correctement en un entier, atoi retourne simplement 0, 
et il n'y a aucun moyen de différencier une conversion réussie d'une conversion qui a donné 0 comme résultat valide.


int ft_atoi(const char *str) {
    int result = 0;
    int sign = 1;
    int i = 0;

    // Gestion des espaces blancs au début de la chaîne
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) {
        i++;
    }

    // Gestion du signe
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    // Conversion des chiffres
    while (str[i] >= '0' && str[i] <= '9') {
        // Gestion du débordement
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        // Mise à jour du résultat
        result = result * 10 + (str[i++] - '0');
    }

    return result * sign;
}

*/
long long int ft_atoi(const char *str){
    long long int result = 0;
    int i = 0;
    int sign = 1;

    // Gestion des espaces blancs et autres caractères spéciaux au début de la chaîne.
    while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)) {
        i++;
    }

    // Gestion du signe.
    if (str[i] == '-' || str[i] == '+') {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    // Conversion des chiffres.
    while (str[i] >= '0' && str[i] <= '9') {
        // Vérification du dépassement.
        if (result > (LLONG_MAX - (str[i] - '0')) / 10) {
            return (sign == 1) ? LLONG_MAX : LLONG_MIN;
        }

        // Mise à jour du résultat.
        result = result * 10 + (str[i++] - '0');
    }

    return result * sign;
}