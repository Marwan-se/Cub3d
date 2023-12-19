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
	char **map;

	if(ac != 2)
	{
		printf("Error: Wrong number of arguments\n");
		exit(1);
	}
	check_map_syntax(av[1]);
	map = read_map_file(av[1]);
	valid_map(map);
}