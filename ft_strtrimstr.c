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


//fonction qui va parcour x char de s1 de la longueur de set, pour savoir si ils ont exactement les mêmes valeurs.
//si il y a une différence avant la fin de la boucle de set, on retourn 0.
//si tout est ok, on répète la boucle au cas ou il y aurait plusieurs set d'affilé dans s1. 
size_t ft_startingtrim(const char *paramS1,  const char *paramSet){
	size_t i;
	//int boole; //boole va être le boolean qui va relancer ou non la boucle si on retrouve un set dans s1(il faudrait peut être le faire en recursive.)
	
	i = 0;
	//boole = 1;
	while(i > ft_strlen_const(paramSet)){
		if(paramS1[i] != paramSet[i]){
			//ca vaut dire que le début de s1 est différent de set.
			//cela retourne un 0 et start vaudra 0
			return(0);
		}
		i++;
	}
	return(ft_strlen_const(paramSet));
}


//il faut une fonction qui boucle ft_startingtrim.
size_t	calculStart(const char *paramS1,  const char *paramSet, size_t starts){
	size_t rslt;

	rslt = 0;
	//ici l'appel de la fonction va faire qu'elle sera deja lance une premiere fois.
	//attention
	//ft_startingtrim return juste 0 ou la longueur de set. Il ne change pas le char, donc il va toujours retourner les mêmes réponses.
	//Il faut donc tout faire dans ft_startingtrim, il faut parcouris tant que set est présent, recommencer s'il y a toujours un set et incréenter la réponses. 
	while(ft_startingtrim(paramS1, paramSet) == ft_strlen_const(paramSet)){
		rslt += ft_startingtrim(paramS1, paramSet);
	}
}

/**
 * function qui va vérifier si set ce trouve bien en fin de chaine.
 * Si il y a un char different, on retourne 0 et end vaudra donc 0. 
*/
size_t ft_endingtrim(const char *paramS1, const char *paramSet){
	size_t i;
	size_t end;

	i = 0;
	end = ft_strlen_const(paramS1) - ft_strlen_const(paramSet);
	while(i < ft_strlen_const(paramSet)){
		if(paramS1[end - 1] != paramSet[i]){
			return(0);
		}
		i++;
	}
	return(ft_strlen_const(paramSet));
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