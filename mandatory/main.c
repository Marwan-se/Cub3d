/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:23 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/24 03:26:16 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fd_error(int fd)
{
	if (fd == -1)
	{
		write(2, "Error: File not found\n", 22);
		exit(1);
	}
}

void	map_error(char **map)
{
	if (!map)
	{
		write(2, "Error: Map is empty\n", 20);
		exit(1);
	}
}

void    free_map(char **map)
{
    int i = 0;
    while (map[i])
    {
        free(map[i]);
        i++;
    }
    free(map);
}

void	ft_setup(void *param)
{
	t_cub3d		*player;
	mlx_image_t	*img[4];

	// cub->map = ft_read_map(file);
	// printf("#########################");
	// if (!cub->map)
	// 	exit(0);
	// printf("hello world \n");
	player = param;
	player->p->width = 1;
	player->p->height = 1;
	player->p->turnDirection = 0;
	player->p->walkDirection = 0;
	player->p->turnDirection2 = 0;
	// player->p->rotationAngle = M_PI / 2;
	player->p->walkSpeed = 250;
	player->p->turnSpeed = 10 * (M_PI / 180);
	player->texture[0] = mlx_load_png(player->EA);
	player->texture[1] = mlx_load_png(player->WE);
	player->texture[2] = mlx_load_png(player->NO);
	player->texture[3] = mlx_load_png(player->SO);
	if (!player->texture[0] || !player->texture[1] || !player->texture[2] || !player->texture[3])
		return( exit(0));
	img[0] = mlx_texture_to_image(player->mlx, player->texture[0]);
	img[1] = mlx_texture_to_image(player->mlx, player->texture[1]);
	img[2] = mlx_texture_to_image(player->mlx, player->texture[2]);
	img[3] = mlx_texture_to_image(player->mlx, player->texture[3]);
	if (!img[0] || !img[1] || !img[2] || !img[3])
		return(perror("allocation failed"), exit(0));
	mlx_resize_image(img[0], player->texture[0]->height, player->texture[0]->height);
	mlx_resize_image(img[1], player->texture[1]->height, player->texture[1]->height);
	mlx_resize_image(img[2], player->texture[2]->height, player->texture[2]->height);
	mlx_resize_image(img[3], player->texture[3]->height, player->texture[3]->height);
	player->tab = malloc (4 * sizeof(uint32_t *));
	player->tab[0] = malloc((player->texture[0]->height * player->texture[0]->height) * sizeof(uint32_t));
	player->tab[1] = malloc((player->texture[1]->height * player->texture[1]->height) * sizeof(uint32_t));
	player->tab[2] = malloc((player->texture[2]->height * player->texture[2]->height) * sizeof(uint32_t));
	player->tab[3] = malloc((player->texture[3]->height * player->texture[3]->height) * sizeof(uint32_t));
	if (!player->tab[0] || !player->tab[1] || !player->tab[2] || !player->tab[3])
		return(perror("allocation failed"), exit(0));
	unsigned int i = 0;
	int j = 0;
	int	k = 0;
	while (k < 4)
	{
		while (i < img[k]->height * img[k]->width)
		{
			player->tab[k][i] =  ft_pixel(img[k]->pixels[j], img[k]->pixels[j + 1],img[k]->pixels[j + 2], img[k]->pixels[j + 3]);
			j += 4;
			i++;
		}
		j = 0;
		i = 0;
		k++;
	}
}

void	ft_update(void *param)
{
	ft_move_player(param);
	ft_cast_rays(param);
}

void	ft_render(void *param)
{
	t_cub3d	*cub;
	uint32_t	tileColor;

	tileColor = 0;
	cub = param;
	// ft_renederRays(param);
	ft_generate_projection(cub, tileColor);
	ft_renderMap(cub);
	ft_renderPlayer(cub);
}

int main(int ac, char **av)
{
    t_cub3d *player;
	mlx_t			*mlx;
	mlx_image_t		*image;
	int fd;
    
    player = malloc(sizeof(t_cub3d));
    if(!player)
        ft_putstr_fd("Error: Malloc failed\n", 2);
	check_syntax(av[1], ac);
	fd = open(av[1], O_RDONLY);
	fd_error(fd);
	player->map = read_map_file(fd);
	map_error(player->map);
	parsing(player->map, fd, player);
	player->map = full_map(player->map, player);
    replace_spaces_with_2(player->map);
	// int i = 0;
	// while (player->map[i])
	// {
	// 	printf("%s\n", player->map[i]);
	// 	i++;
	// }
	// printf("%d\n", player->MAP_NUM_ROWS);
	// printf("%d\n", player->MAP_NUM_COLS);
	printf("%f\n", player->p->x);
	printf("%f\n", player->p->y);
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
	memset(image->pixels, 128, image->width * image->height * sizeof(int32_t));
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	player->mlx = mlx;
	player->image = image;
	ft_setup(player);
	mlx_loop_hook(mlx, ft_update, player);
	mlx_loop_hook(mlx, ft_render, player);
	mlx_key_hook(mlx, ft_my_keyhook, (void *)player);
	mlx_loop_hook(mlx, ft_hook, player);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}


































	// printf("%s\n", player->NO);
	// printf("%s\n", player->SO);
	// printf("%s\n", player->WE);
	// printf("%s\n", player->EA);
	// printf("%d\n", player->F[0]);
	// printf("%d\n", player->F[1]);
	// printf("%d\n", player->F[2]);
	// printf("%d\n", player->C[0]);
	// printf("%d\n", player->C[1]);
	// printf("%d\n", player->C[2]);