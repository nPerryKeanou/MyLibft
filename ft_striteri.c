#include "libft.h"


static size_t ft_strlen(char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}

void    ft_striteri(char *s, void (*f)(unsigned int, char *)){
    size_t i = 0;
    size_t len = ft_strlen(s);

    while (i < len) {
        f(i, &s[i]);
        i++;
    }
}