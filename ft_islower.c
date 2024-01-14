#include "libft.h"


/*
    La fonction islower() teste la présence de lettres minuscules.
    La valeur de l'argument doit être représentable en tant qu'unsigned char ou avoir la valeur EOF.
*/

int ft_islower(int c){
    if((unsigned char)c >= 97 && (unsigned char)c <= 122){
        return(1);
    }
    return(0);  
}
