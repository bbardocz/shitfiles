/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbardocz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:12:37 by bbardocz          #+#    #+#             */
/*   Updated: 2018/01/15 19:46:34 by bbardocz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	*line = NULL;
	int		ret;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	while ((ret = get_next_line(fd, &line)) != 0)
	{
		if (ret == -1)
		{
			printf("error\n");
			return (0);
		}
		printf("RESULT: %s\n", line);
	}
//	get_next_line(fd, &line);
	return (0);
}
