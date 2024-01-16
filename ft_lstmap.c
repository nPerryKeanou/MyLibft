#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new_list;
	t_list *save;

    //1 Validation des paramètres.
	if (!lst || !f || !del)
		return (0);
    //2 Création du premier élément de la nouvelle liste.
	new_list = ft_lstnew(f(lst->content));
	if (!new_list)
		return (0);
    //3 Initialisation des pointeurs.
	save = new_list;
	lst = lst->next;
    //4 Boucle de création de la nouvelle liste.
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		if (!new_list->next)
		{
			ft_lstclear(&save, del);
			return (0);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
    //5 Fin de la nouvelle liste.
	new_list->next = NULL;
    //6 Renvoi de la nouvelle liste.
	return (save);
}