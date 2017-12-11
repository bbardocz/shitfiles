/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetriminos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:12:07 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/11 18:36:47 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "B_Header.h"

#include <stdio.h>
// diviser pour ligne y
// modulo pour colone x
void		ft_print_tetriminos(f_list *tet)
{
	while (tet->next != NULL)
	{
		int i = 0;
		ft_putstr(tet->t_tab);
		ft_putchar('\n');
		while (i < 4)
		{
			printf("x: %i\n", tet->x[i]);
			printf("y: %i\n", tet->y[i]);
			i++;
		}		
		printf("dif: x:%i y:%i\ndif: x:%i y:%i\n", tet->dif[0],
			tet->dif[1], tet->dif[2], tet->dif[3]);
		printf("dif: x:%i y:%i\n\ndif: x:%i y:%i\n", tet->dif[4],
			tet->dif[5], tet->dif[6], tet->dif[7]);
		printf("dif: x:%i y:%i\n", tet->dif[8],
			tet->dif[9]);
		tet = tet->next;
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
	printf("touch: %i\n", touch);
	if (touch != 4)
		return (-1);
	return (0);
}

char		*ft_trim2(char *tet)
{
	int		i;
	int		htag;

	htag = 0;
	i = 0;
	while (tet[i] != '\0')
	{
		while (tet[i] != '\n')
		{
			if (tet[i] == '#')
				htag = 1;
			i++;
		}
		i++;
		if (htag == 0)
		{
			tet = &tet[5];
			i = 0;
		}
	}
	printf("trim l: \n%s\n", tet);
	return (tet);
}

char		*ft_trim(char *tet)
{
	int		i;

	i = 0;
	printf("%s\n", tet);
	while (tet[0] != '#' && tet[5] != '#' && tet[10] != '#' && tet[15] != '#')
	{
	printf("0%c\n", tet[0]);
	printf("5%c\n", tet[5]);
	printf("10%c\n", tet[10]);
	printf("15%c\n", tet[15]);
		while (tet[i] != '\0')
		{
	//printf("%s\n", &tet[i]);
	//printf("i: %i\n", i);
			if (tet[i] == '#' && i != 0 && i != 5 && i != 10 && i !=15)
			{
				tet[i - 1] = '#';
				tet[i] = '.';
			}
			i++;
		}
		i = 0;
	}
	printf("trim c: \n%s\n", tet);
	return (ft_trim2(tet));
}

int			ft_check_tetriminos(f_list *tetriminos)
{
	int		form;
	int		i;

	while (tetriminos->next != NULL)
	{
		form = 0;
		i = -1;
		while (tetriminos->t_tab[++i] != '\0')
		{
			if (tetriminos->t_tab[i] == '.')
				form++;
			if (tetriminos->t_tab[i] == '#')
				form--;
		}
		if (form != 8 || tetriminos->t_tab[4] != '\n'
		|| tetriminos->t_tab[9] != '\n' || tetriminos->t_tab[14] != '\n'
		|| tetriminos->t_tab[19] != '\n'
		|| ft_check_touch(tetriminos->t_tab) == -1)
			return (-1);
		tetriminos->t_tab = ft_trim(tetriminos->t_tab);
		tetriminos = tetriminos->next;
	}
	return (0);
}

void		ft_fill_list(int fd, f_list *tetriminos)
{
	while (read(fd, tetriminos->t_tab, 21) != 0)
	{
		tetriminos->t_tab[20] = '\0';
		tetriminos->next = (f_list *)malloc(sizeof(f_list));
		if (!(tetriminos->next))
			return ;
		tetriminos = tetriminos->next;
		tetriminos->t_tab = (char *)malloc(sizeof(char) * 21);
		if (!(tetriminos->t_tab))
			return ;
	}
	free(tetriminos->t_tab);
	free(tetriminos);
	tetriminos->t_tab = NULL;
	tetriminos->next = NULL;
	tetriminos = NULL;
}

void		find_coord(f_list *tet)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 6)
	{
		tet->dif[j] = tet->x[i + 1] - tet->x[i];
		tet->dif[j + 1] = tet->y[i + 1] - tet->y[i];
		i++;
//		printf("dif: x:%i y:%i\n", tet->dif[j], tet->dif[j + 1]);
		j = j + 2;
	}
	tet->dif[6] = tet->x[2] - tet->x[0];
	tet->dif[7] = tet->y[2] - tet->y[0];
	tet->dif[8] = tet->x[3] - tet->x[0];
	tet->dif[9] = tet->y[3] - tet->y[0];
//	printf("\ndif: x:%i y:%i\ndif: x:%i y:%i\n", tet->dif[6],
//		tet->dif[7], tet->dif[8], tet->dif[9]);
//	ft_putstr("done\n");
}

f_list		*get_coord(f_list *tet)
{
	f_list	*ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	ret = tet;
	while (tet->next != NULL)
	{
		while (tet->t_tab[i] != '\0')
		{
			if (tet->t_tab[i] == '#')
			{
				tet->x[j] = i % 5;
				tet->y[j] = i / 5;
				j++;
			}
			i++;
		}
		find_coord(tet);
		j = 0;
		i = 0;
		tet = tet->next;
	}
	ft_print_tetriminos(ret);
	return (ret);
}

f_list		*ft_get_tetriminos(int fd)
{
	f_list	*tetriminos;
	f_list	*check;
	f_list	*first;

	tetriminos = (f_list *)malloc(sizeof(f_list));
	tetriminos->t_tab = (char *)malloc(sizeof(char) * 21);
	read(fd, tetriminos->t_tab, 21);
	tetriminos->t_tab[20] = '\0';
	first = tetriminos;
	check = tetriminos;
	tetriminos->next = (f_list *)malloc(sizeof(f_list));
	if (!(tetriminos->next) || !(tetriminos->t_tab) || !(tetriminos))
		return (NULL);
	tetriminos = tetriminos->next;
	tetriminos->t_tab = (char *)malloc(sizeof(char) * 21);
	ft_fill_list(fd, tetriminos);
//	ft_print_tetriminos(first);
	if (ft_check_tetriminos(check) == 0)
	{
		ft_putstr("SUCCES\n");
		return (get_coord(first));
	}
	return (NULL);
}
