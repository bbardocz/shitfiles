/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 22:08:06 by bbardocz          #+#    #+#             */
/*   Updated: 2017/11/20 13:06:06 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*nisintmin(int n)
{
	char	*numbermin;
	long	nbr;
	int		i;

	numbermin = (char *)malloc(sizeof(char) * 12);
	nbr = n;
	nbr = -nbr;
	i = 10;
	while (nbr >= 10)
	{
		numbermin[i] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	numbermin[1] = nbr + '0';
	numbermin[0] = '-';
	numbermin[11] = '\0';
	return (numbermin);
}

static void		nisneg(int *neg, int *n, int *i)
{
	*neg = 1;
	*n = *n * -1;
	*i = *i + 1;
}

static char		*fillarray(int n, int i, int neg, char *number)
{
	while (n >= 10)
	{
		number[i] = n % 10 + '0';
		i--;
		n = n / 10;
	}
	if (n < 10)
		number[i] = n + '0';
	if (neg == 1)
	{
		number[0] = '-';
	}
	return (number);
}

char			*ft_itoa(int n)
{
	char	*number;
	int		nbr;
	int		i;
	int		neg;

	neg = 0;
	i = 1;
	if (n == -2147483648)
		return (nisintmin(n));
	if (n < 0)
		nisneg(&neg, &n, &i);
	nbr = n;
	while (nbr >= 10)
	{
		i++;
		nbr = nbr / 10;
	}
	number = (char *)malloc(sizeof(char) * (i + 1));
	if (!(number))
		return (NULL);
	number[i] = '\0';
	i--;
	return (fillarray(n, i, neg, number));
}
