/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:02:51 by kblanche          #+#    #+#             */
/*   Updated: 2025/11/24 22:33:51 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*s;
	char	*file;

	if (argc != 2)
		file = "test1.txt";
	else
		file = argv[1];
	fd = open(file, O_RDONLY);
	s = get_next_line(fd);
	i = 0;
	while (s && i < 10)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		printf("%s", s);
		++i;
	}
	close(fd);
	free (s);
	return (0);
}
