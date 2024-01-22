/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:57:49 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/22 04:02:14 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	mapHasWallAt(cub3d_t *cub,float x, float y)
{
	int	mapGridIndexX;
	int	mapGridIndexY; 

	if (x < 0 || x > MAP_NUM_COLS * TILE_SIZE || y < 0 || y > MAP_NUM_ROWS * TILE_SIZE)
		return (TRUE);
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);
	if (mapGridIndexX > MAP_NUM_COLS)
	{
		mapGridIndexX = MAP_NUM_COLS;
	}
	if (mapGridIndexY > MAP_NUM_ROWS)
	{
		mapGridIndexY = MAP_NUM_ROWS;
	}
	return (map[mapGridIndexY][mapGridIndexX] != '0');
}

void	ft_move_player(cub3d_t *cub)
{
	cub->p.rotationAngle += cub->p.turnDirection * cub->p.turnSpeed * 0.2;
	float	moveStep = cub->p.walkDirection * cub->p.walkSpeed * 0.1;
	float	moveStep2 = cub->p.sideWalkDirection * cub->p.walkSpeed / 4 * 0.1;
	float	newPlayerX = cub->p.x + cos(cub->p.rotationAngle) * moveStep * 0.2 + cos(cub->p.rotationAngle + M_PI / 2) * moveStep2;
	float	newPlayerY = cub->p.y + sin(cub->p.rotationAngle) * moveStep * 0.2 + sin(cub->p.rotationAngle + M_PI / 2) * moveStep2;
	if (!mapHasWallAt(cub, newPlayerX, cub->p.y))
	{
		cub->p.x = newPlayerX;
	}
	if (!mapHasWallAt(cub, cub->p.x, newPlayerY))
	{
		cub->p.y = newPlayerY;
	}
}

void	ft_renderPlayer(cub3d_t *cube)
{
	mlx_put_pixel(cube->image, 150-1, 100-1, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150, 100-1, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150+1, 100-1, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150-1, 100, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150, 100, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150+1, 100, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150-1, 100+1, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150, 100+1, 0x0000FFFF);
	mlx_put_pixel(cube->image, 150+1, 100+1, 0x0000FFFF);
	ft_DDA(300, 200, 300 + (float) cos(cube->p.rotationAngle)
		* 40, 200 + sin(cube->p.rotationAngle) * 40, cube);
}

void	ft_set_color(cub3d_t *cub, int startX, int startY, int i)
{
	int		x;
	int		y;
	int		tileColor;
	int		j;

	j = 0;
	while (j < 300)
	{
		x = (startX + j) / TILE_SIZE - 1;
		y = (startY + i) / TILE_SIZE - 1;
		if (x < 0 || y < 0)
			tileColor = ft_pixel(0, 0, 0, 0);
		else if (x < MAP_NUM_COLS && y < MAP_NUM_ROWS && map[y][x] == '0')
			tileColor = 0xFFFFFFFF;
		else if (x < MAP_NUM_COLS && y < MAP_NUM_ROWS && map[y][x] == '1')
			tileColor = 0x808080FF;
		else
			tileColor = ft_pixel(0, 0, 0, 0);
		mlx_put_pixel(cub->image, j , i, tileColor);
		j++;
	}
}

void	ft_renderMap(cub3d_t *cub)
{
	int		i;
	int		j;
	int		tileColor;
	int		startX;
	int		startY;

	1 && (i = 0) && (j = 0) && (tileColor = 0);
	i = 0;
	j = 0;
	startX = cub->p.x - 150 + TILE_SIZE;
	startY = cub->p.y - 100 + TILE_SIZE;
	while(i < 200)
	{
		j = 0;
		ft_set_color(cub, startX, startY, i);
		i++;
	}
}