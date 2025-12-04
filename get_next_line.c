/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:47:47 by kblanche          #+#    #+#             */
/*   Updated: 2025/12/04 19:20:12 by kblanche         ###   ########.fr       */
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
#ifdef DEBUG
		debugs(GB);
#endif /* ifdef DEBUG */
		return (ft_strlen(GB, '\0'));
	}
	read_err = read(fd, g_buffer, BUFFER_SIZE);
#ifdef DEBUG
	debugs(GB);
#endif /* ifdef DEBUG */
	return (read_err);
}

static int	get_next_line_loop(int fd, char **ret)
{
	int		has_nl;
	size_t	ret_len;
	ssize_t	read_err;

	has_nl = 0;
	ret_len = BUFFER_SIZE;
	while (!has_nl)
	{
		read_err = refresh_buffer(fd);
		if (read_err <= 1)
		{
			free(*ret);
			free(g_buffer);
			return (0);
		}
		has_nl = check_for_nl(g_buffer);
		if (!concat(ret, g_buffer, &ret_len))
		{
			free(g_buffer);
			return (0);
		}
#ifdef DEBUG
		debugs(*ret);
#endif /* ifdef DEBUG */
	}
	return (1);
}

char	*get_next_line(int fd)
{
	char	*ret;

	if (!init_buffer())
		return (NULL);
	ret = malloc(BUFFER_SIZE);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	if (get_next_line_loop(fd, &ret))
	{
#ifdef DEBUG
		infos("END OF GNL CALL");
#endif /* ifdef DEBUG */
		return (ret);
	}
	return (NULL);
}
