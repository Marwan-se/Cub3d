/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:23 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/14 21:02:00 by msekhsou         ###   ########.fr       */
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

// void replace_spaces_with_2(char **map)
// {
//     int i = 0;
//     int j = 0;
//     int line_count = 0;

//     while (map[i]) {
//         if (line_count >= 6) {
//             j = 0;
//             while (map[i][j]) {
//                 if (map[i][j] == ' ')
//                     map[i][j] = '2';
//                 j++;
//             }
//         }
//         i++;
//         line_count++;
//     }
// }

char** full_map(char** map)
{
    int max_length = 0;
    int i, j;
    int rows;

    // Find the number of rows
    rows = 0;
    while (map[rows])
    {
        rows++;
    }

    // Find the length of the longest line
    for (i = 0; i < rows; i++)
    {
        int length = strlen(map[i]);
        if (length > max_length)
        {
            max_length = length;
        }
    }

    char** rectangle_map = (char**)malloc((rows + 1) * sizeof(char*)); // Increase the size by 1 for the NULL sentinel
    for (i = 0; i < rows; i++)
    {
        if (i < 6) // Skip the first six lines
        {
            rectangle_map[i] = (char*)malloc((strlen(map[i]) + 1) * sizeof(char));
            strcpy(rectangle_map[i], map[i]);
        }
        else
        {
            rectangle_map[i] = (char*)malloc((max_length + 1) * sizeof(char));
            strcpy(rectangle_map[i], map[i]);

            // Replace empty spaces with '2'
            for (j = strlen(rectangle_map[i]); j < max_length; j++)
            {
                rectangle_map[i][j] = '2';
            }
            rectangle_map[i][max_length] = '\0';
        }
    }
    rectangle_map[rows] = NULL; // Add the NULL sentinel
    return rectangle_map;
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
	int i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}
