/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:19:24 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/06 15:42:13 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "B_header.h"

#include <stdio.h>

char		*ft_blanksqr(int sqrside)
{
	int		x;
	int		y;
	int		i;
	char	*blanksqr;

	x = sqrside;
	y = sqrside;
	i = 0;
	blanksqr = (char *)malloc(sizeof(char) * 7);
	while (y-- != 0)
	{
		while (x-- != 0)
		{
			blanksqr[i++] = '.';
		}
		blanksqr[i++] = '\n';
		x = sqrside;
	}
	blanksqr[i] = '\0';
	ft_putstr(blanksqr);
	return (blanksqr);
}

int			ft_c_blocks(char **tetriminos)
{
	int		i;
	int		y;
	int		c_blocks;

	i = 0;
	y = 0;
	c_blocks = 0;
	while (tetriminos[y] != NULL)
	{
		while (tetriminos [y][i] != '\0')
		{
			if (tetriminos[y][i] == '#')
				c_blocks++;
			i++;
		}
		i = 0;
		y++;
	}
	return (c_blocks);
}

void		ft_feel_it(char **tetriminos, char *sqr)
{
	int		i;
	int		y;
	int		z;
	char	x;

	i = 0;
	y = 0;
	z = 0;
	x = 'A';
	while (tetriminos[y] != NULL)
	{
		while (tetriminos[y][i] != '\0')
		{
			if (tetriminos[y][i] == '#')
			{
				if (sqr[z + i] == '\n')
					z++;
				sqr[z + i] = x;
			}
			i++;
		}
		i = 0;
		y++;
		x++;
	}
	ft_putchar('\n');
	ft_putstr(sqr);
	ft_putchar('\n');
}

void		ft_fillit(char **tetriminos)
{
	int		sqrside;
	char	*sqr;

	sqrside = (ft_c_blocks(tetriminos) / ft_sqrt(ft_c_blocks(tetriminos)));
	sqr = ft_blanksqr(sqrside);
	ft_feel_it(tetriminos, sqr);
}
