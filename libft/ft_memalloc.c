/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:29:52 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/19 19:24:31 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *memory;

	memory = (void *)malloc(sizeof(size_t) * size);
	if (!(memory))
		return (NULL);
	ft_bzero(memory, size);
	return (memory);
}
