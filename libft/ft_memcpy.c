/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:24:10 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/26 18:56:30 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*source;
	char		*destination;
	size_t		i;

	i = 0;
	source = src;
	destination = dst;
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (destination);
}
