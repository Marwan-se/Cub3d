/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 02:33:54 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/30 17:39:59 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int parsing(char **map, int file)
{
    int i;
    char **fsl;

    i = 0;
    if(!map)
    {
        printf("Error: Map is empty\n");
        exit(1);
    }
    i = -1;
    fsl = malloc(sizeof(char *) * 6 + 1);
    if (!fsl)
        exit(1);
    while (map[++i] && i < 6)
        fsl[i] = ft_strdup(map[i]);
    map_handling(fsl, map, file);
    return (0);
}
