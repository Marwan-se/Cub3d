/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rays.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 02:52:25 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 05:02:23 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_DDA(int X0, int Y0, int X1, int Y1, t_cub3d *cub)
{
	int		i;
	float	X;
	float	Y;
	int		dx;
	int		dy;
	int		steps;
	float	Xinc;
	float	Yinc;
	
	i = 0;
    dx = X1 - X0;
    dy = Y1 - Y0;
	steps = (abs(dx) > abs(dy)) * abs(dx) + !(abs(dx) > abs(dy))  * abs(dy);
    Xinc = dx / (float)steps;
    Yinc = dy / (float)steps;
    X = X0;
    Y = Y0;
	while (i <= steps)
	{
    	mlx_put_pixel(cub->image, round(X) * SACALE_FACTOR , round(Y) * SACALE_FACTOR, 0xff0000ff);
        X += Xinc;
        Y += Yinc;
		i++;
    } 
}

float ft_normalizeAngle(float angle)
{
    angle = remainder(angle, 2 * M_PI);
    if (angle < 0) {
        angle = 2 * M_PI + angle;
    }
    return angle;
}

void ft_castRay(float rayAngle, int stripId, t_cub3d *cub)
{
	info	info1;
	info	info2;

    rayAngle = ft_normalizeAngle(rayAngle);
    info1.facingDown = rayAngle > 0 && rayAngle < M_PI;
    info1.facingRight = rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI;
	info2.facingDown = info1.facingDown;
    info2.facingRight = info1.facingRight;
	info1.foundWallHit = FALSE;
    info1.wallHitX = 0;
    info1.wallContent = 0;
	info2.foundWallHit = FALSE;
    info2.wallHitX = 0;
    info2.wallContent = 0;
	ft_horizentalIntersection(rayAngle, stripId, &info1, cub);
	ft_verticalIntersection(rayAngle, stripId, &info2, cub);
	ft_chooseSmallestDistance(info1, info2, stripId, rayAngle, cub);
}

void	ft_cast_rays(t_cub3d *cub)
{
	float	rayAngle;
	int		id;
	float	DPP;

	id = 0;
	DPP = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (id < NUM_RAYS)
	{
		rayAngle = cub->p->rotation_angle + atan((id - NUM_RAYS / 2) / DPP);
		ft_castRay(rayAngle, id, cub);
		id++;
	}
}