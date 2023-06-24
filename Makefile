NAME := fdf
SRC := \
	main.c \
	parse.c \
	memory.c \
	hook.c \
	color.c \
	math.c \
	normalize.c \
	draw.c \
	utility.c
#	drawloop.c \
	transform.c \

LIBFT_DIR := Libft
LIBFT := $(LIBFT_DIR)/libft.a

CC := cc
CC_FLAG := -Wall -Wextra -Werror -g #-fsanitize=address,undefined # TODO: clean this

LINK := -l m -l mlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	@echo "Compiling fdf..."
	@$(CC) $(CC_FLAG) $(LINK) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@echo "Compiling LIBFT..."
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
