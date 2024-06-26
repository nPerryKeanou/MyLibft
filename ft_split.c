#include "libft.h"

static int ft_isSeparate(int chr, int c){
    return (unsigned char)chr == (unsigned char)c;
}

static size_t ft_nbSep(const char *s, int c, size_t len_s){
    size_t nbSep = 0;
    size_t i = 0;

    while (i < len_s) {
        while (i < len_s && ft_isSeparate(s[i], c)){
            i++;
        }
        while (i < len_s && !ft_isSeparate(s[i], c)){
            i++;
        }
        nbSep++;
    }
    return nbSep;
}

static char *ft_strndup(const char *src, size_t n){
    char *dest = (char *)malloc(n + 1);
    if (dest == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    dest[n] = '\0';

    return dest;
}

char **ft_split(const char *s, int c){
    size_t len_s = ft_strlen_const(s);
    size_t nbSep = ft_nbSep(s, c, len_s);
    size_t iTab = 0;

    size_t i = 0;
    if (s == NULL){
        return NULL;
    }
    char **tabStr = (char **)malloc((nbSep + 1) * sizeof(char *));
    if (tabStr == NULL){
        return NULL;
    }
    while (i < len_s){
        while (i < len_s && ft_isSeparate(s[i], c)){
            i++;
        }
        size_t start = i;
        while (i < len_s && !ft_isSeparate(s[i], c)){
            i++;
        }
        tabStr[iTab] = ft_strndup(s + start, i - start);
        if (tabStr[iTab] == NULL) {
            for (size_t j = 0; j < iTab; j++) {
                free(tabStr[j]);
            }
            free(tabStr);
            return NULL;
        }
        iTab++;
    }
    tabStr[iTab] = NULL;
    return tabStr;
}