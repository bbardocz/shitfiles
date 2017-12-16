/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:04:25 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/16 14:49:59 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	f_list	*tetriminos;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr("./fillit file.txt\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
	{
		tetriminos = get_tetriminos(fd);
		if (tetriminos == NULL)
		{
			ft_putstr("It failed\n");
			return (0);
		}
		if (tetriminos != NULL)
			ft_putstr("It didn't fail nigga\n");
		fillit(tetriminos);
	}
	else if (fd == -1)
	{
		tetriminos = NULL;
		return (0);
	}
	return (0);
}
