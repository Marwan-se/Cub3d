/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:23 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/16 23:28:48 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void	fd_error(int fd)
{
	if (fd == -1)
	{
		write(2, "Error: File not found\n", 22);
		exit(1);
	}
}

void	map_error(char **map)
{
	if (!map)
	{
		write(2, "Error: Map is empty\n", 20);
		exit(1);
	}
}

void replace_spaces_with_2(char **map)
{
    int i = 0;
    int j = 0;
    int line_count = 0;

    while (map[i])
    {
        if (line_count >= 6)
        {
            j = 0;
            while (map[i][j]) {
                if (map[i][j] == ' ')
                    map[i][j] = '2';
                j++;
            }
        }
        i++;
        line_count++;
    }
}


void    free_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

char **full_map(char** map)
{
    int max_length = 0;
    int i;
    int j;
    int rows;

    rows = 0;
    while (map[rows])
        rows++;
    i = 0;
    while (i < rows)
    {
        int length = ft_strlen(map[i]);
        if (length > max_length)
            max_length = length;
        i++;
    }
    char **rectangle_map = (char**)malloc((rows + 1) * sizeof(char*));
    if(!rectangle_map)
    {
        write(2, "Error: Malloc failed\n", 22);
        exit(1);
    }
    i = 0;
    while (i < rows)
    {
        if (i < 6)
        {
            rectangle_map[i] = (char*)malloc((strlen(map[i]) + 1) * sizeof(char));
            if(!rectangle_map[i])
            {
                write(2, "Error: Malloc failed\n", 22);
                exit(1);
            }
            strcpy(rectangle_map[i], map[i]);
        }
        else
        {
            rectangle_map[i] = (char*)malloc((max_length + 1) * sizeof(char));
            if(!rectangle_map[i])
            {
                write(2, "Error: Malloc failed\n", 22);
                exit(1);
            }
            strcpy(rectangle_map[i], map[i]);
            j = ft_strlen(rectangle_map[i]);
            while (j < max_length)
            {
                rectangle_map[i][j] = '2';
                j++;
            }
            rectangle_map[i][max_length] = '\0';
        }
        i++;
    }
    rectangle_map[rows] = NULL;
    return (rectangle_map);
}


int main(int ac, char **av)
{
	char **map;
	int fd;
    
	check_syntax(av[1], ac);
	fd = open(av[1], O_RDONLY);
	fd_error(fd);
	map = read_map_file(fd);
	map_error(map);
	parsing(map, fd);
	map = full_map(map);
    replace_spaces_with_2(map);
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
    
    
}
