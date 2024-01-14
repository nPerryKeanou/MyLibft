#include "libft.h"

int ft_tolower(int c){
    if((unsigned char)c >= 65 && (unsigned char)c <= 90){
        c += 32;
        return((unsigned char)c);
    }
    // ou 
    //if((unsigned char)c >= 'A' && (unsigned char)c <= 'Z'){
    //    c += 'a' - 'A';
    //}
    return(c);
}