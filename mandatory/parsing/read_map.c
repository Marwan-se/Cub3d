/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:26:47 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/23 02:59:16 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_map_lines(char *line, int i, char *map)
{
    int map_len = ft_strlen(map);
    int j = 0;
    
    while (line[i] != '\n')
    {
        if (line[i] != map[j])
            return 0;
        i++;
        j++;
    }
    return (j == map_len);
}

int find_newline(char *map, char *line)
{
    int i = 0;
    int string_len = ft_strlen(line);
    
    while (i < string_len)
    {
        if (line[i] == '\n')
        {
            i++;
            while (line[i] == '\n')
                i++;
            if (check_map_lines(line, i, map))
                break ;
        }
        i++;
    }
    return i;
}

int check_empty_newline(char **map, char *line)
{
    int i;
    char **map_ptr;
    int map_count;
    int char_count;

    map_ptr = map;
    char_count = 0;
    map_count = 0;
    i = find_newline(map_ptr[6], line);
    while (line[i])
    {
        if (line[i] == '\n')
            char_count++;
        i++;
    }
    while (*map_ptr)
    {
        map_count++;
        map_ptr++;
    }
    if (map_count - 7 != char_count)
        return 1;
    return 0;
}


char    **read_map_file(int file)
{
    char **map;
    char *joind_str;
    char *line;
    int i;

    line = (char *)malloc(sizeof(char) * 2);
    if (!line)
        ft_putstr_fd("Error: Malloc failed\n", 2);
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
    map = ft_split(joind_str, '\n');
    if (check_empty_newline(map, joind_str))
    {
        free(joind_str);
        ft_putstr_fd("Error: Empty line in map\n", 2);
    }
    free(joind_str);
    close(file);
    return map;
}
