/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:22:57 by bbardocz          #+#    #+#             */
/*   Updated: 2018/01/15 20:34:44 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>

int		find_eol(char *s)
{
	int			i;

	if (s == NULL)
		return (-1);
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (-1);
	if (s[i] == '\n')
		return (i);
	return (-2);
}

char	*strjoin_sel(char *line, char *save)
{
	if (!line)
		return (ft_strdup(save));
	return (ft_strjoin(line, save));
}

int		get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	int			ret;
	int			retr;

	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	if (*line && (retr = 1))
	{
		save = (ft_strchr(save, '\n'));
		ft_strncpy(*line, save, ft_strlen(save));
	}
	printf("%s\n", *line);
	if ((save = ft_realloc(save, BUFF_SIZE)) == NULL)
		return (-1);
	while ((ret = find_eol(*line)) == -1 && retr > 0)
		if ((retr = read(fd, save, BUFF_SIZE)) > 0)
		{
			save[retr] = '\0';
			*line = strjoin_sel(*line, save);
		}
	*line = ft_strsub(*line, 0, ret);
	if (ret > 0)
		return (1);
	free(save);
	save = NULL;
	return (0);
}
