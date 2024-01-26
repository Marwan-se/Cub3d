/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:50:29 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/26 08:11:54 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_points_dist(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void	ft_choose_small_dist(t_info info1, t_info info2, int id, t_cub3d *cub)
{
	float	horiz_distance;
	float	vert_distance;

	vert_distance = info2.fnd_wl_hit * ft_points_dist(cub->p->x, cub->p->y, \
		info2.wall_hit_x, info2.wall_hit_y) + !info2.fnd_wl_hit * INT_MAX;
	horiz_distance = info1.fnd_wl_hit * ft_points_dist(cub->p->x, cub->p->y, \
			info1.wall_hit_x, info1.wall_hit_y) + !info1.fnd_wl_hit * INT_MAX;
	if (vert_distance < horiz_distance)
	{
		cub->rays[id].distance = vert_distance;
		cub->rays[id].wall_hit_x = info2.wall_hit_x;
		cub->rays[id].wall_hit_y = info2.wall_hit_y;
		cub->rays[id].wall_hit_content = info2.wall_data;
		cub->rays[id].was_hit_vertical = 1;
	}
	else
	{
		cub->rays[id].distance = horiz_distance;
		cub->rays[id].wall_hit_x = info1.wall_hit_x;
		cub->rays[id].wall_hit_y = info1.wall_hit_y;
		cub->rays[id].wall_hit_content = info1.wall_data;
		cub->rays[id].was_hit_vertical = 0;
	}
	if (cub->rays[id].distance < 0.01)
		cub->rays[id].distance = 1;
	cub->rays[id].isfc_dn = info1.fc_dn;
	cub->rays[id].isfc_rt = info1.fc_rt;
}

void	ft_horizental_intersection(float ray_angle, t_info *info1, t_cub3d *cub)
{
	float xtep, y_step, \
		y_to_check;
	info1->next_y = floor(cub->p->y / TL_SZ) * TL_SZ;
	info1->next_y += info1->fc_dn * TL_SZ;
	info1->next_x = cub->p->x + (info1->next_y - cub->p->y) / tan(ray_angle);
	1 && (xtep = TL_SZ / tan(ray_angle)) && (y_step = TL_SZ) \
		&& (y_step *= !info1->fc_dn * -1 + (info1->fc_dn * 1));
	xtep *= (!info1->fc_rt && xtep > 0) * -1 + !(!info1->fc_rt && xtep > 0) * 1;
	xtep *= (info1->fc_rt && xtep < 0) * -1 + !(info1->fc_rt && xtep < 0) * 1;
	while (info1->next_x >= 0 && info1->next_x < cub->map_num_cols * TL_SZ \
		&& info1->next_y >= 0 && info1->next_y < cub->map_num_rows * TL_SZ)
	{
		y_to_check = info1->next_y + !info1->fc_dn * -1;
		if (map_has_wall_at(cub, info1->next_x, y_to_check))
		{
			1 && (info1->wall_hit_x = info1->next_x) && \
				(info1->wall_hit_y = info1->next_y);
			info1->wall_data = (cub->map[(int)floor(y_to_check / TL_SZ)] \
					[(int)floor(info1->next_x / TL_SZ)] != '0');
			info1->fnd_wl_hit = TRUE;
			break ;
		}
		else
			1 && (info1->next_x += xtep) && (info1->next_y += y_step);
	}
}

void	ft_vertical_intersect(float ray_angle, t_info *info2, t_cub3d *cub)
{
	float xtep, y_stp, \
		x_to_check;
	info2->next_x = (int)(cub->p->x / TL_SZ) * TL_SZ + info2->fc_rt * TL_SZ;
	info2->next_y = cub->p->y + (info2->next_x - cub->p->x) * tan(ray_angle);
	1 && (xtep = TL_SZ) && (xtep *= !info2->fc_rt * -1 + info2->fc_rt * 1);
	y_stp = TL_SZ * tan(ray_angle);
	y_stp *= (!info2->fc_dn && y_stp > 0) * -1 \
	+ !(!info2->fc_dn && y_stp > 0) * 1;
	y_stp *= (info2->fc_dn && y_stp < 0) * -1 \
		+ !(info2->fc_dn && y_stp < 0) * 1;
	while (info2->next_x >= 0 && info2->next_x < cub->map_num_cols * TL_SZ \
		&& info2->next_y >= 0 && info2->next_y < cub->map_num_rows * TL_SZ)
	{
		x_to_check = info2->next_x + !info2->fc_rt * -1;
		if (map_has_wall_at(cub, x_to_check, info2->next_y))
		{
			1 && (info2->wall_hit_x = info2->next_x) && \
			(info2->fnd_wl_hit = TRUE) && (info2->wall_hit_y = info2->next_y);
			info2->wall_data = (cub->map[(int)floor(info2->next_y / TL_SZ)] \
				[(int)floor(x_to_check / TL_SZ)] != '0');
			break ;
		}
		else
			1 && (info2->next_x += xtep) && (info2->next_y += y_stp);
	}
}
