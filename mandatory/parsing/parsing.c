/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:31:25 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/19 16:19:16 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_syntax(char *file)
{
	int	i;

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

char	**read_map_file(char *file)
{
	int		fd;
	char	*line;
	char	**map;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		printf("Error: Can't open file\n");
		exit(1);
	}
	while (get_next_line(fd, &line))
	{
		i++;
		free(line);
	}
	close(fd);
	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (get_next_line(fd, &line))
	{
		map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	map[i] = NULL;
	close(fd);
	return (map);
}
