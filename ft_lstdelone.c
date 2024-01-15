#include "libft.h"

void    ft_lstdelone(t_list *lst, void (*del)(void*))
{
    if (lst == NULL || del == NULL) {
        return;
    }

    // Utiliser la fonction 'del' pour supprimer le contenu de 'lst'
    del(lst->content);

    // Libérer la mémoire de 'lst'
    free(lst);
}
