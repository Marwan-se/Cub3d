/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:27:49 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/19 12:21:44 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_next_line(int fd, char **line)
{
	char	*buff;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buff = malloc(sizeof(char) * 100);
	while (read(fd, &buff[i], 1) > 0)
	{
		if (buff[i] == '\n')
		{
			buff[i] = '\0';
			*line = malloc(sizeof(char) * (i + 1));
			while (j < i)
			{
				(*line)[j] = buff[j];
				j++;
			}
			(*line)[j] = '\0';
			return (buff);
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	while (j < dstsize - 1 && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}