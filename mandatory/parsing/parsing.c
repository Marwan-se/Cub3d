/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:33:54 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/04 21:07:30 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int parsing(char **map, int file)
{
    int i;
    char **fsl;

    i = 0;
    i = 0;
    fsl = malloc(sizeof(char *) * 6 + 1);
    if(!fsl)
    {
        write(2, "Error: Malloc failed\n", 22);
        exit(1);
    }
    while (map[i] && i < 6)
    {
        fsl[i] = ft_strdup(map[i]);
        i++;
    }
    fsl[i] = NULL;
    map_handling(fsl, map, file);
    return (0);
}
