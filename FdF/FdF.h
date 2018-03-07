/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FdF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:50:58 by bbardocz          #+#    #+#             */
/*   Updated: 2018/03/07 17:26:45 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define TX 2
# define TY 2
# define TZ 2
# define SX 2
# define SY 2
# define SZ 2

typedef struct		s_coord
{
	int				**tab;
	int				struct_i;
	struct s_coord	*next;
}					t_coord;

t_coord		*create_struct(int);
void		put_line(int *tab, void *mlx_ptr, void *win_ptr);
int			**translation_matrice(void);
int			**scaling_matrice(void);
int			**matrice_mult(int **M1, int **M2);
#endif
