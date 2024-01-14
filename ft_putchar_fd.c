#include "libft.h"

void    ft_putchar_fd(char c, int fd){
    int descriptor;
    int rslt;

    //0644. C'est une représentation octale des autorisations (permissions) du fichier
    descriptor = open(fd, O_WRONLY | O_CREAT | 0644);
    if(descriptor != -1){ 
        rslt = write(descriptor, &c, sizeof(char));
    }
    close(descriptor);
}