/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:33:54 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/26 01:52:11 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

int	parsing(char **map, int file, t_cub3d *player)
{
	int		i;
	char	**fsl;

	i = 0;
	i = 0;
	fsl = malloc(sizeof(char *) * (6 + 1));
	if (!fsl)
		ft_putstr_fd("Error: Malloc failed\n", 2);
	while (map[i] && i < 6)
	{
		fsl[i] = ft_strdup2(map[i]);
		i++;
	}
	fsl[i] = NULL;
	map_handling(fsl, map, file, player);
	free_2darray(fsl);
	return (0);
}

void	init_texture(t_cub3d *p, mlx_image_t **img)
{
	p->txt[0] = mlx_load_png(p->ea);
	p->txt[1] = mlx_load_png(p->we);
	p->txt[2] = mlx_load_png(p->no);
	p->txt[3] = mlx_load_png(p->so);
	if (!p->txt[0] || !p->txt[1] || !p->txt[2] || !p->txt[3])
		return (ft_putstr_fd("Error: Invalid texture\n", 2));
	img[0] = mlx_texture_to_image(p->mlx, p->txt[0]);
	img[1] = mlx_texture_to_image(p->mlx, p->txt[1]);
	img[2] = mlx_texture_to_image(p->mlx, p->txt[2]);
	img[3] = mlx_texture_to_image(p->mlx, p->txt[3]);
	if (!img[0] || !img[1] || !img[2] || !img[3])
		return (perror("allocation failed"), exit(0));
	mlx_resize_image(img[0], TEXTURE_HIGHT, TEXTURE_HIGHT);
	mlx_resize_image(img[1], TEXTURE_HIGHT, TEXTURE_HIGHT);
	mlx_resize_image(img[2], TEXTURE_HIGHT, TEXTURE_HIGHT);
	mlx_resize_image(img[3], TEXTURE_HIGHT, TEXTURE_HIGHT);
	p->tab = malloc (4 * sizeof(uint32_t *));
	p->tab[0] = malloc((TEXTURE_HIGHT * TEXTURE_HIGHT) * 4);
	p->tab[1] = malloc((TEXTURE_HIGHT * TEXTURE_HIGHT) * 4);
	p->tab[2] = malloc((TEXTURE_HIGHT * TEXTURE_HIGHT) * 4);
	p->tab[3] = malloc((TEXTURE_HIGHT * TEXTURE_HIGHT) * 4);
	if (!p->tab[0] || !p->tab[1] || !p->tab[2] || !p->tab[3])
		return (perror("allocation failed"), exit(0));
}

void	norm_mlx_hk(mlx_t *mlx, t_cub3d *player)
{
	mlx_loop_hook(mlx, ft_update, player);
	mlx_loop_hook(mlx, ft_render, player);
	mlx_key_hook(mlx, ft_my_keyhook, (void *)player);
	mlx_loop_hook(mlx, ft_hook, player);
	mlx_loop(mlx);
	mlx_terminate(mlx);
}
