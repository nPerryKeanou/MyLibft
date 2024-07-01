#include "libft.h"

void    *ft_memmove(void *dst, const void *src, size_t len){
    size_t i;
    unsigned char   *ptr_dst;
    const unsigned char   *ptr_src;

    i = 0;
    ptr_dst = dst; 
    ptr_src = src;
    if(ptr_dst == ptr_src){
        return(dst);
    }
    if(ptr_dst != NULL && ptr_src != NULL){
        if(ptr_dst < ptr_src){
            while(len--){
                *ptr_dst++ = *ptr_src;
            }
        }else if(ptr_dst > ptr_src){
            ptr_dst += len;
            ptr_src += len;
            while(len--){
                *(--ptr_dst) = *(--ptr_src);
            }
        }
    }
    return(dst);
}