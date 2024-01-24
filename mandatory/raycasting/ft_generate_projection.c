/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:56:19 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 06:27:28 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ceiling_floor(t_cub3d *cub, int i, int wallTopPixel, int wall_bt_pix)
{
	int	j;

	j = 0;
	while (j < wallTopPixel)
	{
		mlx_put_pixel(cub->image, i, j, cub->C);
		j++;
	}
	j = wall_bt_pix;
	while (j < WINDOW_HEIGHT)
	{
		mlx_put_pixel(cub->image, i, j, cub->F);
		j++;
	}
}

void	ft_set_offset_x(t_cub3d *cub, int i, int *textureOffSetX)
{
	if (cub->rays[i].wasHitVertical)
	{
		*textureOffSetX = (int) cub->rays[i].wallHitY % tile_size;
		if (cub->rays[i].isFacingRight)
			cub->choice = cub->tab[0];
		else
			cub->choice = cub->tab[1];
	}
	else
	{
		if (cub->rays[i].isFacingUp)
			cub->choice = cub->tab[2];
		else
			cub->choice = cub->tab[3];
		*textureOffSetX = (int) cub->rays[i].wallHitX % tile_size;
	}
}

void	ft_wall_hight(t_cub3d *cub, int *wall_s_hight, int i, int *wall_top_btm)
{
	float	dpp;
	float	wall_hight;

	dpp = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	wall_hight = tile_size / (cos(cub->rays[i].rayAngle
				- cub->p->rotation_angle) * cub->rays[i].distance) * dpp;
	*wall_s_hight = (int) wall_hight;
	wall_top_btm[0] = WINDOW_HEIGHT / 2 - *wall_s_hight / 2;
	wall_top_btm[0] = (wall_top_btm[0] < 0) * 0
		+ !(wall_top_btm[0] < 0) * wall_top_btm[0];
	wall_top_btm[1] = WINDOW_HEIGHT / 2 + *wall_s_hight / 2;
	wall_top_btm[1] = (wall_top_btm[1] > WINDOW_HEIGHT) * WINDOW_HEIGHT
		+ !(wall_top_btm[1] > WINDOW_HEIGHT) * wall_top_btm[1];
	if (wall_hight > WINDOW_HEIGHT)
		wall_hight = WINDOW_HEIGHT;
}

void	ft_generate_projection(t_cub3d *cub, uint32_t tile_color)
{
	int			i;
	int			wall_top_btm[2];
	int			txtrof_set_xy[2];
	int			w;
	int			wall_hight_distnc_top[2];

	i = 0;
	while (i < NUM_RAYS)
	{
		ft_wall_hight(cub, &wall_hight_distnc_top[0], i, wall_top_btm);
		ft_set_offset_x(cub, i, &txtrof_set_xy[0]);
		ft_ceiling_floor(cub, i, wall_top_btm[0], wall_top_btm[1]);
		w = wall_top_btm[0];
		while (w < wall_top_btm[1])
		{
			wall_hight_distnc_top[1] = w + wall_hight_distnc_top[0] / 2
				- WINDOW_HEIGHT / 2;
			txtrof_set_xy[1] = wall_hight_distnc_top[1]
				* (((float) texture_hight) / wall_hight_distnc_top[0]);
			tile_color = cub->choice[(texture_width * txtrof_set_xy[1])
				+ txtrof_set_xy[0] * texture_width / tile_size];
			mlx_put_pixel(cub->image, i, w, tile_color);
			w++;
		}
		i++;
	}
}
