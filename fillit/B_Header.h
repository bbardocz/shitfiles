/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:35:39 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/15 14:31:06 by bbardocz         ###   ########.fr       */
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

void						print_sqr(char **sqr, int sqrside);
int							ft_sqrt(int nb);
char						**trim(char **tetriminos);
