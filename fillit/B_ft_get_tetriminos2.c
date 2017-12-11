/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:12:07 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/06 20:21:01 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "B_header.h"

#include <stdio.h>

void		ft_print_tetriminos(char **tetriminos)
{
	int		y;

	y = 0;
	while (tetriminos[y] != NULL)
	{
		ft_putstr(tetriminos[y]);
		ft_putchar('\n');
		y++;
	}
}

int			ft_check_touch(char *tetriminos)
{
	int		touch;
	int		i;

	touch = 0;
	i = 0;
	while (tetriminos[i] != '\0')
	{
		if (tetriminos[i] == '#' && (tetriminos[i + 1]
		== '#' || tetriminos[i + 5]
		== '#' || tetriminos[i - 1]
		== '#' || tetriminos[i - 5] == '#'))
			touch++;
		i++;
	}
	if (touch != 4)
		return (-1);
	return (0);
}

int			ft_check_tetriminos(char **tetriminos)
{
	int		form;
	int		i;
	int		y;

	y = 0;
	i = 0;
	while (tetriminos[y] != NULL)
	{
		form = 0;
		i = -1;
		while (tetriminos[y][++i] != '\0')
		{
			if (tetriminos[y][i] == '.')
				form++;
			if (tetriminos[y][i] == '#')
				form--;
		}
		if (form != 8 || tetriminos[y][4] != '\n'
		|| tetriminos[y][9] != '\n' || tetriminos[y][14] != '\n'
		|| tetriminos[y][19] != '\n'
		|| ft_check_touch(tetriminos[y]) == -1)
			return (-1);
		y++;
	}
	return (0);
}

void		ft_fill_list(int fd, char **tetriminos)
{
	int		i;

	i = 1;
	while (read(fd, tetriminos[i], 21) != 0)
	{
		tetriminos[i][20] = '\0';
		tetriminos[i + 1] = (char *)malloc(sizeof(char) * 21);
		if (!(tetriminos[i + 1]))
			return ;
		i++;
	}
	free(tetriminos[i]);
	tetriminos[i] = NULL;
}

char		**ft_get_tetriminos(int fd)
{
	char	**tetriminos;

	tetriminos = (char **)malloc(sizeof(char *) * 27);
	tetriminos[0] = (char *)malloc(sizeof(char) * 21);
	read(fd, tetriminos[0], 21);
	tetriminos[0][20] = '\0';
	if (!(tetriminos) || !(tetriminos[0]))
		return (NULL);
	tetriminos[1] = (char *)malloc(sizeof(char) * 21);
	ft_fill_list(fd, tetriminos);
	ft_print_tetriminos(tetriminos);
	if (ft_check_tetriminos(tetriminos) == 0)
	{	
		tetriminos = trim(tetriminos);
		ft_print_tetriminos(tetriminos);
		return (tetriminos);
	}
	return (NULL);
}
