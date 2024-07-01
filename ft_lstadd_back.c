#include "libft.h"

void    ft_lstadd_back(t_list **lst, t_list *new)
{
    if(lst == NULL || new == NULL)
    {
        return;
    }
    if(*lst == NULL)
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