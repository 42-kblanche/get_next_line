/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 20:02:34 by kblanche          #+#    #+#             */
/*   Updated: 2025/12/04 18:18:30 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

size_t	check_for_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		++i;
	}
	return (0);
}

size_t	ft_strlen(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		++i;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		++i;
	}
	return (dest);
}

int	concat(char **dest, char *src, size_t *dest_len)
{
	size_t	i;
	size_t	l;
	char	*t;

	i = ft_strlen(*dest, '\0');
	l = ft_strlen(src, '\n');
	if (src[l] == '\n')
		l += 1;
	if (i + l > *dest_len)
	{
		*dest_len = i + l;
		t = malloc(*dest_len + 1);
		if (!t)
		{
			free((*dest));
			return (0);
		}
		ft_memcpy(t, (*dest), i);
		free((*dest));
		(*dest) = t;
	}
	ft_memcpy((*dest) + i, src, l);
	return (1);
}
