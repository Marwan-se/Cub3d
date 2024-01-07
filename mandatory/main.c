/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:23 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/07 06:25:07 by msekhsou         ###   ########.fr       */
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


void replace_spaces(char **map) {
    int mapStartIndex = -1;

    // Find the starting index of the map
    for (int i = 0; map[i] != NULL; i++) {
        if (strstr(map[i], "11") != NULL) {
            mapStartIndex = i;
            break;
        }
    }

    if (mapStartIndex != -1) {
        // Replace spaces in the map rows
        for (int i = mapStartIndex; map[i] != NULL; i++) {
            int len = strlen(map[i]);
            for (int j = 0; j < len; j++) {
                if (map[i][j] == ' ') {
                    map[i][j] = '2';
                }
            }
        }
    }
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
	// replace_spaces(map);
	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
