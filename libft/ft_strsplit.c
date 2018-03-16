/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 20:56:25 by bbardocz          #+#    #+#             */
/*   Updated: 2018/03/05 23:19:46 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(char const *s, char c)
{
	int		wordcount;
	int		i;

	i = 0;
	wordcount = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			break ;
		i++;
	}
	if (s[i] == '\0' && c != '\0')
		return (-1);
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			wordcount++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (wordcount);
}

static char	*putword(char const *s, char c)
{
	char	*word;
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	ft_strncpy(word, s, i);
	word[i + 1] = '\0';
	return (word);
}

static char	**norminette(char const *s, char c)
{
	char	**array;
	int		is;
	int		ia;

	is = 0;
	ia = 0;
	array = (char**)malloc(sizeof(char *) * (countwords(s, c) + 1));
	if (!(array))
		return (NULL);
	while (s[is] != '\0')
	{
		while (s[is] == c)
			is++;
		if (s[is] != '\0')
		{
			array[ia] = putword(&s[is], c);
			ia++;
		}
		while (s[is] != c && s[is] != '\0')
			is++;
	}
	array[ia] = NULL;
	return (array);
}

static char	**noseparator(char const *s)
{
	char	**sadarray;
	char	*sadword;
	int		i;

	sadarray = (char**)malloc(sizeof(char *) * 2);
	i = 0;
	while (s[i] != '\0')
		i++;
	sadword = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] != '\0')
	{
		sadword[i] = s[i];
		i++;
	}
	sadword[i] = '\0';
	sadarray[0] = sadword;
	sadarray[1] = NULL;
	return (sadarray);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**emptyarray;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) == 0)
	{
		emptyarray = (char **)malloc(sizeof(char *) * 2);
		if (!(emptyarray))
			return (NULL);
		emptyarray[0] = NULL;
		emptyarray[1] = NULL;
		return (emptyarray);
	}
	if (countwords(s, c) == -1)
		return (noseparator(s));
	else
		return (norminette(s, c));
}
