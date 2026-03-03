#include "libft.h"


void    *ft_memchr(const void   *s, int c, size_t n){
    size_t i;
    const unsigned char *us;
    unsigned char uc;

    i = 0;
    us = (const unsigned char *)s;
    uc = (unsigned char)c;
    if(n == 0 || s == NULL){
        return(NULL);
    }
    while(i < n){
        if(us[i] == uc){
            return (void *)(us + i);
        }
        i++;
    }
    return(NULL);
}