#include "stdlib.h"
#include "stdio.h"

/*
Alloue (avec malloc(3)) et retourne un tableau
de chaînes de caractères obtenu en séparant ’s’ à
l’aide du caractère ’c’, utilisé comme délimiteur.
Le tableau doit être terminé par NULL.
*/
/*
    function returnNbSeparateur().
    1)      trouver le nombre de int c dans la chaine S;
    1.2)    le nb de int c donnera la taille du tableau. car un séparateur équivaut +/- à deux mots.
    1.3)    Donc si il y a 10 mot, il est censer avec 5 délimiteur (si il ne commence et ne fini pas las chaine. Et que l'on utilise que 1 seul délimitieur à la fois.)
    1.4)    Donc, il faut parcourir la chaine s1 et incrémenter une variable lorsque qeu l'on tombe sur un séparateur.
    1.5)    Il ne faut pas compter si le séparateur commence et/ou fini la chaine. Ou si il y a plusieurs séparateur d'affilé.

    1.1) il faudra peut être une fonction qui check si c'est un char norml ou un séparateur.

    2)  Une fois qu'on a le nb exactement de séparation, on a la taille du tableau + 1 pour le char '\0'.
        Une fois que le tableau est malloc, on doit parcourir la chaine s et lorsque la vérif des séprateur n'est pas ok, ca veut dire que c'est un mot.
        Donc on doit calculer sa taille, malloc dans l'index correct du tableau et ensuite, stocker ces chars.
        Si un malloc ne fonctionne pas, on doit free tout ce qu'on a malloc avant. Donc on devrait avoir une boucle pour tout free.
*/

static size_t ft_strlen_const(const char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}


static int ft_isSeparate(int chr, int c){
    if((unsigned char)chr == (unsigned char)c){
        //oui c'est un séparateur
        return(1);
    }
    return(0);
}

//cette fonction retourne le nb de séparateur en omettant le premier et le dernier char car ils ne séparent pas de chaines et les multiplications de séparateurs.
//ce retourne nous donnera taille du tableau.
static size_t ft_nbSep(const char *s, int c, size_t len_s){
    size_t nbSep;
    size_t i;

    nbSep = 0;
    i = 0;
    while(s[i] != '\0'){
        if(i == 0 && ft_isSeparate(s[0], c) == 1){
            nbSep = nbSep;
        }
        if(i == len_s - 1 && ft_isSeparate(s[len_s - 1], c) == 1){
            nbSep = nbSep;
        }
        if(ft_isSeparate(s[i], c) == 1 && ft_isSeparate(s[i + 1], c) == 1){
            while(ft_isSeparate(s[i], c) == 1){
                i++;
            }
            nbSep += 1;
        }else if(ft_isSeparate(s[i], c) == 1 && ft_isSeparate(s[i + 1], c) == 0){
            nbSep++;
        }
        i++;
    }
    return(nbSep);
}

//cette fonction va recevoir un pointeur ( l'endroit ou commence un mot apres avoir trouver un séparateur)
//à partir de ce pointeur, on va calculer le nb d'octet à malloc et le retourner.
//à la place de retourner un size, je peux essaier de retourner une chaine.
//donc apres avoir trouver la size, je peux malloc ici et stocker la sous chaine
static char  *ft_len_sousChaine(const char *s, int c, char *ptr){
    size_t len;
    size_t i;
    //déclarer un nouveau pointeur et copier la valeur du pointeur passé en paramêtre
    char *copie_ptr;
    char *tmp_ptr;
    char *str;

    len = 0;
    i = 0;
    copie_ptr = ptr;
    tmp_ptr = ptr;
     // Utilisez la copie du pointeur dans votre fonction
    while(ft_isSeparate(s[*copie_ptr], c) == 0){
        len++;
        *copie_ptr++;
    }
    if(len > 0){
        str = (char *)malloc(len + 1 * sizeof(char));
        if(str == NULL){
            return(NULL);
        }
        while(i < len){
            str[i] = tmp_ptr;
            i++;
            tmp_ptr++;
        }
    }
    return(str);
}



char **ft_split(const char *s, int c){
    size_t i ;
    size_t nbSep;
    size_t len_s;
    size_t iTab;
    char **tabStr;
    char    *str;

    i = 0;
    len_s = ft_strlen_const(s);
    nbSep = ft_nbSep(s, c, len_s);
    iTab = 0;
    if(s != NULL && nbSep > 0){
        *tabStr = (char *)malloc(nbSep + 1 * sizeof(char));
        if(tabStr == NULL){
            return(NULL);
        }
    }
    //ici on va parcourir la s pour check chaque char, pour voir si c'est un separateur ou non.
    //si ce n'est pas un séparateur, je lance la fn ft_len_souschaine.
    //cette fn va me renvoyer le nb de char du premier mot.
    //donc je devrais creer une sous chaine de tab[] en malloc.
    //je dois aussi ajouter les chars dans la sous chaien creer en deça.
    //puis je devrais incrémtener mon i de la len retourner
    while(s[i] != '\0'){
        if(ft_isSeparate(s[i], c) == 0){
            *tabStr[iTab] = ft_len_sousChaine(s, c, s[i]);
            if(tabStr[iTab] == NULL){
                //ici il faut une fn qui boucle tout les mallocs crées.
                
            }
        }else{
            i++;
        }
    }
}