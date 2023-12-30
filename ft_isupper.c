/*
    La fonction isupper() teste la présence de toute lettre majuscule. 
    La valeur de l'argument doit être représentable en tant qu'unsigned char ou avoir la valeur EOF.
*/

int ft_isupper(int c){
    if((unsigned char)c >= 65 && (unsigned char)c <= 90){
        return(1);
    }
    return(0);
}