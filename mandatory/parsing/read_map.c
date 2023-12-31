/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:26:47 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/30 17:14:39 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**read_map_file(int file)
{
	char	**map;
	char	*joind_str;
	char	*line;
	int		i;

	if (file == -1)
	{
		printf("Error: Can't open file\n");
		return (NULL);
	}
	line = (char *)malloc(2);
	if (!line)
		return (NULL);
	i = 1;
	while (i > 0)
	{
		i = read(file, line, 1);
		if (i == -1)
		{
			free(line);
			return (NULL);
		}
		line[i] = '\0';
		joind_str = ft_strjoin(joind_str, line);
	}
	free(line);
	map = ft_split(joind_str, '\n');
	close(file);
	return (map);
}

int check_end(const char *s, int i, const char *map)
{
    int k = 0;

    while (s[i] != '\n')
	{
        if (s[i] != map[k])
            return 0;
        i++;
        k++;
    }
    if (map[k] == '\0' || map[k] == '\n')
        return 1;
    return 0;
}

int check_space(const char *map, const char *s)
{
    int i = 0;
    int j = 0;
	

    while (s[i])
	{
        if (s[i] == '\n')
		{
            i++;
            while (s[i] == '\n')
                i++;
            j = check_end(s, i, map);
            if (j)
                break;
        }
        i++;
    }
    if (j)
        return i;
    else
        return (-1);
}

int check_space_nd_newline(char **map, char *s)
{
	int i;
	int count;
	int map_size;

	map_size = 0;
	i = check_space(map[6], s);
	count = 0;
	
	while (s[i])
	{
		if (s[i] == '\n')
			count++;
		i++;
	}
	while (map[map_size])
		map_size++;
	if ((map_size - 7) != count)
	{
		printf("Error: Invalid map\n");
		return (1);
	}
	return (0);
}