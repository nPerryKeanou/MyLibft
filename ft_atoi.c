#include "libft.h"

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