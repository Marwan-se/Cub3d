/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:50:29 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/25 02:32:54 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_points_distance(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
//------------- Choose the smallest one: horizental || vertical ----------//

void	ft_choose_smallest_distance(t_info info1, t_info info2, int id, float ray_angle, t_cub3d *cub)
{
	float	horiz_distance;
	float	vert_distance;

	vert_distance = info2.found_wall_hit \
		* ft_points_distance(cub->p->x, cub->p->y, \
		info2.wall_hit_x, info2.wall_hit_y) + !info2.found_wall_hit * INT_MAX;
	horiz_distance = info1.found_wall_hit \
		* ft_points_distance(cub->p->x, cub->p->y,
			info1.wall_hit_x, info1.wall_hit_y) + !info1.found_wall_hit * INT_MAX;
	if (vert_distance < horiz_distance)
	{
		cub->rays[id].distance = vert_distance;
		cub->rays[id].wall_hit_x = info2.wall_hit_x;
		cub->rays[id].wall_hit_y = info2.wall_hit_y;
		cub->rays[id].wall_hit_content = info2.wall_content;
		cub->rays[id].was_hit_vertical = 1;
	}
	else
	{
		cub->rays[id].distance = horiz_distance;
		cub->rays[id].wall_hit_x = info1.wall_hit_x;
		cub->rays[id].wall_hit_y = info1.wall_hit_y;
		cub->rays[id].wall_hit_content = info1.wall_content;
		cub->rays[id].was_hit_vertical = 0;
	}
	cub->rays[id].ray_angle = ray_angle;
	cub->rays[id].is_facing_up = !info1.facing_down;
	cub->rays[id].isfacing_down = info1.facing_down;
	cub->rays[id].isfacing_left = !info1.facing_right;
	cub->rays[id].isfacing_right = info1.facing_right;
}

//----------------Horizental intersection code -------------------

void	ft_horizental_intersection(float ray_angle, t_info *info1, t_cub3d *cub)
{
	float	xstep;
	float	y_step;
	float	y_to_check;

	// Find the y-coordinate of the closest horizontal grid intersection
	info1->next_y = floor(cub->p->y / TILE_SIZE) * TILE_SIZE;
	info1->next_y += info1->facing_down * TILE_SIZE + !info1->facing_down * 0;
	// Find the x-coordinate of the closest horizontal grid intersection
	info1->next_x = cub->p->x + (info1->next_y - cub->p->y) / tan(ray_angle);
	// Calculate the increment xstep and y_step
	1 && (y_step = TILE_SIZE) && (y_step *= !info1->facing_down * -1 + (info1->facing_down * 1));
	xstep = TILE_SIZE / tan(ray_angle);
	xstep *= (!info1->facing_right && xstep > 0) * -1 + !(!info1->facing_right && xstep > 0) * 1;
	xstep *= (info1->facing_right && xstep < 0) * -1 + !(info1->facing_right && xstep < 0) * 1;
	while (info1->next_x >= 0 && info1->next_x <= cub->map_num_cols * TILE_SIZE && info1->next_y >= 0 && info1->next_y <= cub->map_num_rows * TILE_SIZE)// Increment xstep and y_step until we find a wall
	{
		y_to_check = info1->next_y + !info1->facing_down * -1;
		if (map_has_wall_at(cub, info1->next_x, y_to_check))// found a wall hit
		{
			1 && (info1->wall_hit_x = info1->next_x) && (info1->wall_hit_y = info1->next_y);
            info1->wall_content = (cub->map[(int)floor(y_to_check / TILE_SIZE)][(int)floor(info1->next_x/ TILE_SIZE)] != '0');
           	info1->found_wall_hit = TRUE;
            break;
        }
		else
            1 && (info1->next_x += xstep) && (info1->next_y += y_step);
	}
}
//------------------------------------Vertical intersection code --------------------------------------------
void	ft_vertical_intersection(float ray_angle, t_info *info2, t_cub3d *cub)
{
	float	xstep;
	float	y_step;
	float	x_to_check;

	info2->next_x = floor(cub->p->x / TILE_SIZE) * TILE_SIZE;// Find the x-coordinate of the closest horizontal grid intersection
	info2->next_x += info2->facing_right * TILE_SIZE + !info2->facing_right * 0;
	info2->next_y = cub->p->y + (info2->next_x - cub->p->x) * tan(ray_angle);// Find the y-coordinate of the closest horizontal grid intersection
	1 && (xstep = TILE_SIZE) && (xstep *= !info2->facing_right * -1 + info2->facing_right * 1);
	y_step = TILE_SIZE * tan(ray_angle);
	y_step *= (!info2->facing_down && y_step > 0) * -1 + !(!info2->facing_down && y_step > 0) * 1;
	y_step *= (info2->facing_down && y_step < 0) * -1 + !(info2->facing_down && y_step < 0) * 1;
	while (info2->next_x >= 0 && info2->next_x < cub->map_num_cols * TILE_SIZE && info2->next_y >= 0 && info2->next_y < cub->map_num_rows * TILE_SIZE)// Increment xstep and y_step until we find a wall
	{
		x_to_check = info2->next_x + !info2->facing_right * -1;
		if (map_has_wall_at(cub, x_to_check, info2->next_y))
		{
			1 && (info2->wall_hit_x = info2->next_x) && (info2->wall_hit_y = info2->next_y);
			info2->wall_content = (cub->map[(int)floor(info2->next_y / TILE_SIZE)][(int)floor(x_to_check / TILE_SIZE)] != '0');
			info2->found_wall_hit = TRUE;
			break ;
		} 
		else
			1 && (info2->next_x += xstep) && (info2->next_y += y_step);
	}
}
