/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:44:04 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:31:15 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;
	unsigned char	*s;
	size_t			i;

	value = c;
	s = b;
	i = 0;
	while (i < len)
	{
		s[i] = value;
		i++;
	}
	return (s);
}
