/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:31:25 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/18 17:31:26 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_map_syntax(char *file)
{
    int i;

    i = 0;
    while(file[i])
    {
        if(file[i] == '.')
        {
            if(file[i + 1] == 'c' && file[i + 2] == 'u' && file[i + 3] == 'b' && file[i + 4] == '\0')
                return ;
        }
        i++;
    }
    printf("Error: Wrong file extension\n");
    exit(1);
}

