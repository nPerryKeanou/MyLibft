#include "libft.h"

void    ft_lstclear(t_list **lst, void(*del)(void))
{
     if (lst == NULL || del == NULL) {
        return;
    }

    t_list *current = *lst;
    t_list *next;

    while (current != NULL){
        next = current->next;  // Sauvegarde du pointeur vers le prochain maillon avant de le supprimer
        del(current->content); // Utilisation de la fonction 'del' pour supprimer le contenu du maillon
        free(current);         // Libération de la mémoire du maillon
        current = next;        // Déplacement vers le prochain maillon
    }

    *lst = NULL;  // Le pointeur initial est mis à NULL
}