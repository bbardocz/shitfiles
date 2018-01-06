/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 16:56:28 by bbardocz          #+#    #+#             */
/*   Updated: 2018/01/06 17:35:15 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include <stdio.h>

int		pos_is_valid(f_list *pieces, char **sqr, int sqrside, int *pos)
{
	int		*y;
	int		*x;
	int		i;
	int		j;

	y = pieces->y;
	x = pieces->x;
	j = 1;
	while (j)
	{
		j = 0;
		i = 0;
		while (i < 4)
		{
			if ((y[i] + *pos / sqrside) >= sqrside)
				return (0);
			if ((x[i] + *pos % sqrside) >= sqrside ||
			(sqr[y[i] + *pos / sqrside][x[i] + *pos %sqrside] != '.'))
				j = 1;
			i++;
		}
		if (j)
			(*pos)++;
	}
	i = 0;
	while (i < 4)
	{
		sqr[y[i] + *pos / sqrside][x[i] + *pos %sqrside] = pieces->c;
		i++;
	}
	return (1);
}

char	**remove_tet(char **sqr, f_list *pieces, int sqrside, int j)
{
	int		x;
	int		y;

	y = 0;
	while (sqr[y][x] != '\0')
	{
		x = 0;
		while (sqr[y][x] != '\0')
		{
			if (sqr[y][x] == pieces->c)
				sqr[y][x] = '.';
			x++;
		}
		y++;
	}
	return (sqr);
}

int		feel_it(f_list *pieces, char **sqr, int sqrside)
{
	int		i;
	int		j;
	int		*x;
	int		*y;
	int		pos;

	i = 0;
	j = 0;
	x = pieces->x;
	y = pieces->y;
	pos = 0;
	if (pieces == NULL)
		return (1);
	while (pos_is_valid(pieces, sqr, sqrside, &pos) == 1)
	{
		if (feel_it(pieces->next, sqr, sqrside) == 1)
			return (1);
		else
		{
			remove_tet(sqr, pieces, sqrside, j);
			pos++;
		}
	}
	return (0);
}

void	fillit(f_list *pieces)
{
	int		sqrside;
	char	**sqr;
	int		*pos;

	sqrside = (c_blocks(pieces) / ft_sqrt(c_blocks(pieces)));
	if (!(sqr))
		return ;
	sqr = blanksqr(sqrside);
	while (feel_it(pieces, sqr, sqrside) == 0)
	{
		sqrside++;
		free_map(sqr);
		sqr = blanksqr(sqrside);
	}
	print_sqr(sqr, sqrside);
}
