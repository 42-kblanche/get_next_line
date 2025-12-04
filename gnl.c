/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 19:02:51 by kblanche          #+#    #+#             */
/*   Updated: 2025/12/04 19:32:10 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "debug.h"

int	gnl_test(int fd)
{
	char	*s;

	s = get_next_line(fd);
	if (!s)
	{
		errors("LINE EMPTY");
		return (0);
	}
	printf("%s", s);
	//printf("%s%s%s", BLUE, s, NEUTRAL);
	free(s);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		s;
	char	*file;

	if (argc != 2)
		file = "test1.txt";
	else
		file = argv[1];
	fd = open(file, O_RDONLY);
	s = gnl_test(fd);
	i = 1;
	while (s && i < 50)
	{
		s = gnl_test(fd);
		++i;
	}
	close(fd);
	return (0);
}
