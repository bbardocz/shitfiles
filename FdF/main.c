/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:26:43 by bbardocz          #+#    #+#             */
/*   Updated: 2018/03/07 17:38:46 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include <fcntl.h>
#include "FdF.h"
#include <stdio.h>
#include "mlx.h"

int		main(int argc, char **argv)
{
	int		i;
	int		i2;
	int		fd;
	t_coord	*coord;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	coord = create_struct(fd);
/*	while (coord != NULL)
	{
		i = 0;
		printf("New row\n");
		while (i < 5)
		{
			printf("x: %i | y: %i | z: %i\n",
			coord->tab[i][0], coord->tab[i][1], coord->tab[i][2]);
			i++;
		}
		coord = coord->next;
	}*/

	void *mlx_ptr;
	void *win_ptr;
	int tab[4];

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "FdF");

	int Mp[4][4];
	Mp[0][0] = 2; Mp[0][1] = 3; Mp[0][2] = 6; Mp[0][3] = 1;
	int **M_trans;
	M_trans = translation_matrice();
	printf("Before \nx: %i | y: %i | z: %i\n", Mp[0][0], Mp[0][1], Mp[0][2]);
	int **Mr;
	Mr = matrice_mult(Mp, M_trans);
	printf("After \nx: %i | y: %i | z: %i\n", Mp[0][0], Mp[0][1], Mp[0][2]);

	i2 = 0;
	while (coord != NULL)
	{
		i = 0;
		while (i < 4)
		{
			tab[0] = 300 + (coord->tab[i][0] - i2);
			tab[1] = 300 + ((coord->tab[i][1] / 2) + (i * 0.5));
			tab[2] = 300 + (coord->tab[i + 1][0] - i2);
			tab[3] = 300 + ((coord->tab[i + 1][1] / 2) + (i * 0.5));
			put_line(tab, mlx_ptr, win_ptr);
			i++;
			printf("x: %i | y: %i || x': %i | y' %i\n",
					tab[0], tab[1], tab[2], tab[3]);
		}
		i = 0;
		while (coord->next != NULL && i < 5)
		{
			tab[0] = 300 + (coord->tab[i][0] - i2);
			tab[1] = 300 + ((coord->tab[i][1] / 2) + (i * 0.5));
			tab[2] = 300 + (coord->next->tab[i][0] - i2);
			tab[3] = 300 + ((coord->next->tab[i][1] / 2) + (i * 0.5));
			i++;
			printf("x: %i | y: %i || x': %i | y' %i\n",
					tab[0], tab[1], tab[2], tab[3]);
		}
		coord = coord->next;
		i2 = i2 + 100;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
