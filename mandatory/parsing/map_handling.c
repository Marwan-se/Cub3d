/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:30:12 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/24 04:15:03 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	invalid_map_char(char **map, int i, int j)
{
	if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N' && \
		map[i][j] != 'S' && map[i][j] != 'E' && \
		map[i][j] != 'W' && map[i][j] != ' ' )
		return (1);
	if (check_empty_line(map, i))
		return (1);
	return (0);
}

void	store_directions(t_Player *p, char c)
{
	if (c == 'N')
		p->rotationAngle = 3 * M_PI / 2;
	else if (c == 'S')
		p->rotationAngle = M_PI / 2;
	else if (c == 'E')
		p->rotationAngle = 0;
	else if (c == 'W')
		p->rotationAngle = M_PI;
}

int	store_player(char **map, int i, t_cub3d *player, char *tmp)
{
	int counter;
	int rst;

	rst = 0;

	while (map[i])
	{
		counter = 0;
		while(map[i][counter])
			{
				if(invalid_map_char(map, i, counter) )
					ft_putstr_fd("Error: Invalid map\n", 2);
				if (map[i][counter] == 'N' || map[i][counter] == 'S' \
					|| map[i][counter] == 'E' || map[i][counter] == 'W')
				{
					*tmp = map[i][counter];
					player->p->y = (i * TILE_SIZE) + TILE_SIZE / 2;
					player->p->x = (counter * TILE_SIZE) + TILE_SIZE / 2;
					// player->p->y = i;
					// player->p->x = counter;
					store_directions(player->p, map[i][counter]);
					map[i][counter] = '0';
					rst++;
				}
				counter++;
			}
		i++;
	}
	return (rst);
}

int	check_player(char **map, t_cub3d *player, char *tmp)
{
	int	i;
	
	i = 0;
	player->p = malloc(sizeof(t_Player));
	if(!player->p)
		ft_putstr_fd("Error: Malloc failed\n", 2);
	if (store_player(map+6, i, player, tmp) != 1)
		ft_putstr_fd("Error: Invalid map\n", 2);
	return (0);
}

int map_handling(char **fsl, char **map, int file, t_cub3d *p)
{
	int i;
	(void)file;
	char tmp;

	i = 0;
	while (fsl[i] != NULL)
	{
		if(check_fsl(fsl[i] , p))
			ft_putstr_fd("Error: Invalid element\n", 2);
		i++;
	}
	if (check_fcc(fsl, p))
		ft_putstr_fd("Error: Invalid RGB\n", 2);
	else if(duplicate_elemnts_checker(fsl))
		ft_putstr_fd("Error: Duplicate element\n", 2);
	else if(check_player(map, p, &tmp))
		exit(1);
	else if (check_if_map_closed(map, 5, '0', tmp))
		ft_putstr_fd("Error: Map is not closed\n", 2);
	else if (check_if_map_closed(map, 5, tmp, '0'))
		ft_putstr_fd("Error: Map is not closed\n", 2);
	return(0);
}	
