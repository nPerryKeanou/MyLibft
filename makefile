NAME        = libft.a

# Compilateur et options
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I.

# Dossiers
SRC_DIR     = src
OBJ_DIR     = obj
LIBFT_DIR   = $(SRC_DIR)/libft
GNL_DIR     = $(SRC_DIR)/get_next_line
PRINTF_DIR  = $(SRC_DIR)/ft_printf

# Couleurs
GREEN       = \033[0;32m
RED         = \033[0;31m
RESET       = \033[0m

# Récupération des sources
SRCS        = $(wildcard $(LIBFT_DIR)/*.c) \
              $(wildcard $(GNL_DIR)/*.c) \
              $(wildcard $(PRINTF_DIR)/*.c)

# Filtrer le main.c si présent
SRCS        := $(filter-out %main.c, $(SRCS))

# Transformation des chemins .c en .o dans le dossier obj
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# --- Règles ---

all: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN)✅ $(NAME) créé avec succès !$(RESET)"

# Règle pour compiler les .o dans leur dossier respectif
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)🧹 Dossier des objets supprimés.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  $(NAME) supprimé.$(RESET)"

re: fclean all

.PHONY: all clean fclean re