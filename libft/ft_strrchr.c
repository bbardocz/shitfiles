/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:31:26 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:30:33 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*string;
	char	chr;
	char	end;

	string = (char *)s;
	chr = (char)c;
	end = *string;
	while (*string != '\0')
		string++;
	while (*string != chr)
	{
		if (*string == end)
			return (NULL);
		string--;
	}
	return (string);
}
