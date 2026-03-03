#include "libft.h"

int ft_tolower(int c){
    if((unsigned char)c >= 65 && (unsigned char)c <= 90){
        c += 32;
        return((unsigned char)c);
    }
    return(c);
}