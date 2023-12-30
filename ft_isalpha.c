#include "libft.h"
/*
    La fonction isalpha() teste la présence de tout caractère pour lequel isupper(3) ou islower(3) est vrai. 
    La valeur de l'argument doit être représentable en tant qu'unsigned char ou avoir la valeur EOF.
*/
int ft_isalpha(int c){
    if(ft_islower((unsigned char)c) && ft_isupper((unsigned char)c)){
        return(1);
    }
    return(0);
}
