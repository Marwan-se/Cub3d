/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:26:51 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/25 17:09:30 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_syntax(char *file, int ac)
{
	int	i;

	i = 0;
	if(ac != 2)
	{
		printf("Error: Wrong number of arguments\n");
		exit(1);
	}
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
