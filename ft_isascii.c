//La fonction isascii() teste la présence d'un caractère ASCII, qui est tout caractère compris entre 0 et octal 0177 inclusivement.

int ft_isascii(int c){
    if((unsigned char)c >= 001 && (unsigned char)c <= 0177){
        return(1);
    }
    return(0);
}