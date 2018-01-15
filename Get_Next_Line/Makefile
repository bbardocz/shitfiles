# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/15 15:16:23 by bbardocz          #+#    #+#              #
#    Updated: 2018/01/15 19:02:17 by bbardocz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl

SRC		= main.c get_next_line.c
OBJ		= main.o get_next_line.o

CC		= cc
LIBFTD	= libft
LDFLAGS	= -Wall -Wextra -Werror -I$(LIBFTD) -g
LDLIBS	= -L$(LIBFTD) -lft

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIBFTD)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

%.o: %.c
	$(CC) $(LDFLAGS) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make -C $(LIBFTD) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFTD) fclean

re: fclean all
