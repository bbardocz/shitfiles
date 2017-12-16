# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 18:15:33 by bbardocz          #+#    #+#              #
#    Updated: 2017/12/16 14:45:14 by bbardocz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c get_tetriminos.c fillit.c sqrt.c

OBJ = main.o get_tetriminos.o fillit.o sqrt.o

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -L . -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
