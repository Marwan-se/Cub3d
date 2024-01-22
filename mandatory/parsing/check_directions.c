/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:26:42 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/22 02:54:22 by msekhsou         ###   ########.fr       */
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
	// printf("str = %s\n", str);
	
}

// int ends_with_png(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//         i++;
//     while (str[i] == ' ' || str[i] == '\t')
//         i--;
//     if (str[i - 1] == 'g' && str[i - 2] == 'n' && str[i - 3] == 'p' && str[i - 4] == '.')
//         return (1);
//     return (0);
// }

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
    else if ((ft_strncmp(str + i, "WE", 2)) == 0 && rpath(str + i + 2))
	{
        p->WE = store_path(str + i + 2);
        return(0);
	}
    else if ((ft_strncmp(str + i, "EA", 2)) == 0 && rpath(str + i + 2))
	{
        p->EA = store_path(str + i + 2);
        return(0);
	}
    else if ((ft_strncmp(str + i, "F", 1)) == 0)
        return(0);
    else if ((ft_strncmp(str + i, "C", 1)) == 0)
        return(0);
    return(1);
}

// int check_fsl(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i] == ' ' || str[i] == '\t')
// 		i++;
// 	if ((ft_strncmp(str, "NO", 2)) == 0)
// 		return(0);
// 	else if ((ft_strncmp(str, "SO", 2)) == 0)
// 		return(0);
// 	else if ((ft_strncmp(str, "WE", 2)) == 0)
// 		return(0);
// 	else if ((ft_strncmp(str, "EA", 2)) == 0)
// 		return(0);
// 	else if ((ft_strncmp(str, "F", 1)) == 0)
// 		return(0);
// 	else if ((ft_strncmp(str, "C", 1)) == 0)
// 		return(0);
// 	else
// 		return(1);
// }

// int check_fsl(char *str)
// {
//     int i = 0;
//     while (str[i] == ' ' || str[i] == '\t')
//         i++;
//     if ((ft_strncmp(str + i, "NO", 2)) == 0)
//     {
//         i += 2;
//         while (str[i] == ' ' || str[i] == '\t')
//             i++;
//         if (str[i])
//             return (1);
//     }
//     else if ((ft_strncmp(str + i, "SO", 2)) == 0)
//     {
//         i += 2;
//         while (str[i] == ' ' || str[i] == '\t')
//             i++;
//         if (str[i])
//             return (1);
//     }
//     else if ((ft_strncmp(str + i, "WE", 2)) == 0)
//     {
//         i += 2;
//         while (str[i] == ' ' || str[i] == '\t')
//             i++;
//         if (str[i])
//             return (1);
//     }
//     else if ((ft_strncmp(str + i, "EA", 2)) == 0)
//     {
//         i += 2;
//         while (str[i] == ' ' || str[i] == '\t')
//             i++;
//         if (str[i])
//             return (1);
//     }
//     else if ((ft_strncmp(str + i, "F", 1)) == 0)
//     {
//         i += 1;
//         while (str[i] == ' ' || str[i] == '\t')
//             i++;
//         if (str[i])
//             return (1);
//     }
//     else if ((ft_strncmp(str + i, "C", 1)) == 0)
//     {
//         i += 1;
//         while (str[i] == ' ' || str[i] == '\t')
//             i++;
//         if (str[i])
//             return (1);
//     }
//     else
//         return (1);
//     return (0);
// }