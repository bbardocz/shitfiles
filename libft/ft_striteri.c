/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 20:12:57 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/21 21:02:47 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int index;

	index = 0;
	if (s != NULL && (*f) != NULL)
	{
		while (s[index] != '\0')
		{
			f(index, &s[index]);
			index++;
		}
	}
}
