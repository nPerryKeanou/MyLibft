#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, size_t n){
    size_t i;

    i = 0;
    if(n == 0 || s1 == NULL || s2 == NULL){
        return(0);
    }
    while(i < n && s1[i] == s2[i] && s1[i] != '\0'){
        i++;
    }
    return(s1[i] - s2[i]);
}