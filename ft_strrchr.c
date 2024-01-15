#include "libft.h"

char    *ft_strrchr(const char *s, int c){
    size_t i;
    size_t len_s;

    i = ft_strlen_const(s);
    len_s = ft_strlen_const(s);
    if(s == NULL){
        return(NULL);
    }
    if((unsigned char)c == '\0'){
        return((char*)s+i);
    }
    while(i > 0){
        if(s[i] == (unsigned char)c){
            return((char*)s+i);
        }
        i--;
    }
    return(NULL);
}