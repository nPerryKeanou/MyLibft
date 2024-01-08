#include "stddef.h"
#include "stdlib.h"
#include "stdio.h"

static size_t ft_strlen_const(const char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}


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
	int tmp;

	i = 0;
	j = 0;
	tmp = 0;
	//parcourir le s1
	while(s1[i] != '\0'){
		//parcourir set
		while(set[j] != '\0'){
			//comparer s1[i] à tout les set[j]
			//si s1[i] est bien dans la char* set, on donne la valeur 1 à tmp
			if(s1[i] == set[j]){
				tmp = 1;
			}else if(s1[i] != set[j]){
				tmp = 0;
			}
			
			//on continue la boucle
			j++;
		}
		//si s1[i] n'est pas dans char* set, tmp n'a pas recu la valeur de 1 et vaudra tjrs 0.
		//donc ca veux dire que le trim va s'arreter ici et on va retourner le nb de boucle que l'on a fait.
		//le nb de boucles nous indiques l'index de s1[], donc de l'endroit ou va s'arreter le trim.
		if(tmp == 0){
			return(i);
		}
		j = 0;
		i++;
	}
	return(i);
}

//endStr va parcourir s1 en comparer s1[lens1] -- à chaque set[], jusqu'au moment ou un s1[x] ne sera pas dans *set
//c'est a cette valeur, que l'on devra arreter le trim. Donc start prendre le nb de boucle que l'on a jusque la.
//on va parcourir jusqu'a start
size_t	endStr(const char *s1, const char *set, size_t start){
	//ici on commence de la fin, donc on donne a end, la taille de s1 - 1 (car on n'oublie pas que l'on commence à 0)
	size_t end;
	size_t i;
	int tmp;

	end = ft_strlen_const(s1) - 1;
	tmp = 0;
	while(end > start){
		i = 0;
		while(set[i] != '\0'){
			//on peut directement donner 1 cmme valeur à tmp et si jamais s1[end] != de set
			if(s1[end] == set[i]){
				tmp = 1;
			}else if(s1[end] != set[i]){
				tmp = 0;
			}
			i++;
		}
		if(tmp == 0){
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
	printf("start --> %zu\n",start);
	end = endStr(s1, set, start);
	printf("end --> %zu\n",end);
	i = 0;
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