/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 18:04:25 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/07 19:26:56 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "B_Header.h"

f_list	*ft_get_tetriminos(int fd);
void	ft_fillit(f_list *tetriminos);
int		ft_sqrt(int nb);

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
		tetriminos = ft_get_tetriminos(fd);
		if (tetriminos == NULL)
		{
			ft_putstr("It failed\n");
			return (0);
		}
		if (tetriminos != NULL)
			ft_putstr("It didn't fail nigga\n");
		ft_fillit(tetriminos);
	}
	else if (fd == -1)
	{
		tetriminos = NULL;
		return (0);
	}
	return (0);
}
