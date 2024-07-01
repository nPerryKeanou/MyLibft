#include "libft.h"

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n){
    size_t i;
    unsigned char *ptr_dst;
    const unsigned char *ptr_src;

    i = 0;
    ptr_dst = dst;
    ptr_src = src;
    if(dst != NULL && src != NULL && n > 0){
            while(i < n){
                ptr_dst[i] = ptr_src[i];
                i++;
            }
    }
    return(dst);
}