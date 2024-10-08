/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:30:12 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/26 02:03:16 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

void	invalid_map_char(char **map, int i, int j)
{
	if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N' && \
		map[i][j] != 'S' && map[i][j] != 'E' && \
		map[i][j] != 'W' && map[i][j] != ' ' )
		ft_putstr_fd("Error: Invalid map\n", 2);
	if (check_empty_line(map, i))
		ft_putstr_fd("Error: Invalid map\n", 2);
}

void	store_directions(t_Player *p, char c)
{
	p->width = 1;
	p->height = 1;
	p->turn_direction = 0;
	p->walk_direction = 0;
	p->turn_direction2 = 0;
	p->sidewalk_direction = 0;
	p->walk_speed = 250;
	p->turn_speed = 10 * (M_PI / 180);
	if (c == 'N')
		p->rotation_angle = 3 * M_PI / 2;
	else if (c == 'S')
		p->rotation_angle = M_PI / 2;
	else if (c == 'E')
		p->rotation_angle = 0;
	else if (c == 'W')
		p->rotation_angle = M_PI;
}

int	store_player(char **map, int i, t_cub3d *player, char *tmp)
{
	int	counter;
	int	rst;

	rst = 0;
	while (map[i])
	{
		counter = 0;
		while (map[i][counter])
		{
			invalid_map_char(map, i, counter);
			if (map[i][counter] == 'N' || map[i][counter] == 'S' \
				|| map[i][counter] == 'E' || map[i][counter] == 'W')
			{
				*tmp = map[i][counter];
				player->p->y = (i * TL_SZ) + TL_SZ / 2;
				player->p->x = (counter * TL_SZ) + TL_SZ / 2;
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
	if (!player->p)
		ft_putstr_fd("Error: Malloc failed\n", 2);
	if (store_player(map + 6, i, player, tmp) != 1)
		ft_putstr_fd("Error: Invalid map\n", 2);
	return (0);
}

int	map_handling(char **fsl, char **map, int file, t_cub3d *p)
{
	int		i;
	char	tmp;

	(void)file;
	i = 0;
	while (fsl[i] != NULL)
	{
		if (check_fsl(fsl[i], p))
			ft_putstr_fd("Error: Invalid element\n", 2);
		i++;
	}
	if (check_fcc(fsl, p))
		ft_putstr_fd("Error: Invalid RGB\n", 2);
	else if (is_dup(fsl))
		ft_putstr_fd("Error: Duplicate element\n", 2);
	else if (check_player(map, p, &tmp))
		exit(1);
	else if (check_if_map_closed(map, 6, '0', tmp))
		ft_putstr_fd("Error: Map is not closed\n", 2);
	else if (check_if_map_closed(map, 6, tmp, '0'))
		ft_putstr_fd("Error: Map is not closed\n", 2);
	return (0);
}
