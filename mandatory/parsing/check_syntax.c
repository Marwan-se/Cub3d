/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_syntax.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:26:51 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/21 17:43:29 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_syntax(char *file, int ac)
{
	int	i;

	i = 0;
	if(ac != 2)
		ft_putstr_fd("Error: Wrong number of arguments\n", 2);
	while(file[i])
	{
		if(file[i] == '.')
		{
			if(file[i + 1] == 'c' && file[i + 2] == 'u' && file[i + 3] == 'b' && file[i + 4] == '\0')
				return ;
		}
		i++;
	}
	write(2, "Error: Wrong file extension\n", 28);
	exit(1);
}
