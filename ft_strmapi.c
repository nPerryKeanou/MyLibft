#include "libft.h"


//ft_strmapi va lancer la fn pour chaque char dans un chaine de caractere.


static size_t ft_strlen_const(char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}

char    *ft_strmapi(char const *s, char (*f)(unsigned int, char)){
    int i;
    int len;
    char *str;

    if(s == NULL || f == NULL){
        return(NULL);
    }
    i = 0;
    len = ft_strlen_const(s);
    str = (char*)malloc((len + 1) * sizeof(char));
    if(str == NULL){
        return(NULL);
    }
    while(i < len){
        str[i] = f(i, s[i]);
        i++;
    }
    str[i] = '\0';
    return(str);
}