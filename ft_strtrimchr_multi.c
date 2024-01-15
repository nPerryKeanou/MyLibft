#include "libft.h"

//function qui boucle sur une chaine de char.
//le but est de comparer chaque caractere de str à chaque caracetere de set.
//donc on a une boucle sur tout les char de set
//	ensuite on a une boucle sur tout les char de set pour chaque char de str.
//		On a une variable tmp qui = 0;
//		donc si dans le tour de boucle de set, si str[x] == set, le tmp == 1, ca veut dire que le cha se trouve dans la list de set
//		Donc on ne doit pas continuer la boucle, on peut direct sortir de celle la et incrémenter la boucle mère.
//	On remets le compteur de la boucle enfant à 0
//	On relance la boucle mere à la valeur suivante
//	On boucle la valeu suivant dans la boucle enfant.
//	Si jamais str[x] est != de toute les valeurs de set, ca veut dire que str[x] ne se trouve pas dans set et donc on doit arreter le trim a cette place.
//	Donc tmp vaudra 1 et on peut quitter les deux boucle,
//	tmp doit être des conditions pour les deux boucles.
// Dans tout les cas, on doit retourner le nb de boucles mere pour savoir ou commence ou non, le trim.



////////////////////////////cette fonction va boucler sur chaque char de s1 tant que s1[x] == un char de set.
//ensuite, il retourne le nb de fois qu'on a boucle pour savoir ou commencer le debut de la nouvelle chaine.
//boucler sur s1 tant que s1[] != '\0' et boole == 1
//	le boole va faire en sorte que si boole == 1,
//startStr va parcourir s1 en comparer s1[x] à chaque set[], jusqu'au moment ou un s1[x] ne sera pas dans *set
//c'est a cette valeur, que l'on devra arreter le trim. Donc start prendre le nb de boucle que l'on a jusque la.
size_t	startStr(const char *s1, const char *set){
	size_t i;
	size_t j;
	int isPresent;


	i = 0;
	while(s1[i] != '\0'){
		j = 0;
		isPresent = 0;
		while(set[j] != '\0'){
			if(s1[i] == set[j]){
				isPresent = 1;//ca veut dire qu'il y a au minumum, une valeur qui peut etre trim.
				break;
			}
			j++;
		}
		if(isPresent == 0){//ca veut dire qu'il s1[i] n'egale aucu set[j], donc que le trim doit s'arreter
			return(i);
		}
		i++;
	}
	return(i);
}

//endStr va parcourir s1 en comparer s1[lens1] -- à chaque set[], jusqu'au moment ou un s1[x] ne sera pas dans *set
//c'est a cette valeur, que l'on devra arreter le trim. Donc start prendre le nb de boucle que l'on a jusque la.
//on va parcourir jusqu'a start
size_t	endStr(const char *s1, const char *set){
	size_t end;
	size_t i;
	int isPresent;

	end = ft_strlen_const(s1);
	printf("end --> len --> %zu\n", end);
	while(end > 0){
		isPresent = 0;
		i = 0;
		while(set[i] != '\0'){
			if(s1[end - 1] == set[i]){
				isPresent = 1;
				break;
			}
			i++;
		}
		if(isPresent == 0){
			return(end);
		}
		end--;
	}
	return(end);
}


/*
Cette fonction va supprimer tout les chars de s1 en début et fin de chaine qui se trouvent dans set.
Il faut ici, comparer s1[x] a chaque char dans set.

On boucle sur s1, on boucle pour vérifier chaque char de set.
//si ok char de set == le char de s1, on arrete de chercher au debut et on fais la fin.
*/
//ici on a les deux fonctions qui renvoie l'endroit ou commence et ou termine la nouvelle chaine si on la trim
char    *ft_strtrimchr_multi(const char *s1, const char    *set){
	size_t start;
	size_t end;
	size_t i;
	char	*str;

	start = startStr(s1, set);
	end = endStr(s1, set);
	i = 0;
	if (start == end) {
        char *emptyStr = (char *)malloc(1);
        if (emptyStr == NULL) {
            return NULL;
        }
        emptyStr[0] = '\0';
        return emptyStr;
    }
	str = (char *)malloc((end - start + 2) * sizeof(char));
	if(str == NULL){
		return(NULL);
	}
	while(start < end){
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return(str);
}   