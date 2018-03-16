/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:28:43 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/23 15:46:02 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t index;

	i = len;
	index = 0;
	while (s2[index] != '\0')
	{
		if (s1[index] != s2[index] || i == 0)
			return (1);
		index++;
		i--;
	}
	if (s1[index] == '\0' && s2[index] == '\0')
		return (0);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack != '\0' && len > 0)
	{
		if (cmp(haystack, needle, len) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
