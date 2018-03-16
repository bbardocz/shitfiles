/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 19:21:25 by bbardocz          #+#    #+#             */
/*   Updated: 2018/01/15 19:38:00 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *p, size_t size)
{
	void	*bite;

	if (!p)
		return (ft_memalloc(size));
	bite = ft_memalloc(size);
	ft_memcpy(bite, p, size);
	free(p);
	p = NULL;
	return (bite);
}
