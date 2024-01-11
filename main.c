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

static size_t ft_strlen_const(const char   *str){
	size_t i;

	i = 0;
	while(str[i] != '\0'){
		i++;
	}
	return(i);
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


///////////////////////////////////////ft_memchr
/*
int main() {
    const char *str = "Hello, World!";
    size_t n = ft_strlen(str);

    // Test 1: Recherche d'un caractère présent
    char searchChar1 = 'o';
    void *result1 = ft_memchr(str, searchChar1, n);
    printf("Test 1 - Recherche de '%c': %s\n", searchChar1, result1 ? "Trouvé" : "Non trouvé");

    // Test 2: Recherche d'un caractère absent
    char searchChar2 = 'z';
    void *result2 = ft_memchr(str, searchChar2, n);
    printf("Test 2 - Recherche de '%c': %s\n", searchChar2, result2 ? "Trouvé" : "Non trouvé");

    // Test 3: Recherche du caractère nul
    char searchChar3 = '\0';
    void *result3 = ft_memchr(str, searchChar3, n);
    printf("Test 3 - Recherche de '%c': %s\n", searchChar3, result3 ? "Trouvé" : "Non trouvé");

    // Test 4: Recherche dans une chaîne vide
    const char *emptyStr = "";
    size_t nEmpty = ft_strlen(emptyStr);
    char searchChar4 = 'A';
    void *result4 = ft_memchr(emptyStr, searchChar4, nEmpty);
    printf("Test 4 - Recherche de '%c' dans une chaîne vide: %s\n", searchChar4, result4 ? "Trouvé" : "Non trouvé");

    // Test 5: Recherche dans une partie spécifique de la chaîne
    size_t startIdx = 7;  // Commencer la recherche à partir du 8e caractère
    size_t lenToSearch = 5;  // Rechercher les 5 caractères suivants
    char searchChar5 = 'W';
    void *result5 = ft_memchr(str + startIdx, searchChar5, lenToSearch);
    printf("Test 5 - Recherche de '%c' à partir du 8e caractère: %s\n", searchChar5, result5 ? "Trouvé" : "Non trouvé");

    return 0;
}
*/

//////////////////////////////////////////////ft_memcmp
/*
int main() {
    // Test 1: Chaînes identiques
    char str1[] = "Hello";
    char str2[] = "Hello";
    size_t n1 = 5;
    int result1 = ft_memcmp(str1, str2, n1);
    printf("Test 1: %d\n", result1);  // Attendu : 0

    // Test 2: Chaînes différentes
    char str3[] = "Hello";
    char str4[] = "Hella";
    size_t n2 = 5;
    int result2 = ft_memcmp(str3, str4, n2);
    printf("Test 2: %d\n", result2);  // Attendu : différence entre 'o' et 'a' (111 - 97)

    // Test 3: Comparaison de préfixes
    char str5[] = "Hello";
    char str6[] = "Hello, World!";
    size_t n3 = 5;
    int result3 = ft_memcmp(str5, str6, n3);
    printf("Test 3: %d\n", result3);  // Attendu : 0 (les 5 premiers caractères sont identiques)

    // Test 4: Chaînes vides
    char str7[] = "";
    char str8[] = "";
    size_t n4 = 0;
    int result4 = ft_memcmp(str7, str8, n4);
    printf("Test 4: %d\n", result4);  // Attendu : 0 (chaînes vides, aucune différence)

    return 0;
}
*/


/////////////////////////////////////////////////////////ft_strnstr
/*
int main() {
    const char *haystack = "Hello, World!";
    const char *needle = "World";
    size_t len = 13;

    char *result = strnstr(haystack, needle, len);

    if (result != NULL) {
        printf("Needle found at position: %ld\n", result - haystack);
    } else {
        printf("Needle not found.\n");
    }

    return 0;
}
*/

//////////////////////////////////////////////////ft_atoi
/*
int main() {
    const char *str1 = "12345";
    const char *str2 = "-9876";
    const char *str3 = "  42abc";
    const char *str4 = "0";
    const char *str5 = "   ";
    const char *str6 = "123 456";
    const char *str7 = "abc123";
    const char *str8 = "  +789";
    const char *str9 = "2147483648";  // Dépassement de la capacité d'un int sur 32 bits
    const char *str10 = "  -2147483649";  // Dépassement de la capacité d'un int sur 32 bits
    const char *str11 = "  -+789";


    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str1, atoi(str1), str1, ft_atoi(str1));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str2, atoi(str2), str2, ft_atoi(str2));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str3, atoi(str3), str3, ft_atoi(str3));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str4, atoi(str4), str4, ft_atoi(str4));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str5, atoi(str5), str5, ft_atoi(str5));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str6, atoi(str6), str6, ft_atoi(str6));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str7, atoi(str7), str7, ft_atoi(str7));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str8, atoi(str8), str8, ft_atoi(str8));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str9, atoi(str9), str9, ft_atoi(str9));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str10, atoi(str10), str10, ft_atoi(str10));
    printf("atoi(\"%s\") = %d && ft_atoi(\"%s\") = %d\n", str11, atoi(str11), str11, ft_atoi(str11));

    // printf("atoi(\"%s\") = %d\n", str2, atoi(str2));
    // printf("atoi(\"%s\") = %d\n", str3, atoi(str3));
    // printf("atoi(\"%s\") = %d\n", str4, atoi(str4));
    // printf("atoi(\"%s\") = %d\n", str5, atoi(str5));
    // printf("atoi(\"%s\") = %d\n", str6, atoi(str6));
    // printf("atoi(\"%s\") = %d\n", str7, atoi(str7));
    // printf("atoi(\"%s\") = %d\n", str8, atoi(str8));
    // printf("atoi(\"%s\") = %d\n", str9, atoi(str9));
    // printf("atoi(\"%s\") = %d\n", str10, atoi(str10));
    // printf("atoi(\"%s\") = %d\n", str11, atoi(str11));

    return 0;
}
*/

//////////////////////////////////ft_calloc
// Fonction pour afficher le contenu d'un tableau
/*
void printArray(int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test 1 : Allouer un tableau de 5 entiers
    int* arr1 = (int*)ft_calloc(5, sizeof(int));
    printf("Test 1:\n");
    printArray(arr1, 5);
    free(arr1);

    // Test 2 : Allouer un tableau de 3 doubles
    double* arr2 = (double*)ft_calloc(3, sizeof(double));
    printf("\nTest 2:\n");
    for (size_t i = 0; i < 3; i++) {
        printf("%f ", arr2[i]);
    }
    printf("\n");
    free(arr2);

    // Test 3 : Allouer un tableau de 0 éléments (cas spécial)
    int* arr3 = (int*)ft_calloc(0, sizeof(int));
    printf("\nTest 3 (taille 0):\n");
    printArray(arr3, 0);
    free(arr3);

    return 0;
}
*/

///////////////////////////////ft_strdup
/*
int main(void){
    const char *a = "";
    const char *b = "ok mec, bonjour les gens";
    char *c = ft_strdup(a);
    char *d = ft_strdup(b);

    printf("*a --> %s && copie de *a --> %s\n", a, c);
    printf("\n");
    free(c);
    printf("*b --> %s && copie de *b --> %s\n", b, d);
    printf("\n");
    free(d);
    return(0);
}
*/

//////////////////////////////////ft_substr
/*
int main(void){
    char *a = "abcdefghijklmnopqrstuvwxyz";
    printf("a --> %s\n", a);
    printf("ft_substr(a, 2, 10) ---> %s\n", ft_substr(a, 2, 10));
    printf("ft_substr(a, 3, 10) ---> %s\n", ft_substr(a, 3, 10));
    printf("ft_substr(a, 4, 10) ---> %s\n", ft_substr(a, 4, 10));
    printf("ft_substr(a, 5, 10) ---> %s\n", ft_substr(a, 5, 10));
    return(0);
}
*/

/////////////////////////////////////ft_strjoin
/*
int main(void){
    const char *a = "";
    const char *b = "ok mec";
    const char *c = "                        ";

    char *rslt1 =    ft_strjoin(a, b);
    char *rslt2 =    ft_strjoin(a, c);
    char *rslt3 =    ft_strjoin(b, c);
    char *rslt4 =    ft_strjoin(c, a);
    char *rslt5 =    ft_strjoin(c, b);


    printf("a --> %s\n", a);
    printf("b --> %s\n", b);
    printf("c --> %s\n", c);
    printf("a && b --> %s\n", rslt1);
    printf("a && c --> %s\n", rslt2);
    printf("b && c --> %s\n", rslt3);
    printf("c && a --> %s\n", rslt4);
    printf("c && b --> %s\n", rslt5);
    free(rslt1);
    free(rslt2);
    free(rslt3);
    free(rslt4);
    free(rslt5);
    return(0);
}
*/

//////////////////////////////ft_strtrimchr
/*
int main(void){
    const char *a = "ccccccccccbonjourcccccccccc";
    const char *b = "abccccccccbonjourcccccccccc";
    const char *c = "          bonjour     ok   ";
    const char *d = "";
    printf("a sans trim--> %s\n", a);
    printf("a avec trim--> %s\n", ft_strtrimchr(a, 'c'));
    printf("\n");
    printf("b avant trim --> %s\n", b);
    printf("b apres trim --> %s\n", ft_strtrimchr(b, 'c'));
    printf("\n");
    printf("c avant trim --> %s\n", c);
    printf("b apres trim --> %s\n", ft_strtrimchr(c, ' '));
    printf("\n");
    printf("b avant trim --> %s\n", d);
    printf("b apres trim --> %s\n", ft_strtrimchr(d, 'c'));
    return(0);
}
*/
////////////////////////////ft_strtrimchr_multi
/*
int main(void){
    const char *a = ":::///mmmokmec///:::";
    const char *b = "   a     bcde     ef   ";
    const char *c = "        \\n-_.okmec.....  -__--:::://";
    const char *test1 = ":/";
    const char *test2 = " :/";
    const char *test3  = " /\\n-_.:";
    printf("a before ---> %s && len --> %zu\n", a, ft_strlen_const(a));
    printf("a after ---> %s\n", ft_strtrimchr_multi(a, test1));
    printf("\n");
    printf("b before ---> %s && len --> %zu\n", b, ft_strlen_const(b));
    printf("b after ---> %s\n", ft_strtrimchr_multi(b, test2));
    printf("\n");
    printf("c before ---> %s && len --> %zu\n", c, ft_strlen_const(c));
    printf("c after ---> %s\n", ft_strtrimchr_multi(c, test3));
    return(0);
}
*/
//////////////////////////////////////ft_strtrimstr.c
/*
int main(void){
    const char    *a = "abcdef abcdef abcdef azzzz";
    const char    *a_set = "abcdef";

    const char *b = "abcdef bbbbbb abcdef";
    const char *c = "ccccccccc";
    const char *d = "ccccccccccc abcdef";
    const char *e = "abcdefabcdefabcdef azzzz";

    char *rslt1 = ft_strtrimstr(a, a_set);
    char *rslt2 = ft_strtrimstr(b, a_set);
    char *rslt3 = ft_strtrimstr(c, a_set);
    char *rslt4 = ft_strtrimstr(d, a_set);
    char *rslt5 = ft_strtrimstr(e, a_set);
    printf("a       --> %s\n",a);
    printf("a_set   --> %s\n", a_set);
    printf("ft_strtrimstr(a, a_st) --> %s\n", rslt1);
    printf("\n");
    printf("\n");
    printf("b       --> %s\n",b);
    printf("_set   --> %s\n", a_set);
    printf("ft_strtrimstr(b, a_st) --> %s\n", rslt2);
    printf("\n");
    printf("\n");
    printf("c       --> %s\n",c);
    printf("a_set   --> %s\n", a_set);
    printf("ft_strtrimstr(c, a_st) --> %s\n", rslt3);
    printf("\n");
    printf("\n");
    printf("d       --> %s\n",d);
    printf("a_set   --> %s\n", a_set);
    printf("ft_strtrimstr(d, a_st) --> %s\n", rslt4);
    printf("\n");
    printf("e      --> %s\n",e);
    printf("a_set   --> %s\n", a_set);
    printf("ft_strtrimstr(e, a_st) --> %s\n", rslt5);
    printf("\n");

    free(rslt1);
    free(rslt2);
    free(rslt3);
    free(rslt4);
    free(rslt5);

    return(0);
}
*/
/*
int main() {
    // Test 1: Chaîne vide, pas de trimming
    const char *test1 = "";
    const char *set1 = "";
    char *result1 = ft_strtrimstr(test1, set1);
    printf("Test 1: '%s'\n", result1);  // Devrait afficher une chaîne vide

    // Test 2: Chaîne vide, trimming avec un ensemble non vide
    const char *test2 = "";
    const char *set2 = "abc";
    char *result2 = ft_strtrimstr(test2, set2);
    printf("Test 2: '%s'\n", result2);  // Devrait afficher une chaîne vide

    // Test 3: Chaîne non vide, pas de trimming
    const char *test3 = "Hello, World!";
    const char *set3 = "";
    char *result3 = ft_strtrimstr(test3, set3);
    printf("Test 3: '%s'\n", result3);  // Devrait afficher la chaîne originale

    // Test 4: Chaîne non vide, trimming au début et à la fin
    const char *test4 = "   \t  Trim me!  \t  ";
    const char *set4 = " \t";
    char *result4 = ft_strtrimstr(test4, set4);
    printf("Test 4: '%s'\n", result4);  // Devrait afficher "Trim me!"

    // Test 5: Chaîne non vide, trimming au début seulement
    const char *test5 = "   \t  Trim me!";
    const char *set5 = " \t";
    char *result5 = ft_strtrimstr(test5, set5);
    printf("Test 5: '%s'\n", result5);  // Devrait afficher "Trim me!"

    // Test 6: Chaîne non vide, trimming à la fin seulement
    const char *test6 = "Trim me!  \t  ";
    const char *set6 = " \t";
    char *result6 = ft_strtrimstr(test6, set6);
    printf("Test 6: '%s'\n", result6);  // Devrait afficher "Trim me!"

    // Test 7: Chaîne non vide, pas de trimming (ensemble non présent)
    const char *test7 = "Hello, World!";
    const char *set7 = "abc";
    char *result7 = ft_strtrimstr(test7, set7);
    printf("Test 7: '%s'\n", result7);  // Devrait afficher la chaîne originale

    // Test 8: Chaîne non vide, pas de trimming (ensemble présent au milieu)
    const char *test8 = "Hello, World!";
    const char *set8 = "abc";
    char *result8 = ft_strtrimstr(test8, set8);
    printf("Test 8: '%s'\n", result8);  // Devrait afficher la chaîne originale

    // Libération de la mémoire
    free(result1);
    free(result2);
    free(result3);
    free(result4);
    free(result5);
    free(result6);
    free(result7);
    free(result8);

    return 0;
}
*/

//////////////////////////////////////ft_split
/*
int main() {
    const char *s = " ,       Bonjour,monde,C,est,genial, , ,";
    char **tab = ft_split(s, ',');
    
    if (tab != NULL) {
        for (size_t i = 0; tab[i] != NULL; i++) {
            printf("Mot %zu : %s\n", i + 1, tab[i]);
        }

        // Free memory
        for (size_t i = 0; tab[i] != NULL; i++) {
            free(tab[i]);
        }
        free(tab);
    }

    return 0;
}
*/

///////////////////////////////////////ft_itoa
int main(void){
    char *rslt = ft_itoa(1234);
    char *rslt2 = ft_itoa(-1234);
    char *rslt3 = ft_itoa(0);
    char *rslt4 = ft_itoa(-0);
    char *rslt5 = ft_itoa(2147483647);
    char *rslt6 = ft_itoa(-2147483647);
    char *rslt7 = ft_itoa(-2147483648);
    char *rslt8 = ft_itoa(2147483648);
    printf("rslt --> %s\n", rslt);
    printf("rslt2 --> %s\n", rslt2);
    printf("rsl3t --> %s\n", rslt3);
    printf("rslt4 --> %s\n", rslt4);
    printf("rslt5 --> %s\n", rslt5);
    printf("rslt6 --> %s\n", rslt6);
    printf("rslt7 --> %s\n", rslt7);
    printf("rslt8 --> %s\n", rslt8);
    free(rslt);
    free(rslt2);
    free(rslt3);
    free(rslt4);
    free(rslt5);
    free(rslt6);
    free(rslt7);
    free(rslt8);

    return(0);
}