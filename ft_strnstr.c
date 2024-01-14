#include "libft.h"
/**
 * strnstr :

Description : La fonction strnstr() localise la première occurrence de la chaîne de caractères null-terminée needle dans la chaîne de caractères haystack, 
où au plus len caractères sont recherchés. 
Les caractères qui apparaissent après un caractère \0 ne sont pas recherchés.
Valeur de retour : Si needle est une chaîne vide, la fonction retourne haystack. 
Si needle n'est trouvé nulle part dans les premiers len caractères de haystack, la fonction retourne NULL. 
Sinon, un pointeur sur le premier caractère de la première occurrence de needle dans les premiers len caractères est renvoyé.
 * 
*/

static size_t ft_strlen_const(const char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}

char    *ft_strnstr(const char *haystack, const char *needle, size_t len){
    size_t i;
    size_t tmp;
    size_t len_hays;
    size_t len_need;

    i = 0;
    len_hays = ft_strlen_const(haystack);
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