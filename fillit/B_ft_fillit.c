/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:19:24 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/11 19:08:05 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "B_Header.h"

#include <stdio.h>

char		**ft_blanksqr(int sqrside)
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
	blanksqr[j] = (char *)malloc(sizeof(char) * 1);
	blanksqr[j][0] = '\0';
	return (blanksqr);
}

int			ft_c_blocks(f_list *tetriminos)
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

void		ft_feel_it(f_list *tet, char **sqr)
{
	int		i;
	char	c;
	int		j;
	int		y;

	i = 0;
	j = 0;
	y = 0;
	c = 'A';
	while (tet->next != NULL)
	{
		while (i < 4)
		{
			if (sqr[tet->x[i]][tet->y[i]] == '#' || sqr[tet->x[i + 1]]
			[tet->y[i + 1]] == '#' || sqr[tet->x[i + 2]][tet->y[i + 2]] == '#'
			|| sqr[tet->x[i + 3]][tet->y[i + 3]] == '#')
				tet->x[0] = tet->x[0] + 1;
			sqr[j][tet->y[i]] = c;
			i++;
		}
		i = 0;
		c++;
		tet = tet->next;
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

void		ft_fillit(f_list *tetriminos)
{
	int		sqrside;
	char	**sqr;

	sqrside = (ft_c_blocks(tetriminos) / ft_sqrt(ft_c_blocks(tetriminos)));
	sqr = (char **)malloc (sizeof(char *) * (sqrside + 1));
	if (!(sqr))
		return ;
	sqr = ft_blanksqr(sqrside);
	print_sqr(sqr, sqrside);
	ft_putchar('\n');
	ft_feel_it(tetriminos, sqr);
	print_sqr(sqr, sqrside);
}
