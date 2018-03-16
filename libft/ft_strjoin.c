/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:42:22 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/21 20:56:21 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	dosomething(char const *s1, char *string, int *i1, int *i3)
{
	string[*i3] = s1[*i1];
	*i1 = *i1 + 1;
	*i3 = *i3 + 1;
}

static void	dosomethingelse(char const *s2, char *string, int *i2, int *i3)
{
	string[*i3] = s2[*i2];
	*i2 = *i2 + 1;
	*i3 = *i3 + 1;
}

static char	*addzero(char *string, int *i3, char const *s1, char const *s2)
{
	int		i;

	i = 0;
	if (s2[i] == '\0')
	{
		while (s1[i] != '\0')
		{
			string[i] = s1[i];
			i++;
		}
		string[i] = '\0';
	}
	if (string[i] != '\0')
		string[*i3] = '\0';
	return (string);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	int		size;
	int		i1;
	int		i2;
	int		i3;

	i1 = 0;
	i2 = 0;
	i3 = 0;
	if (s1 != NULL && s2 != NULL)
	{
		size = ft_strlen(s1) + ft_strlen(s2) + 1;
		string = (char *)malloc(sizeof(char) * size);
		if (!(string))
			return (NULL);
		while (s2[i2] != '\0')
		{
			if (s1[i1] != '\0')
				dosomething(s1, string, &i1, &i3);
			if (s1[i1] == '\0' && s2[i2] != '\0')
				dosomethingelse(s2, string, &i2, &i3);
		}
		return (addzero(string, &i3, s1, s2));
	}
	return (NULL);
}
