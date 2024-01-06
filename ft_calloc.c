#include "stddef.h"
#include "stdlib.h"


void    *ft_calloc(size_t count, size_t size){
    size_t i;
    int *tab;

    i = 0;
    tab = (int *)malloc(count * size);
    if(tab == NULL){
        return(NULL);
    }
    while(i < count){
        tab[i] = 0;
        i++;
    }
    return((void *)tab);
}