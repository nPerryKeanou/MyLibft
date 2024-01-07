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
Cette fonction va supprimer tout les chars de s1 en début et fin de chaine qui se trouvent dans set.
Il faut ici, comparer s1[x] a chaque char dans set.
*/
char    *ft_strtrimchr_multi(const char *s1, const char    *set){

}   