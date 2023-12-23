/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:23 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/20 13:24:22 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

int main(int ac, char **av)
{
	char **map;

	if(ac != 2)
	{
		printf("Error: Wrong number of arguments\n");
		exit(1);
	}
	check_map_syntax(av[1]);
	map = read_map_file(av[1]);
	if(!map)
	{
		printf("Error: Can't read file\n");
		exit(1);
	}	
}
