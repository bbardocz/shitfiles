# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 14:07:55 by bbardocz          #+#    #+#              #
#    Updated: 2018/01/06 17:00:40 by bbardocz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c get_pieces.c sqrt.c check.c fillit.c map.c

OBJ = main.o get_pieces.o sqrt.o check.o fillit.o map.o

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -L . -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
