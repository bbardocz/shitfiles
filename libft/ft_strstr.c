/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:37:21 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:32:15 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		cmp(const char *s1, const char *s2)
{
	while (*s2 != '\0')
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

char			*ft_strstr(const char *haystack, const char *needle)
{
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if (cmp(haystack, needle) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
