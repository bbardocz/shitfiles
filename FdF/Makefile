# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/06 16:29:53 by bbardocz          #+#    #+#              #
#    Updated: 2018/03/07 17:07:48 by bbardocz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FdF

SRC = main.c parsing.c put_line.c matrices.c
OBJ = main.o parsing.o put_line.o matrices.o

CC = /usr/bin/clang
CFLAGS = -I /usr/local/include -Wall -Werror -Wextra

MLX = -L /usr/local/lib/ -lmlx -framework Opengl -framework AppKit
LFT = -L libft/ -lft

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) $(SRC) $(MLX) $(LFT) FdF.h

%.o: %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
