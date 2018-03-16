/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:16:52 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:29:26 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*string;
	int		i;

	if (s != NULL)
	{
		i = 0;
		string = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!(string))
			return (NULL);
		while (s[i] != '\0')
		{
			string[i] = f(s[i]);
			i++;
		}
		string[i] = '\0';
		return (string);
	}
	return (NULL);
}
