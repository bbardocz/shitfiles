/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:04:31 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/13 16:49:39 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(char const *s)
{
	int		i;
	int		space;

	i = 0;
	space = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i++;
		space++;
	}
	if (s[i] == '\0')
		return (0);
	i = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		i--;
		space++;
	}
	return (ft_strlen(s) - space);
}

char		*ft_strtrim(char const *s)
{
	char	*string;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (s != NULL)
	{
		string = (char *)malloc(sizeof(char) * (len(s) + 1));
		if (!(string))
			return (0);
		while (s[i2] == ' ' || s[i2] == '\n' || s[i2] == '\t')
			i2++;
		while (i < len(s))
		{
			string[i] = s[i2];
			i++;
			i2++;
		}
		string[i] = '\0';
		return (string);
	}
	return (NULL);
}
