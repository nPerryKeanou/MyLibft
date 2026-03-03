#include "libft.h"

char    *ft_strnstr(const char *haystack, const char *needle, size_t len){
    size_t i;
    size_t tmp;
    size_t len_need;

    i = 0;
    len_need = ft_strlen_const(needle);
    if(len_need == 0){
        return((char *)haystack);
    }
    while(i < len && i + len_need <= len){
        if(haystack[i] == needle[0]){
            tmp = 0;
            while(tmp < len_need && haystack[i + tmp] == needle[tmp]){
                tmp++;
            }
            if(tmp == len_need){
                return((char *)haystack + i);
            }
        }
        i++;
    }
    return(NULL);
}