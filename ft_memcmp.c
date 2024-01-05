#include "stddef.h"

/**
 * 
 * 
 * 
*/

int ft_memcmp(const void *s1, const void *s2, size_t n){
    size_t i;
    const unsigned char *us1;
    const unsigned char *us2;

    i = 0;
    us1 = (unsigned char *)s1;
    us2 = (unsigned char *)s2;
    while(i < n){
        if(us1[i] != us2[i]){
            return(us1[i] - us2[i]);
        }
        i++;
    }
    return(0);
}