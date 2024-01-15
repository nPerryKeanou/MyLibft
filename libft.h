#ifndef LIBFT
#define LIBFT

#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "stddef.h"
#include "limits.h"
#include "tcl.h"
#include "fcntl.h"
#include <sys/types.h>

char    *ft_strchr(const    char    *s, int c);
char    *ft_strrchr(const char *s, int c);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
char    *ft_strdup(const char  *s1);
char    *ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strtrimchr(const char *s1, int c);
char    *ft_strtrimchr_multi(const char *s1, const char    *set);
char    *ft_strtrimstr(const char *s1, const char    *set);
char    *ft_itoa(int nb);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));

char **ft_split(const char *s, int c);

int ft_isalpha(int c);
int ft_islower(int c);
int ft_isupper(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);
int ft_memcmp(const void *s1, const void *s2, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);

long long int ft_atoi(const char *str);

size_t  ft_strlen(char *s);
size_t ft_strlen_const(const char   *str);
size_t  ft_strlcpy(char    *dst, const char   *src, size_t dstsize);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);

void    *ft_memset(void *b, int c, size_t len);
void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memchr(const void   *s, int c, size_t n);
void    *ft_calloc(size_t count, size_t size);
void    ft_striteri(char *s, void (*f)(unsigned int, char *));
void    ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putstr_fd(char const *s, int fd);
void	ft_putnbr(int nb);

#endif