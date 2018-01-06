/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:14:15 by bbardocz          #+#    #+#             */
/*   Updated: 2018/01/06 17:00:19 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	f_list	*pieces;

	(void)argv;
	if (argc != 2)
	{
		ft_putstr("./fillit file.txt\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd != -1)
	{
		pieces = get_pieces(fd);
		fillit(pieces);
	}
	return (0);
}
