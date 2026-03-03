#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    if (s == NULL)
        return (NULL);

    while (*s != '\0')
    {
        if (*s == (unsigned char)c)
        {
            return ((char *)s);
        }
        s++;
    }
    
    if ((unsigned char)c == '\0')
    {
        return ((char *)s);
    }

    return (NULL);
}