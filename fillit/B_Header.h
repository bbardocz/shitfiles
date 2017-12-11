/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:35:39 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/09 16:36:39 by bbardocz         ###   ########.fr       */
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

int							ft_sqrt(int nb);
char						**trim(char **tetriminos);
