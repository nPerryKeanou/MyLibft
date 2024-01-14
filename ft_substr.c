#include "libft.h"
//cette fonction récupere len char de la chaine s à partir de start et renvoie une nouvelle chaine.

char    *ft_substr(const char *s, unsigned int start, size_t len){
    size_t i;
    char    *str;

    i = 0;
    str = (char *)malloc(len + 1 * sizeof(char));
    if (str == NULL || s == NULL || len == 0){
        return(NULL);
    }
    while(i < len && s[start] != '\0'){
        str[i] = s[start];
        i++;
        start++;
    }
    str[i] = '\0';
    return(str);
}