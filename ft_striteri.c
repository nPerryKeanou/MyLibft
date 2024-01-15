#include "libft.h"


void    ft_striteri(char *s, void (*f)(unsigned int, char *)){
    size_t i = 0;
    size_t len = ft_strlen(s);

    while (i < len) {
        f(i, &s[i]);
        i++;
    }
}