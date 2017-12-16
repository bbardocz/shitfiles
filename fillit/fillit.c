/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:19:24 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/16 14:52:09 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include <stdio.h>

char		**blanksqr(int sqrside)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	**blanksqr;

	x = sqrside;
	y = sqrside;
	i = 0;
	j = 0;
	blanksqr = (char **)malloc(sizeof(char *) * (sqrside + 1));
	printf ("sqrside: %i\n", sqrside);
	while (y-- != 0)
	{
		blanksqr[j] = (char *)malloc(sizeof(char) * (sqrside + 1));
		while (x-- != 0)
		{
			blanksqr[j][i] = '.';
			i++;
		}
		blanksqr[j][i] = '\0';
		x = sqrside;
		i = 0;
		j++;
	}
	blanksqr[j] = ft_strnew((size_t)sqrside);
	return (blanksqr);
}

int			c_blocks(f_list *tetriminos)
{
	int		i;
	int		c_blocks;

	i = 0;
	c_blocks = 0;
	while (tetriminos->next != NULL)
	{
		while (tetriminos->t_tab[i] != '\0')
		{
			if (tetriminos->t_tab[i] == '#')
				c_blocks++;
			i++;
		}
		i = 0;
		tetriminos = tetriminos->next;
	}
	return (c_blocks);
}

int			pos_is_valid(char **sqr, int sqrside)
{
	int		y;
	int		x;
	int		q;
	int		touch;

	y = 0;
	x = 0;
	touch = 0;
	ft_putstr("show it to me\n");
	print_sqr(sqr, sqrside);
	while (sqr[y][x] != '\0')
	{
		while (sqr[y][x] != '\0')
		{
			if ((sqr[y][x] != '.' && sqr[y][x] == sqr[y][x + 1]) ||
			(sqr[y][x] != '.' && sqr[y][x] == sqr[y + 1][x]))
			{
				printf("touch because: %c == %c (x = %i)\n", sqr[y][x], sqr[y][x + 1], x);
				printf("Ou because: %c == %c\n", sqr[y][x], sqr[y + 1][x]);
				touch++;
			}
			x++;
		}
		x = 0;
		y++;
	}
	printf("%i\n, touch: %i\n", touch % 3, touch);
	if (touch % 3 == 0)
	{
		ft_putstr("valid 1\n");
		print_sqr(sqr, sqrside);
		return (1);
	}
	ft_putstr("error 0\n");
	return (0);
}

void		remove_tet(char **sqr, char c)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (sqr[y][x] != '\0')
	{
		while (sqr[y][x] != '\0')
		{
			if (sqr[y][x] == c)
				sqr[y][x] = '.';
			x++;
		}
		x = 0;
		y++;
	}
}

void		feel_it(f_list *tet, char **sqr, int sqrside)
{
	int		i;
	char	c;
	int		x;
	int		y;
	int		pos;

	i = 0;
	x = tet->x[i];
	y = tet->y[i];
	pos = 0;
	c = 'A';
	while (tet->next != NULL)
	{
		while (i < 4)
		{
			x = tet->x[i];
			y = tet->y[i];
			while (sqr[y][x + pos] != '.')
				pos++;
			sqr[y][x + pos] = c;
			i++;
		}
		i = 0;
		if (pos_is_valid(sqr, sqrside) == 1)
		{
			c++;
			tet = tet->next;
		}
		else if (pos_is_valid(sqr, sqrside) == 0)
		{
			remove_tet(sqr, c);
			ft_putstr("correction: \n");
			print_sqr(sqr, sqrside);
			pos++;
		}
	}
}

void		print_sqr(char **sqr, int sqrside)
{
	int i = 0;

	while (i < sqrside)
	{
		printf("ligne: %s\n", sqr[i]);
		i++;
	}
}

void		fillit(f_list *tetriminos)
{
	int		sqrside;
	char	**sqr;

	sqrside = (c_blocks(tetriminos) / ft_sqrt(c_blocks(tetriminos)));
	sqr = (char **)malloc (sizeof(char *) * (sqrside + 1));
	if (!(sqr))
		return ;
	sqr = blanksqr(sqrside);
	print_sqr(sqr, sqrside);
	ft_putchar('\n');
	feel_it(tetriminos, sqr, sqrside);
	print_sqr(sqr, sqrside);
}
