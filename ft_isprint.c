int ft_isprint(int c){
    if((unsigned char)c >= 040 && (unsigned char)c <= 0176){
        return(1);
    }
    return(0);
}