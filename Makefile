# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hhismans <hhismans@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/01 14:22:25 by hhismans          #+#    #+#              #
#    Updated: 2014/12/01 21:39:11 by hhismans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fdf

LIB =	lib/libft.a \
		-lmlx -lXext -lX11 -L/usr/X11/lib

SRC =	main/main.c \
		src/ft_drawline_img_c.c \
		src/ft_drawline_img_c_2.c \
		src/put_pixel_img.c \
		src/draw_grid.c \
		src/getinfo.c \
		src/rainbow_gen.c \
		src/convert.c

DEL = rm -f

OBJ = $(SRC:.c=.o)

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@gcc -o $@ $(OBJ) $(LIB)
	@echo "\033[1;33mmake -> $@ created\033[1;37m"

%.o: %.c
	@gcc -o $@ -c $< -I./includes
	@echo [36mCompilation of[1m $< [0m[32m done [37m
clean:
	@$(DEL) $(OBJ)
	@echo "\033[0;33mclean -> .o deleted"

fclean: clean
	@$(DEL) $(NAME)
	@echo "\033[1;31mfclean -> $(NAME) deleted\033[37m"

re: fclean all
	@echo "\033[1;30mre -> $(NAME) reloaded\033[1;37m"

test:
	./fdf map/ftest
.PHONY: all clean fclean re

