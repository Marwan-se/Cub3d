/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:26:47 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/20 13:25:55 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**read_map_file(char *file)
{
	int		fd;
	char	**map;
	char	*joind_str;
	char	*line;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file\n");
		exit(1);
	}
	line = (char *)malloc(2);
	if (!line)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(fd, line, 1);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		line[i] = '\0';
		// printf("here\n");
		joind_str = ft_strjoin(joind_str, line);
	}
	free(line);
	map = ft_split(joind_str, '\n');
	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
