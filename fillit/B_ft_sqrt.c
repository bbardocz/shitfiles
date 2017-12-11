/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 14:53:08 by bbardocz          #+#    #+#             */
/*   Updated: 2017/12/06 15:35:04 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	long nbm;
	long sqrt;

	nbm = nb;
	sqrt = 1;
	if (nbm == 1)
	{
		return (1);
	}
	while (sqrt * sqrt <= nbm)
	{
		if (sqrt * sqrt == nbm)
		{
			return (sqrt);
		}
		else
			sqrt++;
	}
	return (sqrt - 1);
}
