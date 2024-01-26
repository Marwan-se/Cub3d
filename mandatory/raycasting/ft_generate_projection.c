/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:56:19 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/26 08:06:53 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ceiling_floor(t_cub3d *cub, int i, int wallTopPixel, int wall_bt_pix)
{
	int	j;

	j = 0;
	while (j < wallTopPixel)
	{
		mlx_put_pixel(cub->image, i, j, cub->c);
		j++;
	}
	j = wall_bt_pix;
	while (j < WINDOW_HEIGHT)
	{
		mlx_put_pixel(cub->image, i, j, cub->f);
		j++;
	}
}

void	ft_set_offset_x(t_cub3d *cub, int i, int *textureOffSetX)
{
	if (cub->rays[i].was_hit_vertical)
	{
		*textureOffSetX = (int) cub->rays[i].wall_hit_y % TL_SZ;
		if (cub->rays[i].isfc_rt)
			cub->choice = cub->tab[0];
		else
			cub->choice = cub->tab[1];
	}
	else
	{
		if (!cub->rays[i].isfc_dn)
			cub->choice = cub->tab[2];
		else
			cub->choice = cub->tab[3];
		*textureOffSetX = (int) cub->rays[i].wall_hit_x % TL_SZ;
	}
}

void	ft_wall_hight(t_cub3d *cub, int *wall_s_hight, int i, int *wall_top_btm)
{
	float	dpp;
	float	wall_hight;

	dpp = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	if (cub->rays[i].distance < 0.01)
		cub->rays[i].distance = 1;
	if (cos(cub->rays[i].ray_angle - cub->p->rotation_angle) \
		* cub->rays[i].distance < 0.01)
		wall_hight = TL_SZ / (cub->rays[i].distance) * dpp;
	else
		wall_hight = TL_SZ / (cos(cub->rays[i].ray_angle
					- cub->p->rotation_angle) * cub->rays[i].distance) * dpp;
	if (wall_hight < 0)
		wall_hight = 0;
	*wall_s_hight = (int) wall_hight;
	wall_top_btm[0] = WINDOW_HEIGHT / 2 - *wall_s_hight / 2;
	wall_top_btm[0] = (wall_top_btm[0] < 0) * 0
		+ !(wall_top_btm[0] < 0) * wall_top_btm[0];
	wall_top_btm[1] = WINDOW_HEIGHT / 2 + *wall_s_hight / 2;
	wall_top_btm[1] = (wall_top_btm[1] > WINDOW_HEIGHT) * WINDOW_HEIGHT
		+ !(wall_top_btm[1] > WINDOW_HEIGHT) * wall_top_btm[1];
}

void	ft_generate_projection(t_cub3d *cub, uint32_t tile_color)
{
	int			i;
	int			wall_top_btm[2];
	int			txtrof_set_xy[2];
	int			w;
	int			wll_hght_tp[2];

	i = 0;
	while (i < NUM_RAYS)
	{
		ft_wall_hight(cub, &wll_hght_tp[0], i, wall_top_btm);
		ft_set_offset_x(cub, i, &txtrof_set_xy[0]);
		ft_ceiling_floor(cub, i, wall_top_btm[0], wall_top_btm[1]);
		w = wall_top_btm[0];
		while (w < wall_top_btm[1])
		{
			wll_hght_tp[1] = w + wll_hght_tp[0] / 2 - WINDOW_HEIGHT / 2;
			txtrof_set_xy[1] = wll_hght_tp[1]
				* (((float) TEXTURE_HIGHT) / wll_hght_tp[0]);
			tile_color = cub->choice[(TEXTURE_WIDTH * txtrof_set_xy[1])
				+ txtrof_set_xy[0] * TEXTURE_WIDTH / TL_SZ];
			mlx_put_pixel(cub->image, i, w, tile_color);
			w++;
		}
		i++;
	}
}
