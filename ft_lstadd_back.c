#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    if(lst == NULL || new == NULL)//vérifie si le pointeur vers la list ou si le nouveau maillon est null;
    {
        return;
    }
    if(*lst == NULL)//vérifie si la list est vide.
    {
        *lst = new;
        return;
    }
    t_list *newLst;

    newLst = *lst;
    while(newLst->next != NULL)
    {
        newLst = newLst->next;
    }
    newLst->next = new;
    new->next = NULL;
}