#ifndef LIBFT_H
# define LIBFT_H

/* --- Standard Libraries --- */
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <stdarg.h> /* Indispensable pour les (...) de ft_printf */

/* --- Configuration GNL --- */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

/* --- Structures --- */
typedef struct s_list
{
    void            *content;
    struct s_list   *next;
}               t_list;

/* --- Fonctions de base (Libft) --- */
int     ft_isalpha(int c);
int     ft_islower(int c);
int     ft_isupper(int c);
int     ft_isdigit(int c);
int     ft_isalnum(int c);
int     ft_isascii(int c);
int     ft_isprint(int c);
int     ft_toupper(int c);
int     ft_tolower(int c);

long long int ft_atoi(const char *str);
// long long int ft_atoi_long(const char *str); /* Pour ton ft_atoi actuel */

size_t  ft_strlen(const char *s);
size_t  ft_strlen_const(const char *s);
size_t  ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);

char    *ft_strchr(const char *s, int c);
char    *ft_strrchr(const char *s, int c);
char    *ft_strnstr(const char *haystack, const char *needle, size_t len);
char    *ft_strdup(const char *s1);
char    *ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strjoin(const char *s1, const char *s2);
char    *ft_strtrimchr(const char *s1, int c);
char    *ft_strtrimchr_multi(const char *s1, const char *set);
char    *ft_strtrimstr(const char *s1, const char *set);
char    *ft_itoa(int nb);
char    *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char    **ft_split(const char *s, int c);
char    *ft_strcpy(char *dest, char *src);

void    *ft_memset(void *b, int c, size_t len);
void    *ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);
void    *ft_memchr(const void *s, int c, size_t n);
int     ft_memcmp(const void *s1, const void *s2, size_t n);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    *ft_calloc(size_t count, size_t size);
void    ft_striteri(char *s, void (*f)(unsigned int, char *));

/* --- Affichage --- */
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_putchar_fd(char c, int fd);
void    ft_putstr_fd(char const *s, int fd);
void    ft_putendl_fd(char *s, int fd);
void    ft_putnbr(int nb);

/* --- Listes (Bonus) --- */
t_list  *ft_lstnew(void *content);
void    ft_lstadd_front(t_list **lst, t_list *new);
int     ft_lstsize(t_list *lst);
t_list  *ft_lstlast(t_list *lst);
void    ft_lstadd_back(t_list **lst, t_list *new);
void    ft_lstdelone(t_list *lst, void (*del)(void*));
void    ft_lstclear(t_list **lst, void (*del)(void*));
void    ft_lstiter(t_list *lst, void (*f)(void *));
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* --- FT_PRINTF --- */
int     ft_printf(const char *format, ...);
int     printf_c(char c);
int     printf_nb_string(char *str);
int     printf_nb_pointeur(void *ptr);
int     ft_putnbr_d_i(int nb);
int     ft_putnbr_u(unsigned int nb);
// int     ft_putnbr_base(long int nbr, char *base);
void    ft_putnbr_base(unsigned long long int n, char *base, int *count);

/* --- GET_NEXT_LINE --- */
char    *get_next_line(int fd);
char    *ft_get_static(int fd, char *tmp_line_static, size_t *nb_read_param);
char    *ft_get_line_return(char *line_static_param);
char    *ft_new_static(char *line_static_param, char *line_return_param);

#endif