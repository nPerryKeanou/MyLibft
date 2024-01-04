#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "libft.h"
#include "stddef.h"
#include "string.h"



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

/////////////////////////////////////////////////// isalpha, islower, isupper
/*
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
*/



//La fonction isdigit en langage C s'attend à recevoir un caractère
//(int représentant un caractère en code ASCII) en tant que paramètre, et non un entier int arbitraire.
/*
int main(void){
    int one = 1;
    int zero = 0;
    char a = '1';
    printf("ft_isdigit(1)   --> %d\n", ft_isdigit(one));
    printf("\n");
    printf("ft_isdigit(0)   --> %d\n",ft_isdigit(zero));
    printf("\n");
    printf(" ft_isdigit('1')   --> %d\n", ft_isdigit(a));
    printf("\n");
    return(0);
}
*/


////////// isalnum. 
//Dans la famille des fn isalnum, isdigit, isalpha,..., le int en paramêtre ne doit pas être n'importe qu'elle nb.
//Car ce int doit valoir un nb en ascii. Donc int c --> 49  vaut en ascii 49 et --> 57 vaudra 57 car ce sont leurs asci qu'on utilise.
//Alors que l'ascii de 1, ca vaut pas un nb dans le tableau.    
/*int main(void){
    int a = 49;
    unsigned char b = '1';
    int c = 50;
    int d = 57;
    printf("ft_isalnum(1) ---> %d\n", ft_isalnum(a));
    printf("ft_isalnum('1') ---> %d\n", ft_isalnum(b));
    printf("ft_isalnum(11) ---> %d\n", ft_isalnum(c));
    printf("ft_isalnum(-1) ---> %d\n", ft_isalnum(d));
    
    return(0);
}
*/


//////////////////////isascii
/*
Si vous souhaitez vérifier que la fonction isascii renvoie une valeur fausse, vous pouvez utiliser une valeur en dehors de la plage octale 001 à 0177. Une valeur en octal en dehors de cette plage sera considérée comme un caractère non-ASCII.

Par exemple, vous pouvez utiliser 0200 en octal, ce qui équivaut à 128 en décimal, pour vérifier que la fonction renvoie une valeur fausse :
*/
/*int main(void){
    int a = 001;
    int b = 0177;
    int c = 0200;
    printf("ft_isascii(001) ---1 %d\n", ft_isascii(a));
    printf("ft_isascii(0177) ---1 %d\n", ft_isascii(b));
    printf("ft_isascii(0200) ---1 %d\n", ft_isascii(c));
    return(0);
}
*/

//////////////////////////////isprint
/**
 Ici isprint vérifie si ce sont bien des caractères imprimable (on otacl, mais on peux le faire en décimal,...).
 Donc 040 est ok et 0176 est ok.
 039 par exemple n'est pas une valeur octal valide  car en octal on n'utilise seulement les chiffre entre 0 et 7. Donc 9 n'y est pas.
 et 0200 n'est pas un caractère imprimable.
*/
/*
int main(void){
    int a = 040;
    int b = 041;
    int c = 0176;
    int d = 0177;
    int e = 0200;
    printf("ft_isprint(040) ---> %d\n", ft_isprint(a));
    printf("ft_isprint(041) ---> %d\n", ft_isprint(b));
    printf("ft_isprint(017) ---> %d\n", ft_isprint(c));
    printf("ft_isprint(0177) ---> %d\n", ft_isprint(d));
    printf("ft_isprint(0200) ---> %d\n", ft_isprint(e));
    return(0);
}
*/

////////////////////////////////////ft_strlen
//
/*
int main(void){
    char    *a = "bonjour";
    char    *b = "";
    char    *c = "b";
    printf("ft_strlen(bonjour) --> %zu\n", ft_strlen(a));
    printf("ft_strlen() --> %zu\n", ft_strlen(b));
    printf("ft_strlen(b) --> %zu\n", ft_strlen(c));
    return(0);
}
*/

////////////////////////////////////////////ft_memset(void *b, int c, size_t len)
/*
int main() {
    // Déclaration d'un tableau d'entiers
    int myArray[5];

    // Affichage du tableau avant utilisation de ft_memset
    printf("Avant ft_memset :\n");
    for (int i = 0; i < 5; i++) {
        printf("myArray[%d] : %d\n", i, myArray[i]);
    }

    // Utilisation de ft_memset pour remplir le tableau avec la valeur 42
    ft_memset(myArray, 42, sizeof(myArray));

    // Affichage du tableau après utilisation de ft_memset
    printf("\nAprès ft_memset :\n");
    for (int i = 0; i < 5; i++) {
        printf("myArray[%d] : %hhu\n", i, (unsigned char)myArray[i]);
    }

    return 0;
}
*/
/*
int main(void){
    char *dst[20]; 
    const char *src = "bonjour les gens";
    printf("before ft_memencpy :\n");
    printf("dst --> %s\n", dst);
    printf("src ---> %s\n", src);
    printf("after ft_memcpy :\n");
    ft_memcpy(dst, src, ft_strlen(src) + 1);
    printf("---------------");
    printf("dst --> %s\n", dst);
    printf("src ---> %s\n", src);
    return(0);
}
*/



///////////////////////////////////////////////////////ft_memmove
/*
int main() {
    // Déclarer une chaîne de caractères
    char str[] = "Hello, World!";
    
    // Créer un chevauchement en copiant une partie de la chaîne à l'intérieur d'elle-même
    memmove(str + 7, str + 1, 5);

    // Afficher le résultat
    printf("Résultat : %s\n", str);

    return 0;
}
*/

//////////////////////////////ft_strlcpy()
/*
int main() {
    char destination[20];
    const char *source = "Hello, World!";

    // Utilisation de la fonction ft_strlcpy
    size_t result = ft_strlcpy(destination, source, sizeof(destination));

    // Affichage du résultat
    printf("Résultat de ft_strlcpy : %zu\n", result);
    printf("Destination : %s\n", destination);

    return 0;
}
*/


/////////////////////////////////////////ft_strlcat()
/*
int main() {
    char destination[20] = "Hello";
    const char *source = ", World!";

    // Utilisation de la fonction ft_strlcat
    size_t result = ft_strlcat(destination, source, sizeof(destination));

    // Affichage du résultat
    printf("Résultat de ft_strlcat : %zu\n", result);
    printf("Destination : %s\n", destination);

    return 0;
}
*/

//////////////////////////////////ft_str(r)chr
/*
int main() {
    const char *str = "Hello, World!";
    char *ptr;

    // Recherche de la première occurrence de 'o' dans la chaîne
    ptr = strchr(str, 'o');
    if (ptr != NULL) {
        printf("Première occurrence de 'o' : %s\n", ptr);
    } else {
        printf("'o' non trouvé.\n");
    }

    // Recherche de la dernière occurrence de 'o' dans la chaîne
    ptr = strrchr(str, 'o');
    if (ptr != NULL) {
        printf("Dernière occurrence de 'o' : %s\n", ptr);
    } else {
        printf("'o' non trouvé.\n");
    }

    return 0;
}
*/

////////////////////////////////////ft_strncmp
/*
int main() {
    char str1[] = "Hello";
    char str2[] = "Helicopter";
    
    int result = strncmp(str1, str2, 3);
    int result2 = strncmp(str1, str2, 4);
    int result3 = strncmp(str2, str1, 4);
    
    if (result == 0) {
        printf("Les trois premiers caractères sont identiques.\n");
    } else if (result < 0) {
        printf("str1 est inférieur à str2.\n");
    } else {
        printf("str1 est supérieur à str2.\n");
    }
    printf("\n\n");
    if (result2 == 0) {
        printf("Les trois premiers caractères sont identiques.\n");
    } else if (result2 < 0) {
        printf("str1 est inférieur à str2.\n");
    } else {
        printf("str1 est supérieur à str2.\n");
    }
    printf("\n\n");
    if (result3 == 0) {
        printf("Les trois premiers caractères sont identiques.\n");
    } else if (result3 < 0) {
        printf("str1 est inférieur à str2.\n");
    } else {
        printf("str1 est supérieur à str2.\n");
    }



    return 0;
}
*/