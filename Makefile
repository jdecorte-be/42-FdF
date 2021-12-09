NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I minilibx -L minilibx_macos -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRCS = 	srcs/fdf.c\
        srcs/main.c\
		srcs/parse.c\
        libft/libft.a\

# SRCS_BONUS =     pipex_bonus.c\
#                 libft/libft.a\

$(NAME) :
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

# bonus :
#     make all -C libft
#     gcc -fsanitize=address $(CFLAGS) $(SRCS_BONUS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C libft

re : fclean all