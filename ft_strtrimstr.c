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
	printf("start ------- paramS1[i] = %c  == paramSet[j] = %c\n", paramS1[i], paramSet[j]);
	while(paramS1[i] != '\0' && paramS1[i] == paramSet[j]){
		//si j egale la lonueur de set - 1 car on commence j à zero.
		printf(" - - - - - i = %zu && rslt = %zu\n",i,rslt);
		if(paramS1[i] == paramSet[j] && j == ft_strlen_const(paramSet) - 1){
			rslt += 1;
			j = 0;
		}else if(paramS1[i] == paramSet[j] && j < ft_strlen_const(paramSet) - 1){
			j++;
		}
		else{
			return(rslt);
		}
		i++;
	}
	printf(" - - - - - i = %zu && rslt = %zu\n",i,rslt);
	printf("start ------- paramS1[i] = %c  == paramSet[j] = %c\n", paramS1[i], paramSet[j]);// pourquoi paramS1[i] n'affiche rien ?
	//printf("paramS1 --> %s\n", paramS1);
	//printf("i --> %zu\n", i);
	//printf("paramS1[i] --> %c\n", paramS1[i]);
	//paramS1[i] == ' ';
	return(rslt);
}



/**
 * function qui va vérifier si set ce trouve bien en fin de chaine.
 * Si il y a un char different, on retourne 0 et end vaudra donc 0. 
*/
size_t ft_endingtrim(const char *paramS1, const char *paramSet){
	size_t rslt;
	size_t i;;
	size_t end;
	size_t len_set;
	int booleTrue;

	rslt = 0;
	i = 0;
	booleTrue = 1;
	end = ft_strlen_const(paramS1);//longueur total de la chaine, donc ex : 10 char.
	len_set = ft_strlen_const(paramSet);
	//end = ft_strlen_const(paramS1 - 1);Ceci est la longueur - 1 donc pour préciser que l'on commence un index à 0.
	//on doit boucler sur tout les chars de s1 en partant de la fin.
	//On ne démarre pas exactement de la fin mais de la longueu de s1 - la longuer de set. Et comme on va utiliser des index, on va retirer 1.
	//On boucle tant que s1[len_total - len_set - 1] == set[i]
	//	si s1[len_total - len_set - 1] == set[i] && i == len_set, on incrémente rslt et on décrémente end - len_set

	printf("---------------------- 1 --------------------\n");
//	while(paramS1[end - len_set - 1] == paramSet[i]){
	while(booleTrue == 1){
		printf("---------------------- 2 --------------------\n");
		//len_set - 1 car on commence i à 0
		if(paramS1[end - len_set - 1] == paramSet[i] && i == len_set - 1){
			printf("----------------------3 --------------------\n");
			rslt += 1;
			i = 0;//ici je remets la set à l'index 0 
			//je dois aussi décrémenter de len set la chaine s1 pour relancer la boucle
			end -= len_set;
		}else if(paramS1[end - len_set - 1] == paramSet[i] && i < len_set){
			printf("---------------------- 4 --------------------\n");
			end--;
		}else{
			printf("---------------------- 5 --------------------\n");
			booleTrue = 0;
			return(rslt);
		}
		i++;
		printf("---------------------- 6 --------------------\n");
	}
	printf("---------------------- 7 --------------------\n");
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
	printf("---- 1 -----\n");
	if(s1[i] != set[i])
	{
		printf("---- 2 -----\n");
		start = 0;
	}else{
		printf("---- 3 -----\n");
		//cette fonction va retourner un size_t, qui selon la fn peut etre un de la taille de set ou de x * set 
		//
		//ici, il faudrait avoir un fn qui incrémente start tant qu'il retourne "true"
		// il faudrait boucler directement dans ft_startingtrim
		start = ft_startingtrim(s1,  set);
		
	}
	printf("---- 4 -----\n");
	if(s1[lens1 - ft_strlen_const(set) - 1] != set[i]){
		printf("---- 5 -----\n");
		printf("s1[lens1 - ft_strlen_const(set) - 1] --> %c\n",s1[lens1 - ft_strlen_const(set) - 1]);
		end = 0;
	}else{
		//cette fonction va retourner un size_t, qui selon la fn peut etre un de la taille de set ou de x * set 
		//
		//ici, il faudrait avoir un fn qui incrémente end tant qu'il retourne "true"
		printf("---- 6 -----\n");
		end = ft_endingtrim(s1, set);
	}
	printf("---- 7-----\n");
	str = (char *)malloc(lens1 - start - end + 2 * sizeof(char));
	if(str == NULL){
		return(NULL);
	}
	printf("---- 8 -----\n");
	while(s1[i] != '\0' && i < lens1 - start - end){
		printf("---- 9 -----\n");
		str[i] = s1[start];
		i++;
		start++; 
	}
	printf("---- 10 -----\n");
	str[i] = '\0';
	printf("---- 11 -----\n");
	return(str);
}   