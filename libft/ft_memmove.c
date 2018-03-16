/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:05:32 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:28:55 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *source;
	char *destination;

	source = (char *)src;
	destination = (char *)dst;
	if (source < destination)
	{
		source = source + len - 1;
		destination = destination + len - 1;
		while (len > 0)
		{
			*destination-- = *source--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*destination++ = *source++;
			len--;
		}
	}
	return (dst);
}
