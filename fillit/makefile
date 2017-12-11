# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/28 18:15:33 by bbardocz          #+#    #+#              #
#    Updated: 2017/12/07 15:21:24 by bbardocz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = B_fillit

SRC = B_main.c ft_get_tetriminos.c B_ft_fillit.c B_ft_sqrt.c

OBJ = B_main.o ft_get_tetriminos.o B_ft_fillit.o B_ft_sqrt.o

all: $(NAME)

$(NAME):
	gcc $(SRC) -o $(NAME) -L . -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
