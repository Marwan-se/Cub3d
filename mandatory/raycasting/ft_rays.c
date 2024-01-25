/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:52:25 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/25 06:27:32 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_dda(int *Tx, int *Ty, t_cub3d *cub)
{
	float	x;
	float	y;
	int		steps;
	int		i;

	i = 0;
	steps = (abs(Tx[1] - Tx[0]) > abs(Ty[1] - Ty[0])) * abs(Tx[1] - Tx[0])
		+ !(abs(Tx[1] - Tx[0]) > abs(Ty[1] - Ty[0])) * abs(Ty[1] - Ty[0]);
	x = Tx[0];
	y = Ty[0];
	while (i <= steps)
	{
		mlx_put_pixel(cub->image, round(x) * SACALE_FACTOR, round(y)
			* SACALE_FACTOR, 0xff0000ff);
		x += (Tx[1] - Tx[0]) / (float)steps;
		y += (Ty[1] - Ty[0]) / (float)steps;
		i++;
	}
}

float	ft_normalize_angle(float angle)
{
	angle = remainder(angle, 2 * M_PI);
	if (angle < 0)
	{
		angle = 2 * M_PI + angle;
	}
	return (angle);
}

void	ft_cast_ray(float ray_angle, int stripId, t_cub3d *cub)
{
	t_info	info1;
	t_info	info2;

	ray_angle = ft_normalize_angle(ray_angle);
	info1.fc_dn = ray_angle > 0 && ray_angle < M_PI;
	info1.fc_rt = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
	info2.fc_dn = info1.fc_dn;
	info2.fc_rt = info1.fc_rt;
	info1.fnd_wl_hit = FALSE;
	info1.wall_hit_x = 0;
	info1.wall_data = 0;
	info2.fnd_wl_hit = FALSE;
	info2.wall_hit_x = 0;
	info2.wall_data = 0;
	cub->rays[stripId].ray_angle = ray_angle;
	ft_horizental_intersection(ray_angle, &info1, cub);
	ft_vertical_intersect(ray_angle, &info2, cub);
	ft_choose_small_dist(info1, info2, stripId, cub);
}

void	ft_cast_rays(t_cub3d *cub)
{
	float	ray_angle;
	int		id;
	float	dpp;

	id = 0;
	dpp = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (id < NUM_RAYS)
	{
		ray_angle = cub->p->rotation_angle + atan((id - NUM_RAYS / 2) / dpp);
		ft_cast_ray(ray_angle, id, cub);
		id++;
	}
}
