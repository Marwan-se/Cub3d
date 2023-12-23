/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:13:58 by mlahlafi          #+#    #+#             */
/*   Updated: 2023/12/23 20:20:26 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	mlx_image_t* image;
static	Player	p;
static	Rays rays[NUM_RAYS];
// -----------------------------------------------------------------------------

void	ft_setup()
{
	printf("setup is here %d\n", p.walkDirection);
	p.y = WINDOW_HEIGHT / 2;
	p.x = WINDOW_WIDTH / 2;
	p.width = 1;
	p.height = 1;
	p.turnDirection = 0;
	p.walkDirection = 0;
	p.rotationAngle = M_PI / 2;
	p.walkSpeed = 200;
	p.turnSpeed = 45 * (M_PI / 180);
}

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// Function for finding absolute value 
int abs(int n) { return ((n > 0) ? n : (n * (-1))); }
  
// DDA Function for line generation 
void	ft_DDA(int X0, int Y0, int X1, int Y1, int tileColor)
{ 
    // calculate dx & dy 
	// printf("x0 is %d y0 is %d, x1 is %d , y1 is %d\n", X0, Y0, X1, Y1);
    int dx = X1 - X0;
    int dy = Y1 - Y0;
	// int	tileColor = ft_pixel(255, 0, 0, 255);
	// calculate steps required for generating pixels 
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
  
    // calculate increment in x & y for each steps 
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;
  
    // Put pixel for each step 
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++) {
		// printf("HELLO\n");
    	mlx_put_pixel(image, round(X) * SACALE_FACTOR , round(Y) * SACALE_FACTOR, tileColor);
        X += Xinc;
        Y += Yinc;
		// printf("x0 is %f y0 is %f\n", X, Y);
    } 
}

int	mapHasWallAt(float x, float y)
{
	int	mapGridIndexX;
	int	mapGridIndexY;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return (TRUE);
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);
	return (map[mapGridIndexY][mapGridIndexX] != 0);
}

// float	ft_normalize(float rayAngle)
// {
// 	float	angle;

// 	angle = remainder(rayAngle, (2 * M_PI));
// 	if (angle < 0)
// 		angle += 2 * M_PI;
// 	return (angle);
// }

float ft_normalizeAngle(float angle) {
    angle = remainder(angle, 2 * M_PI);
    if (angle < 0) {
        angle = 2 * M_PI + angle;
    }
    return angle;
}


float ft_points_distance(float x1, float y1, float x2, float y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void ft_castRay(float rayAngle, int stripId) {
	info	info1;
	info	info2;

    rayAngle = ft_normalizeAngle(rayAngle);
    info1.facingDown = rayAngle > 0 && rayAngle < M_PI;
	info1.facingUp = !info1.facingDown;
    info1.facingRight = rayAngle < 0.5 * M_PI || rayAngle > 1.5 * M_PI;
    info1.facingLeft = !info1.facingRight;
	info2.facingDown = info1.facingDown;
	info2.facingUp = !info1.facingDown;
    info2.facingRight = info1.facingRight;
    info2.facingLeft = !info1.facingRight;
	info1.foundWallHit = FALSE;
    info1.wallHitX = 0;
    info1.wallContent = 0;
    info1.wallContent = 0;
	info2.foundWallHit = FALSE;
    info2.wallHitX = 0;
    info2.wallContent = 0;
    info2.wallContent = 0;
	ft_horizentalIntersection(rayAngle, stripId, &info1);
	ft_verticalIntersection(rayAngle, stripId, &info2);
	ft_chooseSmallestDistance(info1, info2, stripId, rayAngle);
}

//------------------------------------Choose the smallest one: horizental || vertical -----------------------------------------
void	ft_chooseSmallestDistance(info info1, info info2, int id, float rayAngle)
{
	float	horizDistance;
	float	vertDistance;

	vertDistance =	info2.foundWallHit * ft_points_distance(p.x, p.y, info2.wallHitX, info2.wallHitY) + !info2.foundWallHit * INT_MAX;
	horizDistance =	info1.foundWallHit * ft_points_distance(p.x, p.y, info1.wallHitX, info1.wallHitY) + !info1.foundWallHit * INT_MAX;
	if (vertDistance < horizDistance)
	{
		rays[id].distance = vertDistance;
		rays[id].wallHitX = info2.wallHitX;
		rays[id].wallHitY = info2.wallHitY;
		rays[id].wallHitContent = info2.wallContent; 
		rays[id].wasHitVertical = 1;
	}
	else
	{
		rays[id].distance = horizDistance;
		rays[id].wallHitX = info1.wallHitX;
		rays[id].wallHitY = info1.wallHitY;
		rays[id].wallHitContent = info1.wallContent;
		rays[id].wasHitVertical = 0;
	}
	rays[id].rayAngle = rayAngle;
	rays[id].isFacingUp = !info1.facingDown;
	rays[id].isFacingDown = info1.facingDown;
	rays[id].isFacingLeft = !info1.facingRight;
	rays[id].isFacingRight = info1.facingRight;
}
//------------------------------------Horizental intersection code -----------------------------------------
void	ft_horizentalIntersection(float rayAngle, int id, info * info1)
{
    float	xstep;
	float	ystep;
	float	yToCheck;

    info1->nextY = floor(p.y / TILE_SIZE) * TILE_SIZE; // Find the y-coordinate of the closest horizontal grid intersection
	info1->nextY += info1->facingDown * TILE_SIZE + !info1->facingDown * 0;
    info1->nextX = p.x + (info1->nextY - p.y) / tan(rayAngle);// Find the x-coordinate of the closest horizontal grid intersection
    ystep = TILE_SIZE;// Calculate the increment xstep and ystep
    ystep *= info1->facingUp ? -1 : 1;
    xstep = TILE_SIZE / tan(rayAngle);
    xstep *= (info1->facingLeft && xstep > 0) * -1 + !(info1->facingLeft && xstep > 0) * 1;
    xstep *= (info1->facingRight && xstep < 0) * -1 + !(info1->facingRight && xstep < 0) * 1;
    while (info1->nextX >= 0 && info1->nextX <= WINDOW_WIDTH && info1->nextY >= 0 && info1->nextY <= WINDOW_HEIGHT)    // Increment xstep and ystep until we find a wall
	{
        yToCheck = info1->nextY + (info1->facingUp ? -1 : 0);
        if (mapHasWallAt(info1->nextX, yToCheck))// found a wall hit
		{
            info1->wallHitX = info1->nextX;
            info1->wallHitY = info1->nextY;
            info1->wallContent = map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(info1->nextX/ TILE_SIZE)];
           	info1->foundWallHit = TRUE;
            break;
        } else {
            info1->nextX += xstep;
            info1->nextY += ystep;
        }
    }
}
//------------------------------------Vertical intersection code --------------------------------------------
void	ft_verticalIntersection(float rayAngle, int id, info * info2)
{
	float	xstep;
	float	ystep;
	float	xToCheck;

    info2->nextX = floor(p.x / TILE_SIZE) * TILE_SIZE;// Find the x-coordinate of the closest horizontal grid intersection
    info2->nextX += info2->facingRight * TILE_SIZE + !info2->facingRight * 0;
	info2->nextY = p.y + (info2->nextX - p.x) * tan(rayAngle);// Find the y-coordinate of the closest horizontal grid intersection
	xstep = TILE_SIZE; // Calculate the increment xstep and ystep
    xstep *= info2->facingLeft * -1 + !info2->facingLeft * 1;
	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (info2->facingUp && ystep > 0) * -1 + !(info2->facingUp && ystep > 0) * 1;
    ystep *= (info2->facingDown && ystep < 0) * -1 + !(info2->facingDown && ystep < 0) * 1;
    while (info2->nextX >= 0 && info2->nextX <= WINDOW_WIDTH && info2->nextY >= 0 && info2->nextY <= WINDOW_HEIGHT)// Increment xstep and ystep until we find a wall
	{
        xToCheck = info2->nextX + (info2->facingLeft ? -1 : 0);
        if (mapHasWallAt(xToCheck, info2->nextY))
		{
            info2->wallHitX = info2->nextX;// found a wall hit
            info2->wallHitY = info2->nextY;
            info2->wallContent = map[(int)floor(info2->nextY / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)];
            info2->foundWallHit = TRUE;
            break;
        } 
		else 
		{
            info2->nextX += xstep;
            info2->nextY += ystep;
        }
    }
}

void	ft_cast_rays(void *param)
{
	float	rayAngle;
	int		id;

	id = 0;
	rayAngle = p.rotationAngle - FOV_ANGLE / 2;
	while (id < NUM_RAYS)
	{
		ft_castRay(rayAngle, id);
		rayAngle += FOV_ANGLE / NUM_RAYS;
		// printf("ray angle is %f\n", rayAngle);
		id++;
	}
}

void	ft_move_player(void *param)
{
	p.rotationAngle += p.turnDirection * p.turnSpeed * 0.1;
	float	moveStep = p.walkDirection * p.walkSpeed * 0.1;
	float	newPlayerX = p.x + cos(p.rotationAngle) * moveStep * 0.2;
	float	newPlayerY = p.y + sin(p.rotationAngle) * moveStep * 0.2;

	if (!mapHasWallAt(newPlayerX, newPlayerY))
	{
		p.x = newPlayerX;
		p.y = newPlayerY;
	}
}

void	ft_update(void *param)
{
	ft_move_player(param);
	ft_cast_rays(param);
}

void	ft_renderPlayer(void *param)
{
	int	i;
	int	j;
	int	tileColor;

	i = p.y;
	tileColor = ft_pixel(255, 255, 255, 255);
	while (i < p.height + p.y)
	{
		j = p.x;
		while (j < p.width + p.x)
		{
			mlx_put_pixel(image, j * SACALE_FACTOR, i * SACALE_FACTOR, tileColor);
			j++;
		}
		// printf("i is %d, j is %d\n", i ,j);
		i++;
	}
	// printf ("render player angle, %f\n", p.rotationAngle);
	ft_DDA(p.x, p.y, p.x + (float) cos(p.rotationAngle) * 40, p.y + sin(p.rotationAngle) * 40, tileColor);
}
void	ft_renderMap(void *param)
{
	mlx_t		*mlx;
	int			i;
	int			j;
	int			tileColor;

	1 && (mlx = param) && (i = 0) && (j = 0) && (tileColor = 0);
	i = 0;
	j = 0;
	tileColor = 0;
	mlx = param;
	while(i < image->height)
	{
		j = 0;
		while (j < image->width)
		{
			if (map[i / TILE_SIZE][j / TILE_SIZE])
				tileColor = ft_pixel(255, 255, 255, 255);
			else
				tileColor = ft_pixel(0, 0, 0, 0);
			mlx_put_pixel(image, j * SACALE_FACTOR, i * SACALE_FACTOR, tileColor);
			j++;
			// printf("hello i is %d, j is %d\n", image->width , j / TILE_SIZE);
		}
		i++;
	}
}
void	ft_renederRays(void *param)
{
	int	i;
	int	tileColor;
	
	i = 0;
	// ft_cast_rays(param);
	tileColor = ft_pixel(255, 0, 0, 255);
	while (i < WINDOW_WIDTH)
	{
		ft_DDA(p.x, p.y, rays[i].wallHitX, rays[i].wallHitY, ft_pixel(255, 255, i,255));
		i++;
	}
	
}
void	ft_render(void *param)
{
	ft_renderMap(param);
	ft_renederRays(param);
	// ft_setup();
	ft_renderPlayer(param);
}

void ft_hook(void* param)
{
	mlx_t* mlx = param;

	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	// if (mlx_is_key_down(mlx, MLX_KEY_UP))
	// {
	// 	printf("hook is here\n");
	// 	p.walkDirection = 1;
	// }
	// if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	// 	p.walkDirection = -1;
	// if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	// 	p.turnDirection = -1;
	// if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	// 	p.turnDirection = 1;
}

void ft_my_keyhook(mlx_key_data_t keydata, void* param)
{
	// If we PRESS the 'J' key, print "Hello".
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_UP)
		{
			p.walkDirection = 1;
			// printf("keyhook is here %d\n", p.walkDirection);
		}
		if (keydata.key == MLX_KEY_DOWN)
			p.walkDirection = -1;
		if (keydata.key == MLX_KEY_LEFT)
			p.turnDirection = -1;
		if (keydata.key == MLX_KEY_RIGHT)
			p.turnDirection = 1;
		}
	else if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_UP)
			p.walkDirection = 0;
		if (keydata.key == MLX_KEY_DOWN)
			p.walkDirection = 0;
		if (keydata.key == MLX_KEY_LEFT)
			p.turnDirection = 0;
		if (keydata.key == MLX_KEY_RIGHT)
			p.turnDirection = 0;
	}
}
// -----------------------------------------------------------------------------

int	main(int argc, const char* argv[])
{
	mlx_t* mlx;
	int t = 0;
	// Gotta error check this stuff
	if (!(mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MLX42", true)))
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (!(image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT)))
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	ft_setup();
	// ft_update(mlx);
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_update, mlx);
	mlx_loop_hook(mlx, ft_render, mlx);
	mlx_key_hook(mlx, ft_my_keyhook, NULL);
	mlx_loop_hook(mlx, ft_hook, mlx);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}