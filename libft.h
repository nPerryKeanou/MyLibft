#ifndef LIBFT
#define LIBFT

int ft_isalpha(int c);
int ft_islower(int c);
int ft_isupper(int c);
int ft_isdigit(int c);
int ft_isalnum(int c);
int ft_isascii(int c);
int ft_isprint(int c);
int ft_toupper(int c);
int ft_tolower(int c);

size_t  ft_strlen(const char *s);
size_t  ft_strlcpy(char    *dst, const char   *src, size_t dstsize);
size_t  ft_strlcat(char *dst, const char *src, size_t dstsize);

void    *ft_memset(void *b, int c, size_t len);
void    *ft_memcpy(void *dst, const void *src, size_t n);
void    ft_bzero(void *s, size_t n);
void    *ft_memmove(void *dst, const void *src, size_t len);

#endif