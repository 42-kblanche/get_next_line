/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:47:47 by kblanche          #+#    #+#             */
/*   Updated: 2025/12/16 12:04:18 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#define GB g_buffer
#define LOOP_RET_KO 0
#define LOOP_RET_OK 1
#define LOOP_RET_EOF 2

static char	*g_buffer;

static int	init_buffer(void)
{
	if (!g_buffer)
	{
		g_buffer = malloc(BUFFER_SIZE + 1);
		if (!g_buffer)
			return (0);
		g_buffer[0] = '\0';
		g_buffer[BUFFER_SIZE] = '\0';
	}
	return (1);
}

static ssize_t	refresh_buffer(int fd)
{
	ssize_t	read_len;
	size_t	trim_len;

	trim_len = check_for_nl(g_buffer + 1);
	if (trim_len)
	{
		ft_memcpy(GB, GB + trim_len, ft_strlen(GB + trim_len, '\0') + 1);
		return (ft_strlen(g_buffer, '\0'));
	}
	read_len = read(fd, g_buffer, BUFFER_SIZE);
	if (read_len >= 0)
		g_buffer[read_len] = '\0';
	return (read_len);
}

static int	get_next_line_loop(int fd, char **ret)
{
	int		has_nl;
	size_t	ret_len;
	ssize_t	read_err;

	has_nl = 0;
	read_err = -1;
	ret_len = BUFFER_SIZE;
	while (!has_nl && read_err)
	{
		read_err = refresh_buffer(fd);
		if (read_err < 0)
		{
			free(*ret);
			return (LOOP_RET_KO);
		}
		has_nl = check_for_nl(g_buffer);
		if (!concat(ret, g_buffer, &ret_len))
			return (LOOP_RET_KO);
	}
	if (!read_err)
		return (LOOP_RET_EOF);
	return (LOOP_RET_OK);
}

char	*get_next_line(int fd)
{
	char	*ret;
	int		loop_ret;

	if (BUFFER_SIZE <= 0 || !init_buffer())
		return (NULL);
	ret = malloc(BUFFER_SIZE + 1);
	if (!ret)
		return (NULL);
	ret[0] = '\0';
	ret[BUFFER_SIZE] = '\0';
	loop_ret = get_next_line_loop(fd, &ret);
	if (loop_ret == LOOP_RET_OK)
		return (ret);
	else
	{
		free(g_buffer);
		if (loop_ret == LOOP_RET_EOF)
			return (ret);
		else
			return (NULL);
	}
}
