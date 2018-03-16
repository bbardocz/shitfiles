/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:51:02 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:30:11 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *string;

	string = (char *)malloc(sizeof(char) * size + 1);
	if (!(string))
		return (NULL);
	ft_bzero(string, size + 1);
	return (string);
}
