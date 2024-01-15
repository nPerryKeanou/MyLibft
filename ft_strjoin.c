#include "libft.h"

char    *ft_strjoin(const char *s1, const char *s2){
    size_t len_s1;
    size_t len_s2;
    size_t i;
    size_t j;
    char *str;

    len_s1 = ft_strlen_const(s1);
    len_s2 = ft_strlen_const(s2);
    i = 0;
    j = 0;
    str = (char *)malloc(len_s1 + len_s2 + 1 * sizeof(char));
    if(s1 == NULL || s2 == NULL || str == NULL){
        return(NULL);
    }
    while(s1[i] != '\0'){
        str[i] = s1[i];
        i++;
    }
    while(s2[j] != '\0'){
        str[i] = s2[j];
        i++;
        j++;
    }
    str[i] = '\0';
    return(str);
}