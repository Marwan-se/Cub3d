/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cube.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:13:58 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/23 18:35:04 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static	mlx_image_t* image;
// static	Player	p;
// static	Rays rays[NUM_RAYS];
// static	mlx_texture_t*texture[4];
// -----------------------------------------------------------------------------

// uint32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void	ft_setup(void *param)
// {
// 	cub3d_t		*cub;
// 	mlx_image_t	*img[4];

// 	// cub->map = ft_read_map(file);
// 	// printf("#########################");
// 	// if (!cub->map)
// 	// 	exit(0);
// 	// printf("hello world \n");
// 	cub = param;
// 	cub->p.y = 250;
// 	cub->p.x = 250;
// 	cub->p.width = 1;
// 	cub->p.height = 1;
// 	cub->p.turnDirection = 0;
// 	cub->p.walkDirection = 0;
// 	cub->p.turnDirection2 = 0;
// 	cub->p.rotationAngle = M_PI / 2;
// 	cub->p.walkSpeed = 600;
// 	cub->p.turnSpeed = 10 * (M_PI / 180);
// 	cub->F = ft_pixel(82, 67, 6, 255);
// 	cub->S = ft_pixel(2, 215, 246, 255);
// 	cub->texture[0] = mlx_load_png("./brick.png");
// 	cub->texture[1] = mlx_load_png("./Prev3.png");
// 	cub->texture[2] = mlx_load_png("./matrix.png");
// 	cub->texture[3] = mlx_load_png("./img.png");
// 	if (!cub->texture[0] || !cub->texture[1] || !cub->texture[2] || !cub->texture[3])
// 		return(perror("allocation failed"), exit(0));
// 	img[0] = mlx_texture_to_image(cub->mlx, cub->texture[0]);
// 	img[1] = mlx_texture_to_image(cub->mlx, cub->texture[1]);
// 	img[2] = mlx_texture_to_image(cub->mlx, cub->texture[2]);
// 	img[3] = mlx_texture_to_image(cub->mlx, cub->texture[3]);
// 	if (!img[0] || !img[1] || !img[2] || !img[3])
// 		return(perror("allocation failed"), exit(0));
// 	mlx_resize_image(img[0], TEXTURE_HEIGHT, TEXTURE_HEIGHT);
// 	mlx_resize_image(img[1], TEXTURE_HEIGHT, TEXTURE_HEIGHT);
// 	mlx_resize_image(img[2], TEXTURE_HEIGHT, TEXTURE_HEIGHT);
// 	mlx_resize_image(img[3], TEXTURE_HEIGHT, TEXTURE_HEIGHT);
// 	cub->tab = malloc (4 * sizeof(uint32_t *));
// 	cub->tab[0] = malloc((TEXTURE_HEIGHT * TEXTURE_HEIGHT) * sizeof(uint32_t));
// 	cub->tab[1] = malloc((TEXTURE_HEIGHT * TEXTURE_HEIGHT) * sizeof(uint32_t));
// 	cub->tab[2] = malloc((TEXTURE_HEIGHT * TEXTURE_HEIGHT) * sizeof(uint32_t));
// 	cub->tab[3] = malloc((TEXTURE_HEIGHT * TEXTURE_HEIGHT) * sizeof(uint32_t));
// 	if (!cub->tab[0] || !cub->tab[1] || !cub->tab[2] || !cub->tab[3])
// 		return(perror("allocation failed"), exit(0));
// 	int i = 0;
// 	int j = 0;
// 	int	k = 0;
// 	while (k < 4)
// 	{
// 		while (i < img[k]->height * img[k]->width)
// 		{
// 			cub->tab[k][i] =  ft_pixel(img[k]->pixels[j], img[k]->pixels[j + 1],img[k]->pixels[j + 2], img[k]->pixels[j + 3]);
// 			j += 4;
// 			i++;
// 		}
// 		j = 0;
// 		i = 0;
// 		k++;
// 	}
// }

// void	ft_update(void *param)
// {
// 	ft_move_player(param);
// 	ft_cast_rays(param);
// }

// void	ft_render(void *param)
// {
// 	t_cub3d	*cub;
// 	uint32_t	tileColor;

// 	cub = param;
// 	// ft_renederRays(param);
// 	ft_generate_projection(cub, tileColor);
// 	ft_renderMap(cub);
// 	ft_renderPlayer(cub);
// }

// -----------------------------------------------------------------------------
// int	main(int argc, const char** argv)
// {
// 	cub3d_t*		cube;
// 	mlx_t			*mlx;
// 	mlx_image_t		*image;

// 	cube = malloc(sizeof(cub3d_t));
// 	if (!(mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	ft_memset(image->pixels, 128, image->width * image->height * sizeof(int32_t));
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	cube->mlx = mlx;
// 	cube->image = image;
// 	ft_setup(cube);
// 	mlx_loop_hook(mlx, ft_update, cube);
// 	mlx_loop_hook(mlx, ft_render, cube);
// 	mlx_key_hook(mlx, ft_my_keyhook, (void *)cube);
// 	mlx_loop_hook(mlx, ft_hook, cube);
// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }