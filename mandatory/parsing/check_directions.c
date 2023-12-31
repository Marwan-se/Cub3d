/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_directions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:26:42 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/30 17:17:40 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_fsl(char *str)
{
    if ((ft_strncmp(str, "NO ", 3)) == 0)
        return(0);
    else if ((ft_strncmp(str, "SO ", 3)) == 0)
        return(0);
    else if ((ft_strncmp(str, "WE ", 3)) == 0)
        return(0);
    else if ((ft_strncmp(str, "EA ", 3)) == 0)
        return(0);
    else if ((ft_strncmp(str, "F ", 2)) == 0)
        return(0);
    else if ((ft_strncmp(str, "C ", 2)) == 0)
        return(0);
    else
        return(1);
}
