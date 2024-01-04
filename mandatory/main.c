/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:23 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/04 13:53:51 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int main(int ac, char **av)
{
	char **map;
	int fd;

	if (ac != 2)
	{
		printf("Error: Wrong number of arguments\n");
		exit(1);
	}
	check_map_syntax(av[1], ac);
	fd = open(av[1], O_RDONLY);
	map = read_map_file(fd);
	if(!map)
	{
		printf("Error: Map is empty\n");
		exit(1);
	}

	parsing(map, fd);
	
}
