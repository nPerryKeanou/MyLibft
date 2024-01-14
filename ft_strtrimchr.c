#include "libft.h"

static size_t ft_strlen_const(const char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}



/*
Cette fonction va supprimer tout les chars qui égalent int c en début et fin de chaine de s1.
Cette fonction comporte plus de 25 ligne mais est très clair telle quelle.
*/

char    *ft_strtrimchr(const char *s1, int c){
	size_t start;
	size_t end;
	size_t tmp;
	size_t i;
	char	*str;

	start = 0;
	end = ft_strlen_const(s1) - 1;
	i = 0;
	if(s1 == NULL)
		return(NULL);
	while(s1[start] == (unsigned char)c && s1[start] != '\0')
		start++;
	tmp = start;
	while(end > start && s1[end] == (unsigned char)c)
		end--;
	str = (char *)malloc(((end - start) + 2) * sizeof(char));
	if(str == NULL)
		return(NULL);
	while(i < (end - start  + 1)){
		str[i] = s1[tmp];
		i++;
		tmp++;
	}
	str[i] = '\0';
	return(str);
}