/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kblanche <kblanche@42angouleme.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 18:46:53 by kblanche          #+#    #+#             */
/*   Updated: 2025/11/24 22:40:32 by kblanche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stddef.h>

char	*get_next_line(int fd);
size_t	check_for_nl(char *s);
size_t	ft_strlen(char *s, char c);
int		concat(char **dest, char *src, size_t *dest_len);
void	*ft_memcpy(void *dest, const void *src, size_t n);

#endif
