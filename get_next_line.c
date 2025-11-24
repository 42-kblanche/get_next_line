/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:47:47 by kblanche          #+#    #+#             */
/*   Updated: 2025/11/24 22:40:59 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#define GB g_buffer

static char	*g_buffer;

static int	init_buffer(void)
{
	if (!g_buffer)
	{
		g_buffer = malloc(BUFFER_SIZE);
		if (!g_buffer)
			return (0);
		g_buffer[0] = '\0';
	}
	return (1);
}
static ssize_t	refresh_buffer(int fd)
{
	ssize_t	read_err;
	size_t	trim_len;

	trim_len = check_for_nl(g_buffer);
	if (trim_len)
	{
		ft_memcpy(GB, GB + trim_len, ft_strlen(GB + trim_len, '\0') + 1);
		return (ft_strlen(GB, '\0'));
	}
	read_err = read(fd, g_buffer, BUFFER_SIZE);
	return (read_err);
}

char	*get_next_line(int fd)
{
	int		has_nl;
	char	*ret;
	size_t	ret_len;
	ssize_t	read_err;

	if (!init_buffer())
		return (NULL);
	has_nl = 0;
	ret = malloc(BUFFER_SIZE);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	ret_len = BUFFER_SIZE;
	while (!has_nl)
	{
		read_err = refresh_buffer(fd);
		if (read_err <= 1)
		{
			free(ret);
			free(g_buffer);
			return (NULL);
		}
		has_nl = check_for_nl(g_buffer);
		if (!concat(&ret, g_buffer, &ret_len))
		{
			free(g_buffer);
			return (NULL);
		}
	}
	return (ret);
}
