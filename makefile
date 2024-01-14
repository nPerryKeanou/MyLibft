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
			ft_putchar_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_putnbr_fd.c\
			ft_putnbr.c\
			ft_putstr_fd.c\
			ft_split.c\
			ft_strchr.c\
			ft_strdup.c\
			ft_striteri.c\
			ft_strjoin.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_strlen.c\
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

CC = gcc

# UNE VARIABLE QUI CONTIENT LES OPTIONS DE COMPILATION.
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))

.PHONY: all clean fclean re

all: $(NAME)

$(OBJS_DIR)%.o : %.c | $(OBJS_DIR) libft.h
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c $< -o $@ -I.

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@echo "Libft Done !"

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all