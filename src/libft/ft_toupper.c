#include "libft.h"

int ft_toupper(int c){
    if((unsigned char)c >= 97 && (unsigned char)c <= 122){
        c -= 32;
        return(unsigned char)c;
    }
    return(c);
}