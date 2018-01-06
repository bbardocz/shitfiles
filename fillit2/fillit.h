/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:10:25 by bbardocz          #+#    #+#             */
/*   Updated: 2018/01/06 17:21:09 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct				fillit_list
{
	char					*tet;
	int						x[4];
	int						y[4];
	char					c;
	struct fillit_list		*next;
}							f_list;

int							ft_sqrt(int nb);
f_list						*get_pieces(int fd);
int							check_pieces(f_list *check);
void						fillit(f_list *pieces);
char						**blanksqr(int sqrside);
int							c_blocks(f_list *pieces);
void						print_sqr(char **sqr, int sqrside);
void						free_map(char **sqr);
