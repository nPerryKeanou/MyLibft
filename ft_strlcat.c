#include "stddef.h"
#include "stdio.h"

static size_t ft_strlen(char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}

static size_t ft_strlen_const(const char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}

/*
La fonction strlcat fait partie de la famille de fonctions de manipulation de chaînes de caractères en C. 
Elle est conçue pour résoudre certains des problèmes associés à l'utilisation des fonctions strncpy et strncat, 
qui sont souvent sujettes à des erreurs.

Voici quelques points clés à noter :

Copie et Concaténation : strlcat effectue à la fois une copie et une concaténation. 
Cela signifie qu'elle peut être utilisée pour ajouter une chaîne source à une chaîne de destination, 
tout en garantissant que la destination reste null-terminée.

Paramètres d'Entrée/Sortie : Les paramètres d'entrée de strlcat incluent la chaîne de destination (dst), 
la chaîne source (src), et la taille de la chaîne de destination (dstsize). La taille dstsize spécifie la taille 
totale de l'espace alloué pour la chaîne de destination, y compris le caractère null de fin.

Conception pour la Sécurité : Cette fonction est conçue pour être plus sûre que strncat. 
Elle garantit que la chaîne résultante est toujours null-terminée, à condition que la taille totale de l'espace 
alloué (dstsize) soit suffisante pour contenir la chaîne de destination et la chaîne source.

Remplacement de fonctions précédentes : strlcat est suggérée comme un remplacement plus sûr pour les fonctions 
strncpy et strncat qui sont souvent mal utilisées. Les erreurs courantes avec strncpy et strncat incluent l'oubli 
du caractère null de fin ou l'utilisation incorrecte de la taille.

Valeur de Retour : Comme snprintf, strlcat retourne la longueur totale de la chaîne qu'elle a essayé de créer. 
Si la valeur de retour est supérieure ou égale à dstsize, cela signifie que la chaîne de destination a été tronquée.

En résumé, strlcat est une fonction conçue pour simplifier et sécuriser l'opération de concaténation de chaînes de caractères en C, 
en évitant les erreurs courantes liées aux fonctions similaires dans la bibliothèque standard




La fonction strlcat concatène la chaîne source (src) à la fin de la chaîne de destination (dst) en 
respectant la taille spécifiée (dstsize). Voici un résumé du comportement de strlcat :

La fonction vérifie si la chaîne de destination (dst) a suffisamment d'espace pour accueillir la 
concaténation de la chaîne source (src) et le caractère nul de fin de chaîne ('\0').

Si l'espace est suffisant, elle copie les caractères de la chaîne source (src) à la suite de la chaîne destination (dst), 
en s'arrêtant si elle atteint la taille maximale spécifiée (dstsize) ou si elle atteint le caractère nul de fin de chaîne de la chaîne source.

La fonction s'assure toujours de terminer la chaîne résultante par le caractère nul de fin de chaîne ('\0').

Elle renvoie la longueur totale de la chaîne résultante si elle est inférieure à dstsize, sinon elle renvoie dstsize + strlen(src).

L'utilisation de strlcat est recommandée lorsqu'on veut concaténer des chaînes en C de manière sécurisée,
 évitant ainsi le dépassement de tampon.

*/
size_t ft_strlcat(char	*dst, const char	*src, size_t dstsize){
	size_t len_dst;
	size_t len_src;
	size_t i;
	size_t j;
	size_t rest;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen_const(src);
	if(dst != NULL && src != NULL && dstsize > 0){
		rest = dstsize - len_dst - 1;
		i = len_dst;
		j = 0;
		while(j < rest && src[j] != '\0'){
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
		printf("- - - - - -%s - - - - -\n", dst);
		return(len_dst + len_src);
	}else{
		return(len_dst + len_src);
	}
	return(0);
}