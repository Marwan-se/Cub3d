/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_full_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 04:15:58 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 02:12:38 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void replace_spaces_with_2(char **map)
{
    int i = 0;
    int j = 0;

    while (map[i])
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

int get_max_length(char **map)
{
    int max_length = 0;
    int rows = 0;

    while (map[rows])
        rows++;

    int i = 0;
    while (i < rows)
    {
        int length = ft_strlen(map[i]);
        if (length > max_length)
            max_length = length;
        i++;
    }

    return max_length;
}

void copy_row(char **rectangle_map, char **map, int i, int max_length)
{
    int j;

    if (i < 6)
	{
        rectangle_map[i] = (char*)malloc((ft_strlen(map[i]) + 1) * sizeof(char));
        if (!rectangle_map[i])
            ft_putstr_fd("Error: Malloc failed\n", 2);
        ft_strlcpy(rectangle_map[i], map[i], max_length + 1);
    }
    else
	{
        rectangle_map[i] = (char*)malloc((max_length + 1) * sizeof(char));
        if (!rectangle_map[i])
            ft_putstr_fd("Error: Malloc failed\n", 2);
        strcpy(rectangle_map[i], map[i]);
        j = ft_strlen(rectangle_map[i]);
        while (j < max_length)
		{
            rectangle_map[i][j] = '2';
            j++;
        }
        rectangle_map[i][max_length] = '\0';
    }
}

int calculate_max_length(char **map)
{
    int max_length;
    int i;
	int	length;

	i = 6;
	max_length = 0;
    while (map[i])
	{
        length = ft_strlen(map[i]);
        if (length > max_length)
            max_length = length;
        i++;
    }
    return (max_length);
}

void    full_map(t_cub3d *cub, char **map)
{
    int max_length;
    int i;
    int rows;
	// char **rectangle_map;


    rows = 0;
	max_length = 0;
    while (map[rows])
        rows++;
    rows -= 6;
    printf("rows %d \n", rows);
    i = 0;
	max_length = calculate_max_length(map);
    printf("max_length %d \n", max_length);
    cub->map = (char **)malloc((rows + 1) * sizeof(char*));
    if(!cub->map)
        ft_putstr_fd("Error: Malloc failed\n", 2);
    i = 0;
    while (i < rows)
    {
        copy_row(cub->map, map, i, max_length);
        i++;
    }
    cub->map[rows] = NULL;
    cub->map = cub->map;
    // printf("test %c",cub->map[0][0]);
    for(int z = 0; z < 2;z++)
	{
		for(int k = 0; k < 2;k++)
		{
			printf("%c",cub->map[z][k]);
		}
		printf("\n");
	}
}