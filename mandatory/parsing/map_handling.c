/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:30:12 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/17 01:00:54 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int check_xpm(char **fsl)
// {
// 	int i;
// 	int j;
// 	char *s;
// 	int fd;

// 	i = 0;
// 	j = 0;
// 	fd = open(fsl[i], O_RDWR);
// 	s = ft_strchr(fsl[i], ' ');
// 	while (fsl[i])
// 	{
// 		if (!ft_strchr(fsl[i], ','))
// 		{
// 			if (s[j] == ' ')
// 			{
// 				while (s[j] == ' ')
// 					++s;
// 			}
// 			if (fd == -1 || strcmp(strrchr(s, '.'), ".png") != 0)
// 			{
// 				close(fd);
// 				return (1);
// 			}
// 			close(fd);
// 		}
// 		i++;
// 	}
// 	return (0);
// }



int	check_dupfsl(char **fsl)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (fsl[i])
	{
		count = i + 1;
		while (fsl[count])
		{
			if (ft_strncmp(fsl[i], fsl[count], ft_strlen(fsl[i])) == 0)
				return (1);
			count++;
		}
		i++;
	}
	return (0);
}


int check_empty_line(char **map, int map_size)
{
    int i = 0;
    while (i < map_size)
	{
        int empty_line = 1;
        int j = 0;
        while (map[i][j] != '\0')
		{
            if (map[i][j] != ' ')
			{
                empty_line = 0;
                break;
            }
            j++;
        }
        if (empty_line) {
            return 1;
        }
        i++;
    }
    return 0;
}
int	invalid_map_char(char **map, int i, int j)
{
	if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != 'N' && \
		map[i][j] != 'S' && map[i][j] != 'E' && \
		map[i][j] != 'W' && map[i][j] != ' ' )
		return (1);
	if (check_empty_line(map, i))
		return (1);
	return (0);
}

int	check_player(char **map, char *player)
{
	int	i;
	int	counter;
	int	rst;

	i = 6;
	rst = 0;
	while(map[i])
	{
		counter = 0;
		while(map[i][counter])
		{
			if(invalid_map_char(map, i, counter) )
			{
				write(2, "Error: Invalid map character\n", 29);
				exit(1);
			}
			if (map[i][counter] == 'N' || map[i][counter] == 'S' \
				|| map[i][counter] == 'E' || map[i][counter] == 'W')
			{
				*player = map[i][counter];
				rst++;
			}
			counter++;
		}
		i++;
	}
	if (rst != 1)
	{
		write(2, "Error: Player is not in the map\n", 32);
		exit(1);
	}
	return (0);
}

void	free_2darray(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}



int	check_fcc(char **fsl)
{
	int i;
	int j;
	int index;
	char **var;
	char *str;

	i = 0;
	j = 0;
	index = 0;
	while (fsl[i])
	{
		if(ft_strchr(fsl[i], ','))
		{
			str = ft_strchr(fsl[i], ' ');
			++str;
			if (fc_space(str, &index))
			{
				return (1);
			}
			if (index != 2)
				return (1);
			index = 0;
			var = ft_split(str, ',');
			j = 0;
			while (var[j])
			{
				if (ft_atoi(var[j]) < 0 || ft_atoi(var[j]) > 255)
					return (1);
				j++;
			}
			if (j != 3)
				return (1);
			free_2darray(var);
		}
		i++;
	}
	return (0);
}

int fc_space(char *s, int *k)
{
	int i = 0;

	while (s[i] == 32)
		i++;
	while (s[i] != 32 && s[i])
	{
		if (s[i] != 44 && (!(s[i] >= 48 && s[i] <= 57)))
			return (1);
		if (s[i] == 44)
			(*k)++;
		i++;
	}
	if (s[i] == 32)
		return (1);
	return (0);
}

int	map_isclosed(char **map, int i, char c, char p)
{
	int	k;
	int	j;

	k = 0;
	while (map[k])
		k++;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][0] == c || (map[6][j] != '1' && map[6][j] != ' ' && i == 6) \
				|| (map[k - 1][j] != '1' && map[k - 1][j] != ' ' && i == k - 1))
				return (1);
			if (map[i][j] == c && i != 6 && i != k - 1)
			{
				if (map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != p)
					return (1);
				if (map[i][j - 1] != '1' && map[i][j - 1] != '0' \
					&& map[i][j - 1] != p)
					return (1);
				if (map[i + 1][j] != '1' && map[i + 1][j] != '0' \
					&& map[i + 1][j] != p)
					return (1);
				if (map[i - 1][j] != '1' && map[i - 1][j] != '0' \
					&& map[i - 1][j] != p)
					return (1);
			}
		}
	}
	return (0);
}




int map_handling(char **fsl, char **map, int file)
{
	int i;
	char player;
	(void)file;

	i = 0;
	
	while (fsl[i] != NULL)
	{
		if(check_fsl(fsl[i]))
		{
			write(2, "Error: in elements\n", 19);
			exit(1);		
		}
		i++;
	}
	// if (check_texture(fsl))
	// {
	// 	write(2, "Error: in texture\n", 19);
	// 	return(1);
	// }
	if (check_fcc(fsl))
	{
		write(2, "Error: in RGB\n", 14);
		exit(1);
	}
	else if(check_dupfsl(fsl))
	{
		write(2, "Error: Duplicate elements\n", 26);
		exit(1);
	}
	else if(check_player(map, &player))
		exit(1);
	else if (map_isclosed(map, 5, '0', player))
	{
		printf("map is not closed1\n");
		exit(1);
	}
	else if (map_isclosed(map, 5, player, '0'))
	{
		printf("map is not closed2\n");
		exit(1);
	}
	return(0);
}