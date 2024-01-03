#include "stddef.h"

/*
Le mot-clé restrict dans le paramètre void *restrict dst de la fonction memcpy est une indication 
au compilateur que l'objet pointé par dst n'est pas accessible via un autre pointeur pendant 
la durée de vie de la fonction. Cela permet au compilateur d'effectuer certaines optimisations, 
car il peut supposer que les modifications apportées à l'objet pointé par dst ne proviennent que de l'exécution de la fonction memcpy.


DESCRIPTION
La fonction memcpy copie n octets depuis la zone mémoire src vers la zone mémoire dst. Si dst et src se chevauchent, le comportement est indéfini. Les applications dans lesquelles dst et src pourraient se chevaucher devraient utiliser memmove au lieu de memcpy.

PARAMÈTRES
dst: Pointeur vers la zone mémoire de destination où les données seront copiées.
src: Pointeur vers la zone mémoire source à partir de laquelle les données seront copiées.
n: Nombre d'octets à copier.
DESCRIPTION
dst: Pointeur vers la zone mémoire de destination où les données seront copiées.
src: Pointeur vers la zone mémoire source à partir de laquelle les données seront copiées.
n: Nombre d'octets à copier.

Il n'y a pas de retour en cas d'erreur donc il est dans le rôle du développeur de gérer l'espace mémoire et que les aeguments soient valides.



*/

//il faut que dst ne soit pas null.
// 

void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n){
    size_t i;
    unsigned char *ptr_dst;
    const unsigned char *ptr_src;

    i = 0;
    ptr_dst = dst;
    ptr_src = src;
    if(dst != NULL && src != NULL && n > 0){
            while(i < n){
                ptr_dst[i] = ptr_src[i];
                i++;
            }
    }
    return(dst);
}