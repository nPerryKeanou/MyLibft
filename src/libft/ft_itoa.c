#include "libft.h"

long long ft_len_nb(int nb){
        long long i = 0;
    // Gérer le cas où nb est égal à zéro
    if (nb == 0) {
        return 1;
    }
    while (nb != 0) {
        nb = nb / 10;
        i++;
    }
    return i;
}

char    *ft_itoa(int nb){
    long long n = ft_len_nb((long long)nb);
    int len_str = 0;
    char *str;
    int boole;

    n = (nb == 0) ? 1 : n; // Gérer le cas où nb est égal à zéro
    len_str = 0;
    boole = 1;
    if (nb < 0) {
        len_str += 1;
        nb = -nb;
        boole = 0;
    }
    str = (char *)malloc((len_str + n + 1) * sizeof(char)); // Correction pour la taille de la chaîne
    if (str == NULL) {
        return NULL;
    }
    str[n--] = '\0';
    // Gérer le cas où nb est égal à zéro
    if (nb == 0) {
        str[0] = '0';
        return str;
    }
    while (nb > 0) {
        str[n--] = '0' + nb % 10;
        nb = nb / 10;
    }
    if (boole == 0) {
        str[0] = '-';
    }
    return str;
}
