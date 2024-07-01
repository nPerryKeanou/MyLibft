#include "libft.h"

int ft_isascii(int c){
    if((unsigned char)c >= 001 && (unsigned char)c <= 0177){
        return(1);
    }
    return(0);
}