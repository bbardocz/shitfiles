/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:49:47 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/20 13:08:49 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*cur;
	char	*reader;
	size_t	len;

	cur = (char *)ft_memchr(dst, '\0', size);
	if (cur == NULL)
		return (size + ft_strlen(src));
	reader = (char *)src;
	len = (size_t)(cur - dst) + ft_strlen(reader);
	while ((size_t)(cur - dst) < size - 1 && *reader != '\0')
	{
		*cur = *reader;
		cur++;
		reader++;
	}
	*cur = '\0';
	return (len);
}
