//  La fonction isdigit() en langage C teste la présence d'un caractère décimal.
//  Indépendamment de la localisation, cela inclut uniquement les caractères suivants :
//  0'' 1'' 2'' 3'' 4'' 5'' 6'' 7'' 8'' 9''``
int ft_isdigit(int c){
    if((unsigned char)c >= 48 && (unsigned char)c <= 57){
        return(1);
    }
    return(0);
}

