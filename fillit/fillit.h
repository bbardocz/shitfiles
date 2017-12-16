/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:35:39 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/16 14:51:30 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct				fillit_list
{
	char					*t_tab;
	int						x[4];
	int						y[4];
	int						dif[10];
	struct fillit_list		*next;
}							f_list;

f_list						*get_tetriminos(int fd);
void						fillit(f_list *tetriminos);
void						print_sqr(char **sqr, int sqrside);
int							ft_sqrt(int nb);
