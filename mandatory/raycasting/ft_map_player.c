/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:57:49 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:18:22 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	map_has_wall_at(t_cub3d *cub, float x, float y)
{
	unsigned int	mapgrid_index_x;
	unsigned int	mapgrid_index_y;

	if (x < 0 || x > cub->map_num_cols * TILE_SIZE || y < 0
		|| y > cub->map_num_rows * TILE_SIZE)
		return (TRUE);
	mapgrid_index_x = floor(x / TILE_SIZE);
	mapgrid_index_y = floor(y / TILE_SIZE);
	if (mapgrid_index_x > cub->map_num_cols)
	{
		mapgrid_index_x = cub->map_num_cols;
	}
	if (mapgrid_index_y > cub->map_num_rows)
	{
		mapgrid_index_y = cub->map_num_rows;
	}
	return (cub->map[mapgrid_index_y][mapgrid_index_x] != '0');
}

void	ft_move_player(t_cub3d *cub)
{
	float	move_step;
	float	move_step2;
	float	new_player_x;
	float	new_player_y;

	cub->p->rotation_angle += cub->p->turn_direction * cub->p->turn_speed * 0.2;
	move_step = cub->p->walk_direction * cub->p->walk_speed * 0.1;
	move_step2 = cub->p->sidewalk_direction * cub->p->walk_speed / 4 * 0.1;
	new_player_x = cub->p->x + cos(cub->p->rotation_angle) * move_step * 0.2
		+ cos(cub->p->rotation_angle + M_PI / 2) * move_step2;
	new_player_y = cub->p->y + sin(cub->p->rotation_angle) * move_step * 0.2
		+ sin(cub->p->rotation_angle + M_PI / 2) * move_step2;
	if (!map_has_wall_at(cub, new_player_x, cub->p->y))
	{
		cub->p->x = new_player_x;
	}
	if (!map_has_wall_at(cub, cub->p->x, new_player_y))
	{
		cub->p->y = new_player_y;
	}
}

void	ft_render_player(t_cub3d *cube)
{
	mlx_put_pixel(cube->image, 149, 99, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150, 99, 0x0000FFFF);
	mlx_put_pixel(cube->image, 151, 99, 0x0000FFFF);
	mlx_put_pixel(cube->image, 149, 100, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150, 100, 0x0000FFFF);
	mlx_put_pixel(cube->image, 151, 100, 0x0000FFFF);
	mlx_put_pixel(cube->image, 149, 101, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150, 101, 0x0000FFFF);
	mlx_put_pixel(cube->image, 151, 101, 0x0000FFFF);
	ft_DDA(300, 200, 300 + (float) cos(cube->p->rotation_angle)
		* 40, 200 + sin(cube->p->rotation_angle) * 40, cube);
}

void	ft_set_color(t_cub3d *cub, int startX, int startY, int i)
{
	unsigned int	x;
	unsigned int	y;
	int				tile_color;
	int				j;

	j = 0;
	while (j < 300)
	{
		x = (startX + j) / TILE_SIZE - 1;
		y = (startY + i) / TILE_SIZE - 1;
		if (x < 0 || y < 0)
			tile_color = ft_pixel(0, 0, 0, 0);
		else if (x < cub->map_num_cols && y < \
			cub->map_num_rows && cub->map[y][x] == '0')
			tile_color = 0xFFFFFFFF;
		else if (x < cub->map_num_cols && y < \
			cub->map_num_rows && cub->map[y][x] == '1')
			tile_color = 0x808080FF;
		else
			tile_color = ft_pixel(0, 0, 0, 0);
		mlx_put_pixel(cub->image, j, i, tile_color);
		j++;
	}
}

void	ft_render_map(t_cub3d *cub)
{
	int		i;
	int		j;
	int		tile_color;
	int		start_x;
	int		start_y;

	1 && (i = 0) && (j = 0) && (tile_color = 0);
	i = 0;
	j = 0;
	start_x = cub->p->x - 150 + TILE_SIZE;
	start_y = cub->p->y - 100 + TILE_SIZE;
	while (i < 200)
	{
		j = 0;
		ft_set_color(cub, start_x, start_y, i);
		i++;
	}
}
