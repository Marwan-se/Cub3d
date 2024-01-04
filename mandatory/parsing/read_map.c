/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:26:47 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/04 21:06:14 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int validate_map(char **map, char *s)
{
    int i = 0;
    int count = 0;
    int map_size = 0;
    int pattern_found = 0;
    int k = 0;
    char *ptr;

    while (s[i])
	{
        if (s[i] == '\n')
		{
            i++;
            while (s[i] == '\n')
                i++;
            ptr = malloc(sizeof(char) * 2);
            if (!ptr)
            {
                write(2, "Error: Malloc failed\n", 22);
                exit(1);
            }
            while (s[i] != '\n')
                ptr[k++] = s[i++];
            ptr[k] = '\0';

            if (ft_strncmp(ptr, map[6], ft_strlen(ptr)) == 0)
			{
                pattern_found = 1;
                free(ptr);
                break ;
            }
            free(ptr);
        }
        i++;
    }
    if (!pattern_found)
        return -1;
    while (s[i])
	{
        if (s[i] == '\n')
            count++;
        i++;
    }
    while (map[map_size])
        map_size++;
    if ((map_size - 6 - 1) != count)
		return 1;
    return 0;
}
char *read_file_contents(int file)
{
    char *joind_str;
    char *line;
    int i;

    line = (char *)malloc(sizeof(char) * 2);
    if (!line)
    {
        write(2, "Error: Malloc failed\n", 22);
        exit(1);
    }
    joind_str = NULL;
    i = 1;
    while (i > 0)
	{
        i = read(file, line, 1);
        if (i == -1)
		{
            free(line);
            return NULL;
        }
        line[i] = '\0';
        joind_str = ft_strjoin(joind_str, line);
    }
    free(line);
    return (joind_str);
}

char **read_map_file(int file)
{
    char **map;
    char *joind_str;

    if (file == -1)
	{
        write(2, "Error: File not found\n", 22);
        return NULL;
    }
    joind_str = read_file_contents(file);
    if (!joind_str)
        return NULL;
    map = ft_split(joind_str, '\n');
	if(validate_map(map, joind_str))
	{
		write(2, "Error: Invalid map\n", 19);
		exit(1);
	}
    free(joind_str);
    close(file);
    return map;
}
