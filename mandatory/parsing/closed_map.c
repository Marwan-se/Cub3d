/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closed_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:49:19 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/26 02:23:23 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

void	check_limits(char **map, int i, int k)
{
	int	j;

	j = 0;
	(void)i;
	while (map[6][j] != '\0')
	{
		if ((map[6][j] != '1' && map[6][j] != ' '))
		{
			write(2, "Error: Map is not closed\n", 25);
			exit(1);
		}
		j++;
	}
	j = 0;
	while (map[k - 1][j])
	{
		if ((map[k - 1][j] != '1' && map[k - 1][j] != ' '))
		{
			write(2, "Error: Map is not closed\n", 25);
			exit(1);
		}
		j++;
	}
}

int	is_surrounded(char **map, int i, int j, char plyr)
{
	int	len;

	len = 0;
	while (map[len])
		len++;
	if (map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != plyr)
		return (1);
	if (map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != plyr)
		return (1);
	if (i + 1 != len - 1 && map[i + 1][j] != '1' &&
		map[i + 1][j] != '0' && map[i + 1][j] != plyr)
		return (1);
	if (map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i - 1][j] != plyr)
		return (1);
	return (0);
}

int	check_if_map_closed(char **map, int i, char c, char p)
{
	int	counter;
	int	j;

	counter = 0;
	while (map[counter])
		counter++;
	check_limits(map, i, counter);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == c && i != 6 && i != counter - 1)
			{
				if (is_surrounded(map, i, j, p))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
