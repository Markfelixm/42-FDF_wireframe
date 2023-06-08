NAME := fdf
SRC := \
	main.c \
	parse.c \
	memory.c \
	utility.c
#	draw.c \
	drawloop.c \
	color.c \
	normalize.c \
	transform.c \
	math.c \
	hook.c \

LIBFT_DIR := Libft
LIBFT := $(LIBFT_DIR)/libft.a
CC_FLAG := -Wall -Wextra -Werror -g
LINK := -l m -l mlx -framework OpenGL -framework AppKit

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT)
	@cc $(CC_FLAG) $(LINK) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
