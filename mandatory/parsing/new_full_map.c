/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_full_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 23:28:26 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/26 02:27:58 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

void	replace_spaces_with_2(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

void	copy_row(char **rectangle_map, char **map, int i, int max_length)
{
	int	j;

	if (i < 6)
	{
		rectangle_map[i] = (char *)malloc((max_length + 1) * sizeof(char));
		if (rectangle_map[i] == NULL)
			ft_putstr_fd("Error: Malloc failed\n", 2);
		rectangle_map[i][0] = '\0';
		ft_strlcpy2(rectangle_map[i], map[i], max_length + 1);
	}
	else
	{
		rectangle_map[i] = (char *)malloc((max_length + 1) * sizeof(char));
		if (!rectangle_map[i])
			ft_putstr_fd("Error: Malloc failed\n", 2);
		rectangle_map[i][0] = '\0';
		ft_strlcpy2(rectangle_map[i], map[i], max_length + 1);
		j = ft_strlen2(rectangle_map[i]);
		while (j < max_length)
		{
			rectangle_map[i][j] = '2';
			j++;
		}
		rectangle_map[i][max_length] = '\0';
	}
}

int	calculate_max_cols_inmap(char **map)
{
	int	max_length;
	int	i;
	int	length;

	i = 6;
	max_length = 0;
	while (map[i])
	{
		length = ft_strlen2(map[i]);
		if (length > max_length)
			max_length = length;
		i++;
	}
	return (max_length);
}

char	**full_map(char **map, t_cub3d *p)
{
	int		max_length;
	int		i;
	int		rows;
	char	**rectangle_map;

	rows = 0;
	max_length = 0;
	while (map[rows])
		rows++;
	p->map_num_rows = rows - 6;
	max_length = calculate_max_cols_inmap(map);
	p->map_num_cols = max_length;
	rectangle_map = (char **)malloc((rows + 1) * sizeof(char *));
	if (!rectangle_map)
		ft_putstr_fd("Error: Malloc failed\n", 2);
	i = 0;
	while (i < rows)
		copy_row(rectangle_map, map, i++, max_length);
	rectangle_map[rows] = NULL;
	free_2darray(map);
	i = 0;
	p->tmp_map = rectangle_map;
	while (rectangle_map[i] && i < 6)
		free(rectangle_map[i++]);
	return (rectangle_map + 6);
}
