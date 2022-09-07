SRCS		= main.c color_utils.c image_utils.c mlx_utils.c key_hooks.c mouse_hooks.c

HEADER		= fractol.h

LIB			= ./libft/libft.a

MLX			= ./mlx/libmlx.a

NAME 		= fractol

MAKEFILE	= Makefile

HEADER		= fractol.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror -I .

RM			= rm -f

.PHONY: all clean fclean re mlx

$(NAME): $(MAKEFILE) $(HEADER) $(SRCS) $(HEADER) $(LIB) $(MLX)
	@echo "---------------------"
	@echo "Compilation..."
	@$(CC) $(CFLAGS) $(SRCS) $(LIB) $(MLX) -framework OpenGL -framework AppKit -o $(NAME)
	@echo "Compilation complete"
	@echo "---------------------"

all: $(MLX) $(NAME)

$(LIB):
	@make -C libft

$(MLX):
	@echo "compile mlx..." 
	@make -C mlx &> /dev/null

clean:
	@make clean -C libft
	@make clean -C mlx
	$(RM) $(NAME)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft

re:  fclean all


