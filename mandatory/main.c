/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:31:20 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/19 16:28:16 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{

    if(ac != 2)
    {
        printf("Error: Wrong number of arguments\n");
        exit(1);
    }
    check_map_syntax(av[1]);
    read_map_file(av[1]);
    while(read_map_file(av[1]))
    {
        printf("%s\n", *read_map_file(av[1]));
        
    }
}