/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:30:18 by bbardocz          #+#    #+#             */
/*   Updated: 2018/03/06 21:43:24 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "FdF.h"
#include <stdio.h>

void	fill_struct(t_coord *coord, char *line)
{
	int			i;
	char		**split;
	static int	n = 0;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i] != '\0')
	{
		coord->tab[i][0] = i;
		coord->tab[i][1] = n;
		coord->tab[i][2] = ft_atoi(split[i]);
		printf("x: %i | y: %i | z: %i\n",
		coord->tab[i][0], coord->tab[i][1], coord->tab[i][2]);
		i++;
	}
	n++;
}

int		 read_file(char **line, t_coord **coord, t_coord **first, t_coord **pre)
{
	int		i;

	i = 0;
	if (!((*coord)->next = (t_coord*)malloc(sizeof(t_coord))))
		return (-1);
	if (!((*coord)->tab = (int**)malloc(sizeof(int*) * ft_strlen(*line))))
		return (-1);
	while ((size_t)i < ft_strlen(*line))
	{
		if(!((*coord)->tab[i] = (int*)malloc(sizeof(int) * 3)))
			return (-1);
		i++;
	}
	fill_struct(*coord, *line);
	if (!(*first))
		(*first) = (*coord);
	(*pre) = (*coord);
	(*coord) = (*coord)->next;
	return (0);
}

t_coord	*create_struct(int fd)
{
	char	*line[10];
	t_coord	*coord;
	t_coord *first;
	t_coord *pre;

	first = NULL;
	if (!(coord = (t_coord*)malloc(sizeof(t_coord))))
		return (NULL);
	while (get_next_line(fd, line) > 0)
		read_file(line, &coord, &first, &pre);
	pre->next = NULL;
	free(coord);
	coord = NULL;
	return (first);
}
