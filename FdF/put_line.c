/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:39:53 by bbardocz          #+#    #+#             */
/*   Updated: 2018/03/06 18:41:50 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void		x1_equal_x2(int *tab, void *mlx_ptr, void *win_ptr)
{
	int		x;
	int		y;

	x = tab[0];
	y = tab[1];
	while (y <= tab[3])
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ffffff);
		y++;
	}
}

void		put_line(int *tab, void *mlx_ptr, void *win_ptr)
{
	int		x;
	int		y;
	double	a;
	double	b;

	a = (double)(tab[3] - tab[1]) / (tab[2] - tab[0]);
	b = tab[1] - (a * tab[0]);
	x = tab[0];
	if (x < tab[2])
		while (x <= tab[2])
		{
			y = (int)((a * x) + b);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ffffff);
			x++;
		}
	else if (x > tab[2])
		while (x >= tab[2])
		{
			y = (int)((a * x) + b);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x00ffffff);
			x--;
		}
	else if (x == tab[2])
		x1_equal_x2(tab, mlx_ptr, win_ptr);
}
