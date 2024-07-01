#include "libft.h"

int ft_isalpha(int c){
    if(ft_islower((unsigned char)c) && ft_isupper((unsigned char)c)){
        return(1);
    }
    return(0);
}
