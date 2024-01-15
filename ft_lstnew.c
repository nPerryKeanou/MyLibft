#include "libft.h"

t_list  *ft_lstnew(void *content){
    t_list *newLink;

    newLink = (t_list*)malloc(sizeof(t_list));
    if(newLink == NULL)
    {
        return(NULL);
    }
    newLink->content = content;
    newLink->next = NULL;
    return(newLink);
}