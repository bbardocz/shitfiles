/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:22:57 by bbardocz          #+#    #+#             */
/*   Updated: 2018/03/12 22:29:31 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_n_index(char *save)
{
	int			i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	return (i);
}

int		gnl_check(char **line, char *save, int ret, int last)
{
	if (ret == -1)
		return (-1);
	if (ft_n_index(save) == 0 || (last == 1 && ret == 0))
		*line = ft_strdup("");
	else
		*line = ft_strsub(save, 0, ft_n_index(save));
	if (!(*line))
		return (-1);
	if (save[ft_n_index(save)])
		ft_strncpy(save, save + ft_n_index(save) + 1, ft_strlen(save));
	else
		ft_strncpy(save, save + ft_n_index(save), ft_strlen(save));
	if (ret > 0 || last == 1 || *line[0] > 32)
	{
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static char	*save = NULL;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;
	int			last;

	last = 0;
	if (fd < 0 || BUFF_SIZE < 0 || !line)
		return (-1);
	if (!save)
		if (!(save = ft_strnew(BUFF_SIZE + 1)))
			return (-1);
	if (save[0] == '\n')
		last = 1;
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = save;
		if (!(save = ft_strjoin(save, buff)))
			return (-1);
		free(tmp);
		if (ft_strchr(save, '\n'))
			break ;
	}
	return (gnl_check(line, save, ret, last));
}
