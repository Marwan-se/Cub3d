/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:26:42 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/24 05:05:10 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"


char	*store_path(char *str)
{
	int		i;
	char	*path;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (path = ft_substr2(str, i, ft_strlen2(str) - i));
}

int	rpath(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (i == ft_strlen2(str))
		ft_putstr_fd("Error: Invalid texture\n", 2);
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (i < ft_strlen2(str))
		ft_putstr_fd("Error: Invalid texture\n", 2);
	return (1);
}

int	check_fsl_norm(char *str, t_cub3d *p, int i)
{
	if ((ft_strncmp2(str + i, "WE ", 3)) == 0 && rpath(str + i + 2))
	{
		p->WE = store_path(str + i + 2);
		return (0);
	}
	else if ((ft_strncmp2(str + i, "EA ", 3)) == 0 && rpath(str + i + 2))
	{
		p->EA = store_path(str + i + 2);
		return (0);
	}
	return (1);
}

int	check_fsl(char *str, t_cub3d *p)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if ((ft_strncmp2(str + i, "NO ", 3)) == 0 && rpath(str + i + 2))
	{
		p->NO = store_path(str + i + 2);
		return (0);
	}
	else if ((ft_strncmp2(str + i, "SO ", 3)) == 0 && rpath(str + i + 2))
	{
		p->SO = store_path(str + i + 2);
		return (0);
	}
	else if (check_fsl_norm(str, p, i) == 0)
		return (0);
	else if ((ft_strncmp2(str + i, "F ", 2)) == 0)
		return (0);
	else if ((ft_strncmp2(str + i, "C ", 2)) == 0)
		return (0);
	return (1);
}
