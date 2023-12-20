/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:13:58 by mlahlafi          #+#    #+#             */
/*   Updated: 2023/12/20 23:45:34 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static	mlx_image_t* image;
static	Player	p;
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
	p.roatationAngle = M_PI / 2;
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
void	ft_DDA(int X0, int Y0, int X1, int Y1)
{ 
    // calculate dx & dy 
	// printf("x0 is %d y0 is %d, x1 is %d , y1 is %d\n", X0, Y0, X1, Y1);
    int dx = X1 - X0;
    int dy = Y1 - Y0;
	int	tileColor = ft_pixel(255, 0, 0, 255);
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
    	mlx_put_pixel(image, round(X) * MINI_MAP_SACALE_FACTOR , round(Y) * MINI_MAP_SACALE_FACTOR, tileColor);
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

void	ft_move_player(void *param)
{
	p.roatationAngle += p.turnDirection * p.turnSpeed * 0.1;
	float	moveStep = p.walkDirection * p.walkSpeed * 0.1;
	float	newPlayerX = p.x + cos(p.roatationAngle) * moveStep * 0.2;
	float	newPlayerY = p.y + sin(p.roatationAngle) * moveStep * 0.2;

	if (!mapHasWallAt(newPlayerX, newPlayerY))
	{
		p.x = newPlayerX;
		p.y = newPlayerY;
	}
}

void	ft_update(void *param)
{
	ft_move_player(param);
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
			mlx_put_pixel(image, j * MINI_MAP_SACALE_FACTOR, i * MINI_MAP_SACALE_FACTOR, tileColor);
			j++;
		}
		// printf("i is %d, j is %d\n", i ,j);
		i++;
	}
	ft_DDA(p.x, p.y, p.x + (float) cos(p.roatationAngle) * 40, p.y + sin(p.roatationAngle) * 40);
	
}
void	ft_renderMap(void *param)
{
	mlx_t		*mlx;
	int			i;
	int			j;
	uint32_t	tileColor;

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
			mlx_put_pixel(image, j * MINI_MAP_SACALE_FACTOR, i * MINI_MAP_SACALE_FACTOR, tileColor);
			j++;
			// printf("hello i is %d, j is %d\n", image->width , j / TILE_SIZE);
		}
		i++;
	}
}
void	ft_render(void *param)
{
	ft_renderMap(param);
	// renederRays();
	// ft_setup();
	ft_renderPlayer(param);
}

void ft_randomize(void* param)
{
	for (int32_t i = 0; i < image->width; ++i)
	{
		for (int32_t y = 0; y < image->height; ++y)
		{
			uint32_t color = ft_pixel(
				rand() % 0xFF, // R
				rand() % 0xFF, // G
				rand() % 0xFF, // B
				rand() % 0xFF  // A
			);
			mlx_put_pixel(image, i, y, color);
		}
	}
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

int32_t main(int32_t argc, const char* argv[])
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