/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:23 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/11 06:25:06 by msekhsou         ###   ########.fr       */
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

    while (map[i]) {
        if (line_count >= 6) {
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
	replace_spaces_with_2(map);
	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
