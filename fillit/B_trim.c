/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_trim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 17:15:46 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/07 15:18:55 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "B_Header.h"
#include "libft.h"

int		ft_c_tetriminos(char **tetriminos)
{
	int y;

	y = 0;
	while (tetriminos[y] != NULL)
	{
		y++;
	}
	return (y);
}

int		tlen(char *tetriminos)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] == '#')
			c = 4;
		if (tetriminos[i + ])
	}
}

char	*trimit(char *tetriminos)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] == '#')
			c++;
		if (c == 4)
			tetriminos[i + 1] = '\0';
		i++;
	}
}

char	**trim(char **tetriminos)
{
	int y;
	char **trim;

	y = 0;
	trim = (char **)malloc(sizeof(char *) * ft_c_tetriminos(tetriminos));
	while (tetriminos[y] != NULL)
	{
		trim[y] = (char *)malloc(sizeof(char) * tlen(tetriminos[y]));
		trim[y] = trimit(tetriminos[y])
		y++;
	}
	return (tetriminos);
}
