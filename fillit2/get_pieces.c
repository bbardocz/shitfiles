/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pieces.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:19:05 by bbardocz          #+#    #+#             */
/*   Updated: 2018/01/06 16:35:23 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

void		print_pieces(f_list *pieces)
{
		int i = 0;
	while (pieces != NULL)
	{
		printf("\nPiece %i:\n%s\nLettre:\n%c\n",i, pieces->tet, pieces->c);
		pieces = pieces->next;
		i++;
	}
}

f_list		*get_coord(f_list *pieces)
{
	f_list	*ret;
	int		i;
	int		j;

	ret = pieces;
	while (pieces != NULL)
	{
		j = 0;
		i = 0;
		while (pieces->tet[i] != '\0')
		{
			if (pieces->tet[i] == '#')
			{
				pieces->x[j] = i % 5;
				pieces->y[j] = i / 5;
				j++;
			}
			i++;
		}
		pieces = pieces->next;
	}
	print_pieces(ret);
	return (ret);
}

void		fill_list(int fd, f_list *pieces)
{
	char	c;
	f_list	*pre;

	c = 'B';
	while (read(fd, pieces->tet, 21) != 0)
	{
		pieces->tet[20] = '\0';
		pieces->c = c;
		pieces->next = (f_list *)malloc(sizeof(f_list));
		pre = pieces;
		pieces = pieces->next;
		pieces->tet = (char *)malloc(sizeof(char) * 21);
		c++;
	}
	free(pieces->tet);
	free(pieces);
	pre->next = NULL;
}

f_list		*get_pieces(int fd)
{
	f_list *pieces;
	f_list *check;
	f_list *first;

	pieces = (f_list *)malloc(sizeof(f_list));
	pieces->tet = (char *)malloc(sizeof(char) * 21);
	read(fd, pieces->tet, 21);
	pieces->tet[20] = '\0';
	pieces->c = 'A';
	first = pieces;
	check = pieces;
	pieces->next = (f_list *)malloc(sizeof(f_list));
	pieces = pieces->next;
	pieces->tet = (char *)malloc(sizeof(char) * 21);
	fill_list(fd, pieces);
	if (check_pieces(check) == 0)
		return (get_coord(first));
	return (first);
}
