/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 03:02:56 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/23 17:45:44 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_hook(void* param)
{
	t_cub3d	*cub;
	
	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->p->turnDirection = -1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->p->turnDirection = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		cub->p->walkDirection = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		cub->p->walkDirection = -1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		cub->p->sideWalkDirection = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		cub->p->sideWalkDirection = -1;
}

void ft_my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_cub3d	*cub;

	cub = param;
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_W)
			cub->p->walkDirection = 0;
		if (keydata.key == MLX_KEY_S)
			cub->p->walkDirection = 0;
		if (keydata.key == MLX_KEY_LEFT)
			cub->p->turnDirection = 0;
		if (keydata.key == MLX_KEY_RIGHT)
			cub->p->turnDirection = 0;
		if (keydata.key == MLX_KEY_A || (keydata.key == MLX_KEY_D))
		{
			cub->p->sideWalkDirection = 0;
		}
	}
}

// void	ft_renederRays(cub3d_t *cub)
// {
// 	int	i;
// 	int	tileColor;
	
// 	i = 0;
// 	// ft_cast_rays(param);
// 	tileColor = ft_pixel(255, 0, 0, 255);
// 	while (i < WINDOW_WIDTH)
// 	{
// 		ft_DDA(cub->p.x, cub->p.y, cub->rays[i].wallHitX, cub->rays[i].wallHitY, cub);
// 		i++;
// 	}
// }