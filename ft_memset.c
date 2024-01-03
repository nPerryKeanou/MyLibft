
/*
DESCRIPTION
La fonction memset() écrit len octets de la valeur c (convertie en unsigned char) dans la chaîne b.

VALEURS DE RETOUR
La fonction memset() renvoie son premier argument.

Explication :

memset() est une fonction en langage C qui remplit un bloc de mémoire avec une valeur donnée.

Les paramètres de la fonction sont :

b : Un pointeur vers le début de la zone mémoire à remplir.
c : La valeur à écrire, convertie en unsigned char.
len : Le nombre d'octets à remplir.
La fonction remplit la zone mémoire pointée par b avec la valeur c répétée len fois.

La valeur de retour de memset() est le pointeur vers le début de la zone mémoire modifiée, 
ce qui est généralement équivalent à son premier argument (b).

En résumé, memset() est utilisée pour initialiser un bloc de mémoire avec une valeur spécifiée, 
et elle renvoie un pointeur vers le début de cette zone mémoire.
*/


/*
Explications :

unsigned char *ptr = b; : Déclaration d'un pointeur ptr de type unsigned char qui pointe vers la zone de mémoire spécifiée par b. Cela permet de traiter les octets individuellement.

ptr[i] = (unsigned char)c; : Affectation de la valeur c (convertie en unsigned char) à chaque octet de la zone de mémoire pointée par ptr.

return b; : Retour du pointeur vers le début de la zone mémoire, similaire à la fonction memset standard.
*/
void    *ft_memset(void *b, int c, size_t len){
    size_t i;
    unsigned char *ptr = b;
    i = 0;
    while(i < len){
        ptr[i] = (unsigned char)c;
        i++;
    }
    return(b);
}