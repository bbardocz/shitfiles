/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:06:01 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:27:46 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*string;
	char	chr;

	string = (char *)s;
	chr = (char)c;
	while (*string != chr)
	{
		if (*string == '\0')
			return (NULL);
		string++;
	}
	return (string);
}
