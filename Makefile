# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: decortejohn <decortejohn@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 17:05:27 by decortejohn       #+#    #+#              #
#    Updated: 2022/02/16 15:25:24 by decortejohn      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = gcc

CFLAGS = -Wall -Wextra -Werror -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

RM = rm -rf

SRCS = 	src/*.c\
        libft/libft.a\

SRCS_BONUS = src_bonus/*.c\
        libft/libft.a\

$(NAME) :
	make all -C minilibx_macos
	make all -C libft
	gcc $(CFLAGS) $(SRCS) -o $(NAME)

bonus :
	make clean
	make all -C minilibx_macos
	make all -C libft
	gcc $(CFLAGS) $(SRCS_BONUS) -o $(NAME)

all : $(NAME)

fclean : clean
	$(RM) $(NAME)
	make clean -C minilibx_macos
	make fclean -C libft

clean :
	$(RM) $(NAME)
	make clean -C minilibx_macos
	make clean -C libft

re : fclean all
