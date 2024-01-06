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


//je vais partir du principe que je ne dois supprimer la partie de s1 
//en debut et fin de chaine, le morceau qui ègale à set.
//
//je ferais une autre fonnction qui elle, surrpimer tout les élément qui égalera chaque char de set un à un,
//jusqu'a ce que l'element s1[x] != d'un element x de set.

//pour trim, on doit juste faire un strnstr pour trouver la premiere occurance de chaine des le debut, 
//si il y en pas, on change rien et on passe à la suite.
//on doit trouver la derniere occurence du premiere char de set dans s1, si il y a rien, on fait rien. Sinon,
// on check si il y a une une occurence de chaien à partir du pointeur retrouenr ac l'occurence et on change la valeur de l'occurence en '\0'

//1) faire un strnstr
//  si il y a un retour de strnstr, on doit créer une nouvelle chaine en partant de s1[strnstr]
//2) on regarde si strrch de st[0] == ok,
//  si oui, on vérifie un strnstr de s1[strrchr[0]]
//   si oui, on modifie s1 en changeant la valeur de s1[strrchr[0]] en '\0' 


char    *ft_strtrim(const char *s1, const char    *set){
    //si il y a une occurence de set au debut de s1
    if(ft_strnstr(s1, set, ft_strlen_const(set)) != NULL){
        //si on trouve une occurence en partant de la fin
        if(ft_strrchr(s1, set[0]) != NULL){
            //trouver une occurence de chaine de set dans s1, à partir de s1[strrch]
                //crrer un malloc de s1 - set - set
            
        }
    }
}   