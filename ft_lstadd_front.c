#include "libft.h"

//fonction poiur ajouter un maillon en début de liste.
void    ft_lstadd_front(t_list **lst, t_list *new)
{
    if(lst == NULL || new == NULL)
    {
        return;
    }
    new->next = *lst;//affecte l'adresse du premier maillon actuel a champ next du maillon suivant.
    *lst = new;//met à jour l'adresse du premier maillon pour pointer vers le nouveau maillon.
}