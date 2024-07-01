#include "libft.h"

char    *ft_strchr(const    char    *s, int c){
    size_t i;
    size_t len_s;

    i = 0;
    len_s = ft_strlen_const(s);
    if(s == NULL){
        return(NULL);
    }
    if((unsigned char)c == '\0'){
        return((char*)s+len_s);
    }
    while(*(s) != '\0'){
        if(*(s) == (unsigned char)c){
            return((char*)s);
        }
        s++;
    }
    return(NULL);
}