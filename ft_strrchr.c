#include "libft.h"

// * La fonction strchr recherche la derniére occurrence du caractère spécifié c dans la chaîne de caractères pointée par s. 
//c'est la même chose que strchr mais, on décrémente à partir de la fin de la chaine.

static size_t ft_strlen(char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}

char    *ft_strrchr(const char *s, int c){
    size_t i;
    size_t len_s;

    i = ft_strlen(s);
    len_s = ft_strlen(s);
    if(s == NULL){
        return(NULL);
    }
    if((unsigned char)c == '\0'){
        return((char*)s+i);
    }
    while(i > 0){
        if(s[i] == (unsigned char)c){
            return((char*)s+i);
        }
        i--;
    }
    return(NULL);
}