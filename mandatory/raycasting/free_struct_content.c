/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:30:24 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/26 02:19:03 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

void	free_struct_content(t_cub3d *p)
{
	int	i;

	free(p->tab[0]);
	free(p->tab[1]);
	free(p->tab[2]);
	free(p->tab[3]);
	free(p->tab);
	i = 0;
	while (i < 4)
	{
		mlx_delete_texture(p->txt[i]);
		i++;
	}
	free(p->no);
	free(p->so);
	free(p->we);
	free(p->ea);
	i = 0;
	while (p->map[i])
	{
		free(p->map[i]);
		i++;
	}
	free(p->tmp_map);
	free(p->p);
}
