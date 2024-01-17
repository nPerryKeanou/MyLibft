#CEtte variable contient la liste des fichiers sources à nécéssaire pour constuire
#ma lib.Les fichiers sont énumérés avec un backslash pour indiquer unec continuation de la ligne.
SRCS = ft_atoi.c\
			ft_bzero.c\
			ft_calloc.c\
			ft_isalnum.c\
			ft_isalpha.c\
			ft_isascii.c\
			ft_isdigit.c\
			ft_islower.c\
			ft_isprint.c\
			ft_isupper.c\
			ft_itoa.c\
			ft_memchr.c\
			ft_memcmp.c\
			ft_memcpy.c\
			ft_memmove.c\
			ft_memset.c\
			ft_putchar.c\
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putnbr_fd.c\
			ft_putnbr.c\
			ft_putstr.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
			ft_strlen_const.c\
			ft_strmapi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strtrimchr_multi.c\
			ft_strtrimchr.c\
			ft_strtrimstr.c\
			ft_substr.c\
			ft_tolower.c\
			ft_toupper.c

SRCS_BONUS = ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c



#Cette variable définit le compilateur à utiliser. Dans ce cas, c'est GCC.
CC = gcc

#Cette variable comporte des options de compilations.
#'-Wall','-Wextra' et '-Werror' activent des avertissement du compilateur ('-Wall' et '-Wextra) et traitent 
#les avertissements commes des erreurs ('-Werror').
CFLAGS = -Wall -Wextra -Werror

#Cette variable comporte le nom de la libft apèrs la compilations.
NAME = libft.a

#Cette variable sera le répertoires où seront stockés les fichiers objets générés lors de la compiltions.
OBJS_DIR = objs/

#Cette variable utilise '$(SCRS:c=.O)' pour générer la liste des fichiers objets en remplaçant l'extension '.C' par '.O'
#et en ajoutant le chemin du répertoires d'objets à l'aide de '$(addpréfix $(OBJS_DIR), ...). Les fichiers objets sont 
#les fichiers compilés correspondants aux fichiers sources.
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS_BONUS:.c=.o)))
	
#Ces cibles sont marquées comme des cibles "PHONY", ce qui signifies qu'elles ne correspondent pas à des fichiers réels.
#Cela permet d'éviter des problèmes si des fichiers ou des répertoires portent le même nom.
.PHONY: all clean fclean re

#LA règle par défaut. LA cible 'all' dépend de la cible "$(NAME), donc éxecuter 'make' construira la bibliothèque.
all: $(NAME)

#LA règle de compiltation des fichiers objets. Elle utilise le modéèle '%.O pour représenter tous les fichiers objets, et la dépendences
#'libft.h' indique que si 'libft.h' est modifié, le fichiers objets doivent être reconstruit.
#La cible utilise aussi '$(OBJS_DIR) pour s'assurer que le répertoire des objets existe.
$(OBJS_DIR)%.o : %.c | $(OBJS_DIR) libft.h
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

#La règle pour créer le repertoire des objets s'il n'existe pas.
$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

#La règle pour créer la bibliothèque statique 'libft.a' en utilisant les fichiers objets.
$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "Libft Done !"

bonus: $(OBJS_BONUS)
		@ar rcs $@ $^
		@echo "Libft Done !"

#La règle pour supprimer les fichiers objets.
clean:
	@rm -rf $(OBJS_DIR)

#La règle pour supprimer les fichiers objets et la bibliothèque statique.
fclean: clean
	@rm -f $(NAME)

#La règle pour reconstruire la bibliothèque statique à partir de zéro.
re: fclean all