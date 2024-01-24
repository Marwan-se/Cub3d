/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:26:51 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/24 05:26:50 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

void	check_syntax(char *file, int ac)
{
	int	i;

	i = 0;
	if (ac != 2)
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
	while (file[i])
	{
		if (file[i] == '.')
		{
			if (file[i + 1] == 'c' && file[i + 2] == 'u' && \
				file[i + 3] == 'b' && file[i + 4] == '\0')
				return ;
		}
		i++;
	}
	write(2, "Error: Wrong file extension\n", 28);
	exit(1);
}

int	check_empty_line(char **map, int map_size)
{
	int	i;
	int	j;
	int	empty_line;

	i = 0;
	while (i < map_size)
	{
		empty_line = 1;
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != ' ')
			{
				empty_line = 0;
				break ;
			}
			j++;
		}
		if (empty_line)
			return (1);
		i++;
	}
	return (0);
}

int	duplicate_elemnts_checker(char **fsl)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (fsl[i])
	{
		count = i + 1;
		while (fsl[count])
		{
			if (ft_strncmp2(fsl[i], fsl[count], ft_strlen2(fsl[i])) == 0)
				return (1);
			count++;
		}
		i++;
	}
	return (0);
}
