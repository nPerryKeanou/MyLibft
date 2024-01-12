#include "fcntl.h"
#include "stdlib.h"

void    ft_putchar_fd(char c, int fd){
    int descirptor;
    int rslt;

    //0644. C'est une représentation octale des autorisations (permissions) du fichier
    descirptor = open(fd, O_WRONLY | O_CREAT | 0644);
    if(descirptor != -1){ 
        rslt = write(descirptor, &c, sizeof(char));
    }
    close(descirptor);
}