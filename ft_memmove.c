//#include "stddef.h"
/**
 * 
 * LORSQUE L'ON TRAVAILLE AVEC DES POINTEURS EN LANGAGE C, IL EST IMPORTANT DE COMPRENDRE QU'UN POINTEUR EST SIMPLEMENT UN VARIABLE
 * QUI STOCK UN ADRESSE MÉMOIRE.
 * 
 * 
La comparaison des adresses mémoire dans la fonction ft_memmove permet de déterminer 
l'orientation de la copie. Elle permet de gérer le cas où les zones mémoire source et destination se chevauchent.

Si ptr_dst est inférieur à ptr_src, cela signifie que la copie doit être effectuée de 
gauche à droite (de début à fin) sans risque de corruption des données, car la destination est située après la source. Cela correspond à la première partie de la fonction ft_memmove.

Si ptr_dst est supérieur à ptr_src, cela signifie que la copie doit être effectuée de 
droite à gauche (de fin à début) pour éviter de corrompre les données. Cela correspond à la deuxième partie de la fonction ft_memmove.

En résumé, la comparaison des adresses mémoire est utilisée pour déterminer la direction de 
la copie (gauche à droite ou droite à gauche) en fonction de la relation relative entre les adresses de la source et de la destination. 
Cela garantit que la copie se fait correctement, même en cas de chevauchement des zones mémoire.

En C, l'arithmétique des pointeurs est conçue pour être compatible avec les types de données pointés. Le size_t est un type entier sans signe utilisé pour représenter la taille d'objets, 
y compris la taille d'un tableau ou la distance entre deux pointeurs.

Les copies d'adresse mémoires dans les fonctions sont éphémère, ells disparaissent lorsque la fonctions s'arrete.
Donc on travaille sur une copie mais on ne modofie pas la variable copié.
Une fois le boulot fini, on retourne la variable copié.
Mais si on fait une erreur dans notre copie et que l'on retourne la variable copié, on aura un problème au final.
C'est au développeur à faire attention à ne pas faire d'erreur avant d'avoir changé la copie et d'avoir return la variable.

Dans la fonction ft_memmove que vous avez montrée, l'idée est d'éviter les problèmes de chevauchement lors de la copie des données. 
La copie temporaire ptr_dst est utilisée pour travailler sur une copie de la mémoire source tout en 
évitant de compromettre la zone de mémoire de destination qui n'a pas encore été copiée.

Ainsi, si vous modifiez ptr_dst, cela n'affectera pas directement dst en dehors de la fonction. 
dst a toujours la même valeur d'adresse, mais si vous modifiez ptr_dst dans la fonction, 
cela n'aura pas d'impact sur dst à l'extérieur de la fonction.
*/


void    *ft_memmove(void *dst, const void *src, size_t len){
    size_t i;
    unsigned char   *ptr_dst;
    unsigned char   *ptr_src;

    i = 0;
    ptr_dst = dst;//ptr_dst copie l'adresse de dst, donc on peut travailler sur une copie de dst sans toucher à celui ci. 
    ptr_src = src;
    if(ptr_dst == ptr_src){
        return(dst);
    }
    if(ptr_dst != NULL && ptr_src != NULL){
        if(ptr_dst < ptr_src){
            //copie de gauche à droite.
            while(len--){
                *ptr_dst++ = *ptr_src;
            }
        }else if(ptr_dst > ptr_src){
            //copie de droite à gauche. Bouge le pointeur à la fin
            ptr_dst += len;
            ptr_src += len;
            while(len--){
                *(--ptr_dst) = *(--ptr_src);
            }
        }
    }
    return(dst);
}