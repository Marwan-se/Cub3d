/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 13:24:34 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:11:33 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char	*c;
	char	*line;
	char	*tmp;
	int		count;

	line = ft_strdup("");
	c = malloc(2);
	if (fd < 0 || read(fd, c, 0) == -1)
		return (free(line), free(c), NULL);
	count = read(fd, c, 1);
	if (count <= 0)
		return (free(line), free(c), NULL);
	while (count > 0)
	{
		*(c + 1) = 0;
		tmp = line;
		line = ft_strjoin(line, c);
		free(tmp);
		if (*c == '\n')
			break ;
		count = read(fd, c, 1);
	}
	free(c);
	return (line);
}
