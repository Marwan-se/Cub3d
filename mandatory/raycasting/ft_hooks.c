/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:02:56 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 20:26:16 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_hook(void *param)
{
	t_cub3d	*cub;

	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->p->turn_direction = -1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->p->turn_direction = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		cub->p->walk_direction = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		cub->p->walk_direction = -1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		cub->p->sidewalk_direction = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		cub->p->sidewalk_direction = -1;
}

void	ft_my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub;

	cub = param;
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_W)
			cub->p->walk_direction = 0;
		if (keydata.key == MLX_KEY_S)
			cub->p->walk_direction = 0;
		if (keydata.key == MLX_KEY_LEFT)
			cub->p->turn_direction = 0;
		if (keydata.key == MLX_KEY_RIGHT)
			cub->p->turn_direction = 0;
		if (keydata.key == MLX_KEY_A || (keydata.key == MLX_KEY_D))
		{
			cub->p->sidewalk_direction = 0;
		}
	}
}

// void	ft_renederRays(t_cub3d *cub)
// {
// 	int	i;
// 	int	tile_color;	
// 	i = 0;
// 	// ft_cast_rays(param);
// 	tile_color = ft_pixel(255, 0, 0, 255);
// 	while (i < WINDOW_WIDTH)
// 	{
// 		ft_dda(cub->p->x, cub->p->y, cub->rays[i].wallHit_x, 
// cub->rays[i].wall_hit_y, cub);
// 		i++;
// 	}
// }