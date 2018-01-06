/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 17:00:44 by bbardocz          #+#    #+#             */
/*   Updated: 2018/01/06 17:19:49 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include <stdio.h>

void	print_sqr(char **sqr, int sqrside)
{
	int		i;

	i = 0;
	while (i < sqrside)
	{
		ft_putendl(sqr[i]);
		i++;
	}
}

void	free_map(char **sqr)
{
	int		i;

	i = 0;
	while (sqr[i])
	{
		free(sqr[i]);
		i++;
	}
	free(sqr);
}

int		c_blocks(f_list *pieces)
{
	int		i;
	int		c_blocks;

	c_blocks = 0;
	while (pieces != NULL)
	{
		i = 0;
		while (pieces->tet[i] != '\0')
		{
			if (pieces->tet[i] == '#')
				c_blocks++;
			i++;
		}
		pieces = pieces->next;
	}
	return (c_blocks);
}

char	**blanksqr(int sqrside)
{
	int		x;
	int		y;
	int		i;
	int		j;
	char	**blanksqr;

	y = sqrside;
	j = 0;
	blanksqr = (char **)malloc(sizeof(char *) * (sqrside + 1));
	while (y-- != 0)
	{
		x = sqrside;
		i = 0;
		blanksqr[j] = (char *)malloc(sizeof(char) * (sqrside + 1));
		while (x-- != 0)
		{
			blanksqr[j][i] = '.';
			i++;
		}
		blanksqr[j][i] = '\0';
		j++;
	}
	blanksqr[j] = ft_strnew((size_t)sqrside);
	return (blanksqr);
}
