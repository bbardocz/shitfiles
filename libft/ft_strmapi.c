/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 21:19:41 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:29:38 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*string;

	if (s != NULL)
	{
		index = 0;
		string = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!(string))
			return (NULL);
		while (s[index] != '\0')
		{
			string[index] = f(index, s[index]);
			index++;
		}
		string[index] = '\0';
		return (string);
	}
	return (NULL);
}
