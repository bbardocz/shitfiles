/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:13:54 by bbardocz          #+#    #+#             */
/*   Updated: 2018/01/06 16:34:25 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

#include <stdio.h>

char	*trimline(char *piece)
{
	int	i;
	int	htag;

	htag = 0;
	i = 0;
	while (piece[i] != '\0')
	{
		while (piece[i] != '\n')
		{
			if (piece[i] == '#')
				htag = 1;
			i++;
		}
		i++;
		if (htag == 0)
		{
			piece = &piece[5];
			i = 0;
		}
	}
	return (piece);
}

char	*trimcol(char *tet)
{
	int	i;

	i = 0;
	while (tet[0] != '#' && tet[5] != '#' && tet[10] != '#' && tet[15] != '#')
	{
		while (tet[i] != '\0')
		{
			if (tet[i] == '#' && i != 0 && i != 5 && i != 10 && i != 15)
			{
				tet[i - 1] = '#';
				tet[i] = '.';
			}
			i++;
		}
		i = 0;
	}
	return (trimline(tet));
}

int		check_touch(char *piece)
{
	int	touch;
	int	i;

	touch = 0;
	i = 0;
	while (piece[i] != '\0')
	{
		if (piece[i] == '#' && (piece[i + 1] == '#' || piece[i + 5] == '#'
		|| piece[i - 1] == '#' || piece[i - 5] == '#'))
			touch++;
		i++;
	}
	if (touch != 4)
		return (-1);
	return (0);
}

int		check_pieces(f_list *pieces)
{
	int form;
	int i;

	while (pieces != NULL)
	{
		form = 0;
		i = -1;
		while (pieces->tet[++i] != '\0')
		{
			if (pieces->tet[i] == '.')
				form++;
			if (pieces->tet[i] == '#')
				form--;
		}
		if (form != 8 || pieces->tet[4] != '\n'
		|| pieces->tet[9] != '\n' || pieces->tet[14] != '\n'
		|| pieces->tet[19] != '\n' || check_touch(pieces->tet) == -1)
			return (-1);
		pieces->tet = trimcol(pieces->tet);
		pieces = pieces->next;
	}
	return (0);
}
