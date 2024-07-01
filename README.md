# MyLibft
 
### 1.  Prérequis

  Assurez-vous d'avoir `gcc` (GNU Compiler Collection) installé sur votre système. 
  Vous pouvez vérifier son installation en exécutant la commande suivante : gcc --version

### 2.  Téléchargement

  Clonez ce dépôt en utilisant git : https://github.com/nPerryKeanou/MyLibft.git

### 3.  Compilation

  Accédez au répertoire du projet et compilez la bibliothèque en utilisant make : 
    cd libft/
      make

  Pour compiler également les fonctions bonus, utilisez :
    cd libft/
      make bonus

### 4.  Nettoyage

  Pour supprimer les fichiers objets générés, utilisez :
    make clean

  Pour supprimer les fichiers objets et la bibliothèque compilée, utilisez :
    make fclean

  Pour reconstruire la bibliothèque à partir de zéro, utilisez :
    make re

### 5.  Utilisation

  Pour utiliser libft dans votre propre projet, vous devez inclure le fichier d'en-tête libft.h et 
  lier votre projet avec la bibliothèque compilée libft.a.

  Assurez-vous que libft.a et libft.h sont dans le même répertoire que vos fichiers source, 
  ou modifiez les chemins d'inclusion et de liaison en conséquence.

  Incluez libft.h dans vos fichiers source :
    #include "libft.h"

  Compilez votre projet en liant libft.a. Par exemple, si vous avez un fichier source main.c :
    gcc -o my_program main.c libft.a -I.

  L'option -I. indique au compilateur d'inclure le répertoire courant dans la recherche des fichiers d'en-tête.
    
### 6.  Contributions 

  Les contributions sont les bienvenues ! N'hésitez pas à ouvrir une issue ou à soumettre une pull request.
