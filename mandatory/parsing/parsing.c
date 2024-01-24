/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:33:54 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/24 05:05:16 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"


int parsing(char **map, int file, t_cub3d *player)
{
    int i;
    char **fsl;

    i = 0;
    i = 0;
    fsl = malloc(sizeof(char *) * (6 + 1));
    if(!fsl)
    {
        write(2, "Error: Malloc failed\n", 22);
        exit(1);
    }
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
