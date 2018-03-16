/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:52:50 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:32:31 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*string;
	unsigned int	i;

	if (s != NULL)
	{
		i = 0;
		string = (char *)malloc(sizeof(char) * len + 1);
		if (!(string))
			return (NULL);
		while (s[start] != '\0' && i < len)
		{
			string[i] = s[start];
			i++;
			start++;
		}
		string[i] = '\0';
		return (string);
	}
	return (NULL);
}
