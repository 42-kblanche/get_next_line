/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 01:16:22 by kblanche          #+#    #+#             */
/*   Updated: 2026/01/29 05:00:25 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	char	*line;
	int		fd;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	else
		fd = 0;
	if (fd < 0)
		return (fd);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
		if (line[0] == '!' && line[1] == 'q'
			&& (line[2] == '\n' || line[2] == '\0'))
		{
			free(line);
			line = NULL;
		}
	}
	close(fd);
	return (0);
}
