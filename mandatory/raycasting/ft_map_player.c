/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:57:49 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 04:19:46 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	mapHasWallAt(t_cub3d *cub,float x, float y)
{
	unsigned int	mapGridIndexX;
	unsigned int	mapGridIndexY; 

	if (x < 0 || x > cub->MAP_NUM_COLS * TILE_SIZE || y < 0 || y > cub->MAP_NUM_ROWS * TILE_SIZE)
		return (TRUE);
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);
	if (mapGridIndexX > cub->MAP_NUM_COLS)
	{
		mapGridIndexX = cub->MAP_NUM_COLS;
	}
	if (mapGridIndexY > cub->MAP_NUM_ROWS)
	{
		mapGridIndexY = cub->MAP_NUM_ROWS;
	}
	// printf("%d, %d\n", mapGridIndexX, mapGridIndexY);
 	return (cub->map[mapGridIndexY][mapGridIndexX] != '0');
}

void	ft_move_player(t_cub3d *cub)
{
	cub->p->rotationAngle += cub->p->turnDirection * cub->p->turnSpeed * 0.2;
	float	moveStep = cub->p->walkDirection * cub->p->walkSpeed * 0.1;
	float	moveStep2 = cub->p->sideWalkDirection * cub->p->walkSpeed / 4 * 0.1;
	float	newPlayerX = cub->p->x + cos(cub->p->rotationAngle) * moveStep * 0.2 + cos(cub->p->rotationAngle + M_PI / 2) * moveStep2;
	float	newPlayerY = cub->p->y + sin(cub->p->rotationAngle) * moveStep * 0.2 + sin(cub->p->rotationAngle + M_PI / 2) * moveStep2;
	
	if (!mapHasWallAt(cub, newPlayerX, cub->p->y))
	{
		cub->p->x = newPlayerX;
	}
	if (!mapHasWallAt(cub, cub->p->x, newPlayerY))
	{
		cub->p->y = newPlayerY;
	}
}

void	ft_renderPlayer(t_cub3d *cube)
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
	ft_DDA(300, 200, 300 + (float) cos(cube->p->rotationAngle)
		* 40, 200 + sin(cube->p->rotationAngle) * 40, cube);
}

void	ft_set_color(t_cub3d *cub, int startX, int startY, int i)
{
	unsigned int		x;
	unsigned int		y;
	int		tileColor;
	int		j;

	j = 0;
	while (j < 300)
	{
		x = (startX + j) / TILE_SIZE - 1;
		y = (startY + i) / TILE_SIZE - 1;
		if (x < 0 || y < 0)
			tileColor = ft_pixel(0, 0, 0, 0);
		else if (x < cub->MAP_NUM_COLS && y < cub->MAP_NUM_ROWS && cub->map[y][x] == '0')
			tileColor = 0xFFFFFFFF;
		else if (x < cub->MAP_NUM_COLS && y < cub->MAP_NUM_ROWS && cub->map[y][x] == '1')
			tileColor = 0x808080FF;
		else
			tileColor = ft_pixel(0, 0, 0, 0);
		mlx_put_pixel(cub->image, j , i, tileColor);
		j++;
	}
}

void	ft_renderMap(t_cub3d *cub)
{
	int		i;
	int		j;
	int		tileColor;
	int		startX;
	int		startY;

	1 && (i = 0) && (j = 0) && (tileColor = 0);
	i = 0;
	j = 0;
	startX = cub->p->x - 150 + TILE_SIZE;
	startY = cub->p->y - 100 + TILE_SIZE;
	while(i < 200)
	{
		j = 0;
		ft_set_color(cub, startX, startY, i);
		i++;
	}
}