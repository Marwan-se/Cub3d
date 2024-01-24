/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_full_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:28:26 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/24 05:01:29 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

void replace_spaces_with_2(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i] != NULL)
    {
            j = 0;
            while (map[i][j])
			{
                if (map[i][j] == ' ')
                    map[i][j] = '2';
                j++;
            }
        i++;
    }
}


void copy_row(char **rectangle_map, char **map, int i, int max_length)
{
    int j;

    if (i < 6)
	{
        rectangle_map[i] = (char*)malloc((max_length + 1) * sizeof(char));
        if (!rectangle_map[i])
            ft_putstr_fd("Error: Malloc failed\n", 2);
        ft_strlcpy2(rectangle_map[i], map[i], max_length + 1);
    }
    else
	{
        rectangle_map[i] = (char*)malloc((max_length + 1) * sizeof(char));
        if (!rectangle_map[i])
            ft_putstr_fd("Error: Malloc failed\n", 2);
        strcpy(rectangle_map[i], map[i]);
        j = ft_strlen2(rectangle_map[i]);
        while (j < max_length)
		{
            rectangle_map[i][j] = '2';
            j++;
        }
        rectangle_map[i][max_length] = '\0';
    }
}

int calculate_max_cols_inmap(char **map)
{
    int max_length;
    int i;
    int length;

    i = 6;
    max_length = 0;
    while (map[i])
    {
        length = ft_strlen2(map[i]);
        if (length > max_length)
            max_length = length;
        i++;
    }
    return max_length;
}

char **full_map(char **map, t_cub3d *cub)
{
    int max_length;
    int i;
    int rows;
	char **rectangle_map;


    rows = 0;
	max_length = 0;
    while (map[rows])
        rows++;
    cub->map_num_rows = rows - 6;
    i = 0;
    max_length = calculate_max_cols_inmap(map);
    cub->map_num_cols = max_length;
    rectangle_map = (char**)malloc((rows + 1) * sizeof(char*));
    if(!rectangle_map)
        ft_putstr_fd("Error: Malloc failed\n", 2);
    i = 0;
    while (i < rows)
    {
        copy_row(rectangle_map, map, i, max_length);
        i++;
    }
    rectangle_map[rows] = NULL;
    return (rectangle_map + 6);
}
