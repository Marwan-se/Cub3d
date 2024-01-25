/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:23 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/25 07:39:41 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting/cub3d.h"

void	ft_setup(void *param)
{
	t_cub3d			*p;
	mlx_image_t		*img[4];
	int				j;
	unsigned int	i;
	int				k;

	p = param;
	init_texture(p, img);
	i = 0;
	j = 0;
	k = 0;
	while (k < 4)
	{
		while (i < img[k]->height * img[k]->width)
		{
			p->tab[k][i] = ft_pixel(img[k]->pixels[j], img[k]->pixels[j + 1], \
				img[k]->pixels[j + 2], img[k]->pixels[j + 3]);
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
	t_cub3d		*cub;
	uint32_t	tile_color;

	tile_color = 0;
	cub = param;
	// ft_renederRays(param);
	ft_generate_projection(cub, tile_color);
	ft_render_map(cub);
	ft_render_player(cub);
}

void	init_mlx_norm(mlx_t **mlx, mlx_image_t **image)
{
	*mlx = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "MLX42", true);
	if (!(*mlx))
	{
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	*image = mlx_new_image(*mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!(*image))
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
	ft_memset((*image)->pixels, 128, \
		(*image)->width * (*image)->height * sizeof(int32_t));
	if (mlx_image_to_window(*mlx, *image, 0, 0) == -1)
	{
		mlx_close_window(*mlx);
		puts(mlx_strerror(mlx_errno));
		exit(EXIT_FAILURE);
	}
}

void	ft()
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_cub3d		*player;
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			fd;

	atexit(ft);
	player = malloc(sizeof(t_cub3d));
	if (!player)
		ft_putstr_fd("Error: Malloc failed\n", 2);
	check_syntax(av[1], ac);
	fd = open(av[1], O_RDONLY);
	fd_error(fd);
	player->map = read_map_file(fd);
	map_error(player->map);
	parsing(player->map, fd, player);
	player->map = full_map(player->map, player);
	replace_spaces_with_2(player->map);
	init_mlx_norm(&mlx, &image);
	player->mlx = mlx;
	player->image = image;
	ft_setup(player);
	norm_mlx_hk(mlx, player);
	close(fd);
	return (EXIT_SUCCESS);
}
