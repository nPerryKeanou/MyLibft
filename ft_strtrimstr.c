#include "stddef.h"
#include "stdlib.h"

static size_t ft_strlen_const(const char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}


/*
Cette fonction va supprimer le debut et fin de chaine de s1 si on retouve exactement set en debut et fin.
*/
char    *ft_strtrimstr(const char *s1, const char    *set){

}   