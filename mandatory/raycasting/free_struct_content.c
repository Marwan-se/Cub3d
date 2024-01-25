/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_struct_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 10:30:24 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/25 11:11:34 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

void    free_struct_content(t_cub3d *p)
{
	int	i;

	i = 0;
	free(p->tab);
	while (i < 4)
	{
		free(p->txt[i]);
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
}
