NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I minilibx -L minilibx_macos -lmlx -framework OpenGL -framework AppKit -fsanitize=address -g

RM = rm -rf

SRCS = 	src/fdf.c\
        src/main.c\
		src/parse.c\
        libft/libft.a\

SRCS_BONUS = src_bonus/fdf_bonus.c\
        src_bonus/main_bonus.c\
		src_bonus/parse_bonus.c\
        libft/libft.a\

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

bonus :
	make clean
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all