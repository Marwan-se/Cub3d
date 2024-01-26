/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_chk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:26:25 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/26 01:45:20 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

void	fd_error(int fd)
{
	if (fd < 0)
		ft_putstr_fd("Error: File descriptor\n", 2);
}

void	map_error(char **map)
{
	if (!map)
		ft_putstr_fd("Error: Map not found\n", 2);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
