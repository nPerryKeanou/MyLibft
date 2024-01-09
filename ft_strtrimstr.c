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


//fonction qui va parcour x char de s1 de la longueur de set, pour savoir si ils ont exactement les mêmes valeurs.
//si il y a une différence avant la fin de la boucle de set, on retourn 0.
//si tout est ok, on répète la boucle au cas ou il y aurait plusieurs set d'affilé dans s1. 
size_t ft_startingtrim(const char *paramS1,  const char *paramSet){
	size_t rslt;//cette variable va renvoyer le nb de fois où l'on trouve set OU le nb de chars  à trim (qui se le nombre de boucle de while * set)
	size_t i;
	size_t j;

	rslt = 0;
	i = 0;
	j = 0;
	while(paramS1[i] != '\0' && paramS1[i] == paramSet[j]){
		//si j egale la lonueur de set - 1 car on commence j à zero.
		if(paramS1[i] == paramSet[j] && j == ft_strlen_const(paramSet - 1)){
			printf("ft_strlen_const(paramSet - 1) --> %zu\n", ft_strlen_const(paramSet - 1));
			printf("paramS1[i] --> %c && paramSet[j] --> %c && j --> %zu\n", paramS1[i], paramSet[j], j);
			rslt += 1;
			j = 0;
		}else if(paramS1[i] == paramSet[j] && j < ft_strlen_const(paramSet - 1)){
			j++;
		}
		else{
			return(rslt);
		}
		i++;
	}
	return(rslt);
}



/**
 * function qui va vérifier si set ce trouve bien en fin de chaine.
 * Si il y a un char different, on retourne 0 et end vaudra donc 0. 
*/
size_t ft_endingtrim(const char *paramS1, const char *paramSet){
	size_t rslt;
	size_t i;
	size_t j;
	size_t end;
	size_t len_set;

	rslt = 0;
	i = 0;
	j = 0;
	end = ft_strlen_const(paramS1);//longueur total de la chaine, donc ex : 10 char.
	len_set = ft_strlen_const(paramSet);
	//end = ft_strlen_const(paramS1 - 1);Ceci est la longueur - 1 donc pour préciser que l'on commence un index à 0.
	//on doit boucler sur tout les chars de s1 en partant de la fin.
	//On ne démarre pas exactement de la fin mais de la longueu de s1 - la longuer de set. Et comme on va utiliser des index, on va retirer 1.
	//On boucle tant que s1[len_total - len_set - 1] == set[i]
	//	si s1[len_total - len_set - 1] == set[i] && i == len_set, on incrémente rslt et on décrémente end - len_set

	while(paramS1[end - len_set - 1] == paramSet[i]){
		//len_set - 1 car on commence i à 0
		if(paramS1[end - len_set - 1] == paramSet[i] && i == len_set - 1){
			rslt += 1;
			i = 0;//ici je remets la set à l'index 0 
			//je dois aussi décrémenter de len set la chaine s1 pour relancer la boucle
			end -= len_set;
		}else if(paramS1[end - len_set - 1] == paramSet[i] && i < len_set){
			end++;
		}else{
			return(rslt);
		}
		i++;
	}
	return(rslt);
}
/*
Cette fonction va supprimer le debut et fin de chaine de s1 si on retouve exactement set en debut et fin.
Ici, on va chercher la premiere occurence de s1 et set.
Si la premier char de s1 n'est pas une occurence de set, on peut return 0 pour start
Si s1[lens1 - len_set - 1] n'est pas une occurence de set, on peut return 0
SINON
SI il y a occurence, on donne le pointeur de l'occurence à la fonction qui va check si les char qui suivent forment exacetement set.
Si oui, la fn return true.
à partir de la, on peux trim len_set.
On recommence la boucle tant qu'on trouve l'occurence des chars 0 de set et de s1
*/
char    *ft_strtrimstr(const char *s1, const char    *set){
	size_t i;
	size_t start;
	size_t end;
	size_t lens1;
	char	*str;

	i = 0;
	lens1 = ft_strlen_const(s1);
	if(s1[i] != set[i])
	{
		start = 0;
	}else{
		//cette fonction va retourner un size_t, qui selon la fn peut etre un de la taille de set ou de x * set 
		//
		//ici, il faudrait avoir un fn qui incrémente start tant qu'il retourne "true"
		// il faudrait boucler directement dans ft_startingtrim
		start = ft_startingtrim(s1,  set);
		
	}
	if(s1[(lens1 - 1) - ft_strlen_const(set)] != set[i]){
		end = 0;
	}else{
		//cette fonction va retourner un size_t, qui selon la fn peut etre un de la taille de set ou de x * set 
		//
		//ici, il faudrait avoir un fn qui incrémente end tant qu'il retourne "true"
		end = ft_endingtrim(s1, set);
	}
	str = (char *)malloc(lens1 - start - end + 2 * sizeof(char));
	if(str == NULL){
		return(NULL);
	}
	while(s1[i] != '\0' && i < lens1 - start - end){
		str[i] = s1[start];
		i++;
		start++; 
	}
	str[i] = '\0';
	return(str);
}   