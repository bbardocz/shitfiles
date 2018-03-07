/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 16:37:13 by bbardocz          #+#    #+#             */
/*   Updated: 2018/03/07 17:37:08 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include "FdF.h"

int **translation_matrice(void)
{
	int **M;
	int i;

	i = 0;
	M = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		M[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	M[0][0] = 1;
	M[0][1] = 0;
	M[0][2] = 0;
	M[0][3] = TX;
	M[1][0] = 0;
	M[1][1] = 1;
	M[1][2] = 0;
	M[1][3] = TY;
	M[2][0] = 0;
	M[2][1] = 0;
	M[2][2] = 1;
	M[2][3] = TZ;
	M[3][0] = 0;
	M[3][1] = 0;
	M[3][2] = 0;
	M[3][3] = 1;
	return (M);
}

int **scaling_matrice(void)
{
	int **M;
	int i;

	i = 0;
	M = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		M[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	M[0][0] = SX;
	M[0][1] = 0;
	M[0][2] = 0;
	M[0][3] = 0;
	M[1][0] = 0;
	M[1][1] = SY;
	M[1][2] = 0;
	M[1][3] = 0;
	M[2][0] = 0;
	M[2][1] = 0;
	M[2][2] = SZ;
	M[2][3] = 0;
	M[3][0] = 0;
	M[3][1] = 0;
	M[3][2] = 0;
	M[3][3] = 1;
	return (M);
}

int	**matrice_mult(int **M1, int **M2)
{
	int i;
	int j;
	int **M3;

	i = 0;
	M3 = (int **)malloc(sizeof(int *) * 4);
	while (i < 4)
	{
		M3[i] = (int *)malloc(sizeof(int) * 4);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			M3[i][j] = M1[i][0] * M2[0][j] +
					M1[i][1] * M2[1][j] +
					M1[i][2] * M2[2][j] +
					M1[i][3] * M2[3][j];
			j++;
		}
		i++;
	}
	return (M3);
}
