/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:26:42 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/22 22:44:42 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*store_path(char *str)
{
    int i;
	char *path;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
	return (path = ft_substr(str, i, ft_strlen(str) - i));
}

int    rpath(char *str)
{
	size_t i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (i == ft_strlen(str))
		ft_putstr_fd("Error: Invalid texture\n", 2);
	while (str[i] && (str[i] != ' ' && str[i] != '\t'))
		i++;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (i < ft_strlen(str))
		ft_putstr_fd("Error: Invalid texture\n", 2);
	return (1);
}

int	check_fsl_norm(char *str, t_cub3d *p, int i)
{
	if ((ft_strncmp(str + i, "WE", 2)) == 0 && rpath(str + i + 2))
	{
        p->WE = store_path(str + i + 2);
        return(0);
	}
    else if ((ft_strncmp(str + i, "EA", 2)) == 0 && rpath(str + i + 2))
	{
        p->EA = store_path(str + i + 2);
        return(0);
	}
	return(1);
}

int check_fsl(char *str, t_cub3d *p)
{
    int i;

    i = 0;
    while (str[i] == ' ' || str[i] == '\t')
        i++;
    if ((ft_strncmp(str + i, "NO", 2)) == 0 && rpath(str + i + 2))
	{
        p->NO = store_path(str + i + 2);
        return(0);
	}
    else if ((ft_strncmp(str + i, "SO", 2)) == 0 && rpath(str + i + 2))
	{
        p->SO = store_path(str + i + 2);
        return(0);
	}
	else if (check_fsl_norm(str, p, i) == 0)
		return(0);
    else if ((ft_strncmp(str + i, "F", 1)) == 0)
        return(0);
    else if ((ft_strncmp(str + i, "C", 1)) == 0)
        return(0);
    return(1);
}
