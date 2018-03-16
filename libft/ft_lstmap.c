/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 16:29:13 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/23 16:27:35 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *first;
	t_list *new;

	new = f(lst);
	first = new;
	while ((lst = lst->next))
	{
		new->next = f(lst);
		new = new->next;
	}
	return (first);
}
