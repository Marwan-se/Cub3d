/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generate_projection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:56:19 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/22 04:02:04 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_ceiling_floor(cub3d_t *cub, int i, int wallTopPixel, int wallBottomPixel)
{
	int	j;

	j = 0;
	while (j < wallTopPixel)
	{
		mlx_put_pixel(cub->image, i, j, cub->S);
		j++;
	}
	j = wallBottomPixel;
	while (j < WINDOW_HEIGHT)
	{
		mlx_put_pixel(cub->image, i, j, cub->F);
		j++;
	}
}

void	ft_set_offsetX(cub3d_t *cub, int i, int *textureOffSetX)
{
	if (cub->rays[i].wasHitVertical)
	{
		*textureOffSetX = (int) cub->rays[i].wallHitY % TILE_SIZE;
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
		*textureOffSetX = (int) cub->rays[i].wallHitX % TILE_SIZE;
	}
}

void	ft_set_wall_hight(cub3d_t *cub, int *wallStripHight, int i, int *wall_Top_Bottom)
{
		float	DPP;
		float	wallHight;
		int		wallTopPixel;
		int		wallBottomPixel;

		DPP = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		wallHight = TILE_SIZE / (cos(cub->rays[i].rayAngle - cub->p.rotationAngle) * cub->rays[i].distance) * DPP;
		*wallStripHight = (int) wallHight;
		wall_Top_Bottom[0] = WINDOW_HEIGHT / 2 - *wallStripHight / 2;
		wall_Top_Bottom[0] = (wall_Top_Bottom[0] < 0) * 0
								+ !(wall_Top_Bottom[0] < 0) * wall_Top_Bottom[0];
		wall_Top_Bottom[1] = WINDOW_HEIGHT / 2 + *wallStripHight / 2;
		wall_Top_Bottom[1] = (wall_Top_Bottom[1] > WINDOW_HEIGHT) * WINDOW_HEIGHT
								+ !(wall_Top_Bottom[1] > WINDOW_HEIGHT) * wall_Top_Bottom[1];
		if (wallHight > WINDOW_HEIGHT)
			wallHight = WINDOW_HEIGHT;
}

void	ft_generate_projection(cub3d_t *cub, uint32_t tileColor)
{
	int			i;
	int			wall_Top_Bottom[2];
	int			txtrOfSet_XY[2];
	int			w;
	int			wallHight_distncFrmTop[2];

	i = 0;
	while (i < NUM_RAYS)
	{
		ft_set_wall_hight(cub, &wallHight_distncFrmTop[0], i, wall_Top_Bottom);
		ft_set_offsetX(cub, i , &txtrOfSet_XY[0]);
		ft_ceiling_floor(cub, i, wall_Top_Bottom[0], wall_Top_Bottom[1]);
		w = wall_Top_Bottom[0];
		while (w < wall_Top_Bottom[1])
		{
			wallHight_distncFrmTop[1] = w + wallHight_distncFrmTop[0] / 2 - WINDOW_HEIGHT / 2;
			txtrOfSet_XY[1] = wallHight_distncFrmTop[1] * (((float) TEXTURE_HEIGHT) / wallHight_distncFrmTop[0]);
			tileColor = cub->choice[(TEXTURE_WIDTH * txtrOfSet_XY[1]) + txtrOfSet_XY[0] * TEXTURE_WIDTH / TILE_SIZE];
			mlx_put_pixel(cub->image, i, w, tileColor);
			w++;
		}
		i++;
	}
}