#include "libft.h"

size_t  ft_strlcpy(char  *dst, const char *src, size_t dstsize){
    size_t i;

    i = 0;
    if(dst != NULL && src != NULL && dstsize > 0){
        while(i < dstsize - 1 && src[i] != '\0'){
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return(i);
}