#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"



void    ft_putchar(char c){
    write(1, &c, 1);
}

void    ft_putstr(char *str){
    int i;

    i = 0;
    while(str[i] != 0){
        ft_putchar(str[i]);
        i++;
    }
}

size_t ft_strlen(char   *str){
    size_t i;

    i = 0;
    while(str[i] != 0){
        i++;
    }
    return(i);
}



int main(void){
    char    *str = "bonjour les gens\n";
    char    a = 'a';
    char    b = 'b';
    int     one = 1;
    ft_putstr(str);
    ft_putchar('\n');
    printf("rslt de ft_isalpha(a) --> %d \n",ft_isalpha(a));
    printf("rslt de ft_islower(a) --> %d \n",ft_islower(a));
    printf("rslt de ft_isupper(a) --> %d \n",ft_isupper(a));
    ft_putchar('\n');
    ft_putchar('\n');
    printf("rslt de ft_isalpha(one) --> %d \n",ft_isalpha(one));
    printf("rslt de ft_islower(one) --> %d \n",ft_islower(one));
    printf("rslt de ft_isupper(one) --> %d \n",ft_isupper(one));
    ft_putchar('\n');
    return(0);
}