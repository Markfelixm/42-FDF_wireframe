NAME := fdf
SRC := \
	main.c \
	parse.c \
	memory.c \
	hook.c \
	hook_utility.c \
	color.c \
	math.c \
	normalize.c \
	draw.c \
	drawloop.c \
	utility.c
#	transform.c

LIBFT_DIR := Libft
LIBFT := $(LIBFT_DIR)/libft.a

CC := cc
CC_FLAG := -Wall -Wextra -Werror -Ofast

LINK := -l m -l mlx -framework OpenGL -framework AppKit -I minilibx_macos/

DEBUG := -g -fsanitize=address,undefined -O0

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

debug: $(LIBFT)
	@echo "Compiling debug..."
	@$(CC) $(CC_FLAG) $(LINK) $(DEBUG) $(SRC) $(LIBFT) -o $(NAME)
