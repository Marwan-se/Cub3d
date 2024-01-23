/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:23 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/22 23:52:34 by msekhsou         ###   ########.fr       */
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

// void	ft_setup(void *param)
// {
// 	t_cub3d		*cub;
// 	mlx_image_t	*img[4];

// 	// cub->map = ft_read_map(file);
// 	// printf("#########################");
// 	// if (!cub->map)
// 	// 	exit(0);
// 	// printf("hello world \n");
// 	cub = param;
// 	cub->p.width = 1;
// 	cub->p.height = 1;
// 	cub->p.turnDirection = 0;
// 	cub->p.walkDirection = 0;
// 	cub->p.turnDirection2 = 0;
// 	// cub->p.rotationAngle = M_PI / 2;
// 	cub->p.walkSpeed = 250;
// 	cub->p.turnSpeed = 10 * (M_PI / 180);
// 	cub->texture[0] = mlx_load_png(cub->WE);
// 	cub->texture[1] = mlx_load_png(cub->EA);
// 	cub->texture[2] = mlx_load_png(cub->SO);
// 	cub->texture[3] = mlx_load_png(cub->NO);
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

int main(int ac, char **av)
{
    t_cub3d *player;
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
	player->map = full_map(player->map);
    replace_spaces_with_2(player->map);
	int i = 0;
	while (player->map[i])
	{
		printf("%s\n", player->map[i]);
		i++;
	}
	// printf("%f\n", player->p->x);
	// printf("%f\n", player->p->y);
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