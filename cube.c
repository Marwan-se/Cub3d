/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:13:58 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/16 06:27:43 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static	mlx_image_t* image;
// static	Player	p;
// static	Rays rays[NUM_RAYS];
// static	mlx_texture_t*texture[4];
// -----------------------------------------------------------------------------

uint32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
    return (r << 24 | g << 16 | b << 8 | a);
}

// char	**ft_read_map(char *file)
// {
//     int        fd = 0;
//     char    *line = 0;
//     char    *map_1d = 0;
//     char    *tmp = 0;
// 	char	**grid;

//     fd = open(file, O_RDONLY);
// 	if (!fd)
// 		return (0);
//     map_1d = ft_strdup("");
//     line = get_next_line(fd);
//     while (line)
//     {
//         tmp = map_1d;
//         map_1d = ft_strjoin(map_1d, line);
//         free(tmp);
//         free(line);
//         line = get_next_line(fd);
//     }
//     grid = ft_split(map_1d, '\n');
// 	char **tmp2 = grid;
// 	// char *tmp1 = tmp2[0];
// 	// while (tmp2)
// 	// {
// 	// 	tmp1 = tmp2;
// 	// 	while (tmp1)
// 	// 		printf("%s\n", tmp1++);
// 	// 	tmp2++;
// 	// }
//     free(map_1d);
// 	return (grid);
// }
void	ft_setup(void *param)
{
	cub3d_t		*cub;
	mlx_image_t	*img[4];

	// cub->map = ft_read_map(file);
	// printf("#########################");
	// if (!cub->map)
	// 	exit(0);
	// printf("hello world \n");
	cub = param;
	cub->p.y = MAP_NUM_COLS * TILE_SIZE / 2;
	cub->p.x = MAP_NUM_COLS * TILE_SIZE / 2;
	cub->p.width = 1;
	cub->p.height = 1;
	cub->p.turnDirection = 0;
	cub->p.walkDirection = 0;
	cub->p.turnDirection2 = 0;
	cub->p.rotationAngle = M_PI / 2;
	cub->p.walkSpeed = 1200;
	cub->p.turnSpeed = 10 * (M_PI / 180);
	cub->texture[0] = mlx_load_png("./brick.png");
	cub->texture[1] = mlx_load_png("./Prev3.png");
	cub->texture[2] = mlx_load_png("./matrix.png");
	cub->texture[3] = mlx_load_png("./img.png");
	if (!cub->texture[0] || !cub->texture[1] || !cub->texture[2] || !cub->texture[3])
		return(perror("allocation failed"), exit(0));
	img[0] = mlx_texture_to_image(cub->mlx, cub->texture[0]);
	img[1] = mlx_texture_to_image(cub->mlx, cub->texture[1]);
	img[2] = mlx_texture_to_image(cub->mlx, cub->texture[2]);
	img[3] = mlx_texture_to_image(cub->mlx, cub->texture[3]);
	if (!img[0] || !img[1] || !img[2] || !img[3])
		return(perror("allocation failed"), exit(0));
	mlx_resize_image(img[0], TEXTURE_HEIGHT, TEXTURE_HEIGHT);
	mlx_resize_image(img[1], TEXTURE_HEIGHT, TEXTURE_HEIGHT);
	mlx_resize_image(img[2], TEXTURE_HEIGHT, TEXTURE_HEIGHT);
	mlx_resize_image(img[3], TEXTURE_HEIGHT, TEXTURE_HEIGHT);
	cub->tab = malloc (4 * sizeof(uint32_t *));
	cub->tab[0] = malloc((TEXTURE_HEIGHT * TEXTURE_HEIGHT) * sizeof(uint32_t));
	cub->tab[1] = malloc((TEXTURE_HEIGHT * TEXTURE_HEIGHT) * sizeof(uint32_t));
	cub->tab[2] = malloc((TEXTURE_HEIGHT * TEXTURE_HEIGHT) * sizeof(uint32_t));
	cub->tab[3] = malloc((TEXTURE_HEIGHT * TEXTURE_HEIGHT) * sizeof(uint32_t));
	if (!cub->tab[0] || !cub->tab[1] || !cub->tab[2] || !cub->tab[3])
		return(perror("allocation failed"), exit(0));
	int i = 0;
	int j = 0;
	int	k = 0;
	while (k < 4)
	{
		while (i < img[k]->height * img[k]->width)
		{
			cub->tab[k][i] =  ft_pixel(img[k]->pixels[j], img[k]->pixels[j + 1],img[k]->pixels[j + 2], img[k]->pixels[j + 3]);
			j += 4;
			i++;
		}
		j = 0;
		i = 0;
		k++;
	}
}
// Function for finding absolute value 
int abs(int n) { return ((n > 0) ? n : (n * (-1)));}
  
// DDA Function for line generation 
void	ft_DDA(int X0, int Y0, int X1, int Y1, cub3d_t *cub)
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
    	mlx_put_pixel(cub->image, round(X) * SACALE_FACTOR , round(Y) * SACALE_FACTOR, 0xff0000ff);
        X += Xinc;
        Y += Yinc;
		// printf("x0 is %f y0 is %f\n", X, Y);
    } 
}

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

void ft_castRay(float rayAngle, int stripId, cub3d_t *cub)
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

//------------------------------------Choose the smallest one: horizental || vertical -----------------------------------------
void	ft_chooseSmallestDistance(info info1, info info2, int id, float rayAngle, cub3d_t *cub)
{
	float	horizDistance;
	float	vertDistance;

	vertDistance =	info2.foundWallHit * ft_points_distance(cub->p.x,cub->p.y, info2.wallHitX, info2.wallHitY) + !info2.foundWallHit * INT_MAX;
	horizDistance =	info1.foundWallHit * ft_points_distance(cub->p.x,cub->p.y, info1.wallHitX, info1.wallHitY) + !info1.foundWallHit * INT_MAX;
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
void	ft_horizentalIntersection(float rayAngle, int id, info * info1, cub3d_t *cub)
{
    float	xstep;
	float	ystep;
	float	yToCheck;

    info1->nextY = floor(cub->p.y / TILE_SIZE) * TILE_SIZE; // Find the y-coordinate of the closest horizontal grid intersection
	info1->nextY += info1->facingDown * TILE_SIZE + !info1->facingDown * 0;
    info1->nextX = cub->p.x + (info1->nextY - cub->p.y) / tan(rayAngle);// Find the x-coordinate of the closest horizontal grid intersection
	ystep = TILE_SIZE;// Calculate the increment xstep and ystep
    ystep *= !info1->facingDown * -1 + (info1->facingDown * 1);
    xstep = TILE_SIZE / tan(rayAngle);
    xstep *= (!info1->facingRight && xstep > 0) * -1 + !(!info1->facingRight && xstep > 0) * 1;
    xstep *= (info1->facingRight && xstep < 0) * -1 + !(info1->facingRight && xstep < 0) * 1;
    while (info1->nextX >= 0 && info1->nextX <= MAP_NUM_COLS * TILE_SIZE && info1->nextY >= 0 && info1->nextY <= MAP_NUM_ROWS * TILE_SIZE)// Increment xstep and ystep until we find a wall
	{
        yToCheck = info1->nextY + !info1->facingDown * -1;
        if (mapHasWallAt(cub, info1->nextX, yToCheck))// found a wall hit
		{
            info1->wallHitX = info1->nextX;
            info1->wallHitY = info1->nextY;
            info1->wallContent = (map[(int)floor(yToCheck / TILE_SIZE)][(int)floor(info1->nextX/ TILE_SIZE)] != '0');
           	info1->foundWallHit = TRUE;
            break;
        }
		else
		{
            info1->nextX += xstep;
            info1->nextY += ystep;
        }
    }
}
//------------------------------------Vertical intersection code --------------------------------------------
void	ft_verticalIntersection(float rayAngle, int id, info * info2, cub3d_t *cub)
{
	float	xstep;
	float	ystep;
	float	xToCheck;

    info2->nextX = floor(cub->p.x / TILE_SIZE) * TILE_SIZE;// Find the x-coordinate of the closest horizontal grid intersection
    info2->nextX += info2->facingRight * TILE_SIZE + !info2->facingRight * 0;
	info2->nextY = cub->p.y + (info2->nextX - cub->p.x) * tan(rayAngle);// Find the y-coordinate of the closest horizontal grid intersection
	xstep = TILE_SIZE; // Calculate the increment xstep and ystep
    xstep *= !info2->facingRight * -1 + info2->facingRight * 1;
	ystep = TILE_SIZE * tan(rayAngle);
	ystep *= (!info2->facingDown && ystep > 0) * -1 + !(!info2->facingDown && ystep > 0) * 1;
    ystep *= (info2->facingDown && ystep < 0) * -1 + !(info2->facingDown && ystep < 0) * 1;
    while (info2->nextX >= 0 && info2->nextX <= MAP_NUM_COLS * TILE_SIZE && info2->nextY >= 0 && info2->nextY <= MAP_NUM_ROWS * TILE_SIZE)// Increment xstep and ystep until we find a wall
	{
        xToCheck = info2->nextX + !info2->facingRight * -1;
        if (mapHasWallAt(cub, xToCheck, info2->nextY))
		{
            info2->wallHitX = info2->nextX;// found a wall hit
		    info2->wallHitY = info2->nextY;
            info2->wallContent = (map[(int)floor(info2->nextY / TILE_SIZE)][(int)floor(xToCheck / TILE_SIZE)] != '0');
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

void	ft_cast_rays(cub3d_t *cub)
{
	float	rayAngle;
	int		id;
	float	DPP;

	id = 0;
	DPP = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
	while (id < NUM_RAYS)
	{
		rayAngle = cub->p.rotationAngle + atan((id - NUM_RAYS / 2) / DPP);
		ft_castRay(rayAngle, id, cub);
		id++;
	}
}

int	mapHasWallAt(cub3d_t *cub,float x, float y)
{
	int	mapGridIndexX;
	int	mapGridIndexY; 

	if (x < 0 || x > MAP_NUM_COLS * TILE_SIZE || y < 0 || y > MAP_NUM_ROWS * TILE_SIZE)
		return (TRUE);
	mapGridIndexX = floor(x / TILE_SIZE);
	mapGridIndexY = floor(y / TILE_SIZE);
	if (mapGridIndexX > MAP_NUM_COLS)
	{
		mapGridIndexX = MAP_NUM_COLS;
		// printf("%d | %d", mapGridIndexX, mapGridIndexY);
	}
	if (mapGridIndexY > MAP_NUM_ROWS)
	{
		mapGridIndexY = MAP_NUM_ROWS;
	}
	// if (mapGridIndexX < 0)
	// 	mapGridIndexX = 0;
	// if (mapGridIndexY)
	// 	mapGridIndexY = 0;
	// printf("%d | %d\n\n", mapGridIndexX, mapGridIndexY);
	return (map[mapGridIndexY][mapGridIndexX] != '0');
}

void	ft_move_player(cub3d_t *cub)
{
	cub->p.rotationAngle += cub->p.turnDirection * cub->p.turnSpeed * 0.2;
	float	moveStep = cub->p.walkDirection * cub->p.walkSpeed * 0.1;
	float	moveStep2 = cub->p.sideWalkDirection * cub->p.walkSpeed / 4 * 0.1;
	float	newPlayerX = cub->p.x + cos(cub->p.rotationAngle) * moveStep * 0.2 + cos(cub->p.rotationAngle + M_PI / 2) * moveStep2;
	float	newPlayerY = cub->p.y + sin(cub->p.rotationAngle) * moveStep * 0.2 + sin(cub->p.rotationAngle + M_PI / 2) * moveStep2;
	if (!mapHasWallAt(cub, newPlayerX, cub->p.y))
	{
		cub->p.x = newPlayerX;
	}
	if (!mapHasWallAt(cub, cub->p.x, newPlayerY))
	{
		cub->p.y = newPlayerY;
	}
}

void	ft_update(void *param)
{
	ft_move_player(param);
	ft_cast_rays(param);
}
void	ft_renderPlayer(cub3d_t *cub)
{
	int		i;
	int		j;
	int		tileColor;

	i = cub->p.y;
	tileColor = ft_pixel(255, 255, 255, 255);
	while (i < cub->p.height + cub->p.y)
	{
		j = cub->p.x;
		while (j < cub->p.width + cub->p.x)
		{
			mlx_put_pixel(cub->image, j * SACALE_FACTOR, i * SACALE_FACTOR, 0xff0000ff);
			j++;
		}
		// printf("i is %d, j is %d\n", i ,j);
		i++;
	}
	// printf ("render player angle, %f\n", p.rotationAngle);
	ft_DDA(cub->p.x, cub->p.y, cub->p.x + (float) cos(cub->p.rotationAngle) * 40, cub->p.y + sin(cub->p.rotationAngle) * 40, cub);
}
void	ft_renderMap(void *param)
{
	mlx_t		*mlx;
	int			i;
	int			j;
	int			tileColor;
	cub3d_t		*cub;

	cub = param;
	1 && (mlx = param) && (i = 0) && (j = 0) && (tileColor = 0);
	i = 0;
	j = 0;
	tileColor = 0;
	mlx = param;
	while(i < cub->image->height)
	{
		j = 0;
		while (j < cub->image->width)
		{
			if (map[i / TILE_SIZE][j / TILE_SIZE] != 0)
				tileColor = ft_pixel(255, 255, 255, 255);
			else
				tileColor = ft_pixel(0, 0, 0, 0);
			mlx_put_pixel(cub->image, j * SACALE_FACTOR, i * SACALE_FACTOR, tileColor);
			j++;
			// printf("hello i is %d, j is %d\n", image->width , j / TILE_SIZE);
		}
		i++;
	}
}
void	ft_renederRays(cub3d_t *cub)
{
	int	i;
	int	tileColor;
	
	i = 0;
	// ft_cast_rays(param);
	tileColor = ft_pixel(255, 0, 0, 255);
	while (i < WINDOW_WIDTH)
	{
		ft_DDA(cub->p.x, cub->p.y, cub->rays[i].wallHitX, cub->rays[i].wallHitY, cub);
		i++;
	}
	
}

void	ft_generate_projection(cub3d_t *cub)
{
	int		i;
	int		y;
	float	wallHight;
	float	DPP;
	int		wallTopPixel;
	int		wallBottomPixel;
	int		j;
	int		w;
	int		m,n;
	int		textureOffSetX;
	uint32_t	*choice;

	i = 0;
	choice = 0;
	while (i < NUM_RAYS)
	{
		y = 0;
		DPP = (WINDOW_WIDTH / 2) / tan(FOV_ANGLE / 2);
		wallHight = TILE_SIZE / (cos(cub->rays[i].rayAngle - cub->p.rotationAngle) * cub->rays[i].distance) * DPP;
		int wallStripHight = (int) wallHight;
		wallTopPixel = WINDOW_HEIGHT / 2 - wallStripHight / 2;
		wallTopPixel = (wallTopPixel < 0) ? 0 : wallTopPixel;
		wallBottomPixel = WINDOW_HEIGHT / 2 + wallStripHight / 2;
		wallBottomPixel = wallBottomPixel > WINDOW_HEIGHT ? WINDOW_HEIGHT : wallBottomPixel;
		if (wallHight > WINDOW_HEIGHT)
			wallHight = WINDOW_HEIGHT;
		// while (y < wallHight)
		// {
		// 	pix = (y + WINDOW_HEIGHT / 2 - wallHight / 2) * img->width + i;
		// 	if (rays[i].distance >= 50)
		// 		mlx_put_pixel(image, i, y + WINDOW_HEIGHT / 2 - wallHight / 2, ft_pixel(img->pixels[pix], img->pixels[pix + 1], img->pixels[pix + 2], img->pixels[pix + 3] / (rays[i].distance / 50)));
		// 	else
		// 		mlx_put_pixel(image, i, y + WINDOW_HEIGHT / 2 - wallHight / 2, ft_pixel(img->pixels[pix], img->pixels[pix + 1], img->pixels[pix + 2], img->pixels[pix + 3]));
		// 	y++;
		// }
		
		j = 0;
		if (!cub->image)
			return(perror("error in image"), exit(0));
		while (j < wallTopPixel)
		{
			mlx_put_pixel(cub->image, i, j, ft_pixel(2, 215, 246, 255));
			j++;
		}
		uint32_t	tileColor;
		// printf("p.rotationAngle %f\n", p.rotationAngle);
		if (cub->rays[i].wasHitVertical)
		{
			// printf("hello yes vertical\n");
			textureOffSetX = (int) cub->rays[i].wallHitY % TILE_SIZE;
			if (cub->rays[i].isFacingRight)
				choice = cub->tab[0];
			else
				choice = cub->tab[1];
			// printf("hit HORRRRRRRZZZ\n");
		}
		else
		{
			// printf("hello yes horizental\n");
			if (cub->rays[i].isFacingUp)
				choice = cub->tab[2];
			else
				choice = cub->tab[3];
			textureOffSetX = (int) cub->rays[i].wallHitX % TILE_SIZE;
			// printf("hit Vertiiiiiiical\n");
		}
		w = wallTopPixel;
		// choice = cub->tab[0];
		while (w < wallBottomPixel)
		{
			// printf("wlall strip hight is %d \n", wallStripHight);
			int	distanceFromTop = w + wallStripHight / 2 - WINDOW_HEIGHT / 2;
			int	texetureOffSetY = distanceFromTop * (((float) TEXTURE_HEIGHT) / wallStripHight);
			// printf("texetureOffSetY  = %d, textureOffSetX = %d\n", texetureOffSetY, textureOffSetX);
			tileColor = choice[(TEXTURE_WIDTH * texetureOffSetY) + textureOffSetX];
			// printf("heloo \n");
			// printf("tileColor %d\n", texture->width * texetureOffSetY + textureOffSetX);
			mlx_put_pixel(cub->image, i, w, tileColor);
			w++;
			// Convert texture to a displayable image
		}
		j = wallBottomPixel;
		while (j < WINDOW_HEIGHT)
		{
			mlx_put_pixel(cub->image, i, j, ft_pixel(82, 67, 6, 255));
			j++;
		}
		i++;
	}
}

void	ft_render(void *param)
{
	cub3d_t	*cub;
	cub = param;

	// ft_renderMap(param);
	// ft_renederRays(param);
	// ft_renderPlayer(param);
	// ft_setup(param);
	ft_generate_projection(param);
}

void ft_hook(void* param)
{
	cub3d_t*	cub;
	
	cub = param;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(cub->mlx);
	if (mlx_is_key_down(cub->mlx, MLX_KEY_LEFT))
		cub->p.turnDirection = -1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_RIGHT))
		cub->p.turnDirection = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_W))
		cub->p.walkDirection = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_S))
		cub->p.walkDirection = -1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_D))
		cub->p.sideWalkDirection = 1;
	if (mlx_is_key_down(cub->mlx, MLX_KEY_A))
		cub->p.sideWalkDirection = -1;
	// if (mlx_is_key_up(cub->mlx, MLX_KEY_LEFT))
	// 	cub->p.turnDirection = 0;
	// if (mlx_is_key_up(cub->mlx, MLX_KEY_RIGHT))
	// 	cub->p.turnDirection = 0;
	// if (mlx_is_key_up(cub->mlx, MLX_KEY_W))
	// 	cub->p.walkDirection = 0;
	// if (mlx_is_key_up(cub->mlx, MLX_KEY_S))
	// 	cub->p.walkDirection = 0;
	// if (mlx_is_key_up(cub->mlx, MLX_KEY_D))
	// 	cub->p.sideWalkDirection = 0;
	// if (mlx_is_key_up(cub->mlx, MLX_KEY_A))
	// 	cub->p.sideWalkDirection = 0;

}

void ft_my_keyhook(mlx_key_data_t keydata, void *param)
{
	// If we PRESS the 'J' key, print "Hello".
	cub3d_t	*cub;

	cub = param;
	// printf("%d = %d, %d = %d\n", keydata.action, MLX_PRESS, keydata.key, MLX_KEY_W);
	// if (keydata.action == MLX_PRESS)
	// {
	// 	if (keydata.key == MLX_KEY_W)
	// 	{
	// 		printf("heloo its me2\n");
	// 		cub->p.walkDirection = 1;
	// 	}
	// 	if (keydata.key == MLX_KEY_S)
	// 		cub->p.walkDirection = -1;
	// 	if (keydata.key == MLX_KEY_LEFT)
	// 		cub->p.turnDirection = -1;
	// 	if (keydata.key == MLX_KEY_RIGHT)
	// 		cub->p.turnDirection = 1;
	// 	if (keydata.key == MLX_KEY_D)
	// 	{
	// 		cub->p.sideWalkDirection = 1;
	// 		// p.turnDirection2 = M_PI / 2;
	// 	}
	// 	if (keydata.key == MLX_KEY_A)
	// 	{
	// 		cub->p.sideWalkDirection = -1;
	// 		// p.turnDirection2 = - M_PI / 2;
	// 	}
	// }
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_W)
			cub->p.walkDirection = 0;
		if (keydata.key == MLX_KEY_S)
			cub->p.walkDirection = 0;
		if (keydata.key == MLX_KEY_LEFT)
			cub->p.turnDirection = 0;
		if (keydata.key == MLX_KEY_RIGHT)
			cub->p.turnDirection = 0;
		if (keydata.key == MLX_KEY_A || (keydata.key == MLX_KEY_D))
		{
			cub->p.sideWalkDirection = 0;
			// p.turnDirection2 = 0;
		}
	}
}

// -----------------------------------------------------------------------------
int	main(int argc, const char** argv)
{
	// char **map = ft_read_map("map04.cub");
	// int i = 0;
	// int j;
	// while (*(map + i))
	// {
	// 	printf("{");
	// 	j = 0;
	// 	while (map[i][j])
	// 	{
	// 		printf("'%c',",map[i][j]);
	// 		j++;
	// 	}
	// 	printf("},\n");
	// 	// ft_putendl_fd(*(map  + i), 1);
	// 	i++;
	// }
	cub3d_t*		cube;
	mlx_t			*mlx;
	mlx_image_t		*image;
	// Gotta error check this stuff
	cube = malloc(sizeof(cub3d_t));
	
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
	ft_memset(image->pixels, 128, image->width * image->height * sizeof(int32_t));
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	cube->mlx = mlx;
	cube->image = image;
	ft_setup(cube);
	// ft_update(mlx);
	// mlx_loop_hook(mlx, ft_randomize, mlx);
	mlx_loop_hook(mlx, ft_update, cube);
	mlx_loop_hook(mlx, ft_render, cube);
	mlx_key_hook(mlx, ft_my_keyhook, (void *)cube);
	mlx_loop_hook(mlx, ft_hook, cube);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}