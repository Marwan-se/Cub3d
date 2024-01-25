/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:52:25 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 20:11:20 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_DDA(int X0, int Y0, int X1, int Y1, t_cub3d *cub)
{
	int		i;
	float	x;
	float	y;
	int		dx;
	int		dy;
	int		steps;
	float	x_inc;
	float	y_inc;

	i = 0;
	dx = X1 - X0;
	dy = Y1 - Y0;
	steps = (abs(dx) > abs(dy)) * abs(dx) + !(abs(dx) > abs(dy)) * abs(dy);
	x_inc = dx / (float)steps;
	y_inc = dy / (float)steps;
	x = X0;
	y = Y0;
	while (i <= steps)
	{
		mlx_put_pixel(cub->image, round(x) * SACALE_FACTOR, round(y) * SACALE_FACTOR, 0xff0000ff);
		x += x_inc;
		y += y_inc;
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
	info1.facing_down = ray_angle > 0 && ray_angle < M_PI;
	info1.facing_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
	info2.facing_down = info1.facing_down;
	info2.facing_right = info1.facing_right;
	info1.found_wall_hit = FALSE;
	info1.wall_hit_x = 0;
	info1.wall_content = 0;
	info2.found_wall_hit = FALSE;
	info2.wall_hit_x = 0;
	info2.wall_content = 0;
	ft_horizental_intersection(ray_angle, &info1, cub);
	ft_vertical_intersection(ray_angle, &info2, cub);
	ft_choose_smallest_distance(info1, info2, stripId, ray_angle, cub);
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
