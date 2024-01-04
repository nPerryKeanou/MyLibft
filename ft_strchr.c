static size_t ft_strlen(char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
}

/**
 * 
 * La fonction strchr recherche la première occurrence du caractère spécifié c dans la chaîne de caractères pointée par s. 
 * La recherche inclut le caractère nul de fin de chaîne ('\0'). Si le caractère c est trouvé, 
 * la fonction renvoie un pointeur vers l'emplacement de ce caractère dans la chaîne. 
 * Si le caractère c n'est pas trouvé, la fonction renvoie NULL.
*/


char    *ft_strchr(const    char    *s, int c){
    size_t i;
    size_t len_s;

    i = 0;
    len_s = ft_strlen(s);
    if(s == NULL){
        return(NULL);
    }
    if((unsigned char)c == '\0'){
        //retourne direct la fin du la str s.
        return((char*)s+len_s);
    }
    while(*(s) != '\0'){
        if(*(s) == (unsigned char)c){
            //on retourne donc l'endroit, l'espace mémoire, où se trouve la premiere occurence. Et non sa valeur.
            //C'est pour ca que l'on convertit avec (char*), pour récuperer non la valeur mais l'adresse.
            //En résumé, (char*)s est une conversion de type, tandis que *s est une opération de déréférencement qui donne accès à la valeur à laquelle s pointe.
            return((char*)s);
        }
        s++;
    }
    return(NULL);
}