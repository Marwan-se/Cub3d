/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays_hit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:50:29 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 05:53:53 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float ft_points_distance(float x1, float y1, float x2, float y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}
//------------------------------------Choose the smallest one: horizental || vertical -----------------------------------------
void	ft_chooseSmallestDistance(info info1, info info2, int id, float rayAngle, t_cub3d *cub)
{
	float	horizDistance;
	float	vertDistance;

	vertDistance =	info2.foundWallHit * ft_points_distance(cub->p->x,cub->p->y,
		info2.wallHitX, info2.wallHitY) + !info2.foundWallHit * INT_MAX;
	horizDistance =	info1.foundWallHit * ft_points_distance(cub->p->x,cub->p->y,
		info1.wallHitX, info1.wallHitY) + !info1.foundWallHit * INT_MAX;
	if (vertDistance < horizDistance)
	{
		cub->rays[id].distance = vertDistance;
		cub->rays[id].wallHitX = info2.wallHitX;
		cub->rays[id].wallHitY = info2.wallHitY;
		cub->rays[id].wallHitContent = info2.wallContent;
		cub->rays[id].wasHitVertical = 1;
	}
	else
	{
		cub->rays[id].distance = horizDistance;
		cub->rays[id].wallHitX = info1.wallHitX;
		cub->rays[id].wallHitY = info1.wallHitY;
		cub->rays[id].wallHitContent = info1.wallContent;
		cub->rays[id].wasHitVertical = 0;
	}
	cub->rays[id].rayAngle = rayAngle;
	cub->rays[id].isFacingUp = !info1.facingDown;
	cub->rays[id].isFacingDown = info1.facingDown;
	cub->rays[id].isFacingLeft = !info1.facingRight;
	cub->rays[id].isFacingRight = info1.facingRight;
}
//------------------------------------Horizental intersection code -----------------------------------------
void	ft_horizentalIntersection(float rayAngle, info * info1, t_cub3d *cub)
{
    float	xstep;
	float	ystep;
	float	yToCheck;

    info1->nextY = floor(cub->p->y / tile_size) * tile_size; // Find the y-coordinate of the closest horizontal grid intersection
	info1->nextY += info1->facingDown * tile_size + !info1->facingDown * 0;
    info1->nextX = cub->p->x + (info1->nextY - cub->p->y) / tan(rayAngle);// Find the x-coordinate of the closest horizontal grid intersection
	1 && (ystep = tile_size) && (ystep *= !info1->facingDown * -1 + (info1->facingDown * 1));// Calculate the increment xstep and ystep
    xstep = tile_size / tan(rayAngle);
    xstep *= (!info1->facingRight && xstep > 0) * -1 + !(!info1->facingRight && xstep > 0) * 1;
    xstep *= (info1->facingRight && xstep < 0) * -1 + !(info1->facingRight && xstep < 0) * 1;
    while (info1->nextX >= 0 && info1->nextX <= cub->map_num_cols * tile_size && info1->nextY >= 0 && info1->nextY <= cub->map_num_rows * tile_size)// Increment xstep and ystep until we find a wall
	{
        yToCheck = info1->nextY + !info1->facingDown * -1;
        if (map_has_wall_at(cub, info1->nextX, yToCheck))// found a wall hit
		{
			1 && (info1->wallHitX = info1->nextX) && (info1->wallHitY = info1->nextY);
            info1->wallContent = (cub->map[(int)floor(yToCheck / tile_size)][(int)floor(info1->nextX/ tile_size)] != '0');
           	info1->foundWallHit = TRUE;
            break;
        }
		else
            1 && (info1->nextX += xstep) && (info1->nextY += ystep);
	}
}
//------------------------------------Vertical intersection code --------------------------------------------
void	ft_verticalIntersection(float rayAngle, info * info2, t_cub3d *cub)
{
	float	xstep;
	float	ystep;
	float	xToCheck;

    info2->nextX = floor(cub->p->x / tile_size) * tile_size;// Find the x-coordinate of the closest horizontal grid intersection
    info2->nextX += info2->facingRight * tile_size + !info2->facingRight * 0;
	info2->nextY = cub->p->y + (info2->nextX - cub->p->x) * tan(rayAngle);// Find the y-coordinate of the closest horizontal grid intersection
	1 && (xstep = tile_size) && (xstep *= !info2->facingRight * -1 + info2->facingRight * 1);
	ystep = tile_size * tan(rayAngle);
	ystep *= (!info2->facingDown && ystep > 0) * -1 + !(!info2->facingDown && ystep > 0) * 1;
    ystep *= (info2->facingDown && ystep < 0) * -1 + !(info2->facingDown && ystep < 0) * 1;
    while (info2->nextX >= 0 && info2->nextX <= cub->map_num_cols * tile_size && info2->nextY >= 0 && info2->nextY <= cub->map_num_rows * tile_size)// Increment xstep and ystep until we find a wall
	{
        xToCheck = info2->nextX + !info2->facingRight * -1;
        if (map_has_wall_at(cub, xToCheck, info2->nextY))
		{
            1 && (info2->wallHitX = info2->nextX) && (info2->wallHitY = info2->nextY);
            info2->wallContent = (cub->map[(int)floor(info2->nextY / tile_size)][(int)floor(xToCheck / tile_size)] != '0');
            info2->foundWallHit = TRUE;
            break;
        } 
		else 
            1 && (info2->nextX += xstep) && (info2->nextY += ystep);
    }
}
