/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:30:12 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/22 02:40:18 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"



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
        if (empty_line)
            return 1;
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

void	store_directions(t_Player *p, char c)
{
	if (c == 'N')
		p->rotationAngle = 3 * M_PI / 2;
	else if (c == 'S')
		p->rotationAngle = M_PI / 2;
	else if (c == 'E')
		p->rotationAngle = 0;
	else if (c == 'W')
		p->rotationAngle = M_PI;
}

// void process_map_character(char **map, int row, int col, t_cub3d *player, char *tmp, int *rst)
// {
// 	if (invalid_map_char(map, row, col))
// 	{
// 		ft_putstr_fd("Error: Invalid map\n", 2);
// 		return;
// 	}
// 	if (map[row][col] == 'N' || map[row][col] == 'S' || map[row][col] == 'E' || map[row][col] == 'W')
// 	{
// 		*tmp = map[row][col];
// 		player->p->y = row * TILE_SIZE / 2;
// 		player->p->x = col * TILE_SIZE / 2;
// 		store_directions(player->p, map[row][col]);
// 		(*rst)++;
// 	}
// }

// int check_player(char **map, t_cub3d *player, char *tmp)
// {
// 	int i;
// 	int counter;
// 	int rst;

// 	i = 6;
// 	rst = 0;
// 	player->p = malloc(sizeof(t_Player));
// 	if (!player->p)
// 		ft_putstr_fd("Error: Malloc failed\n", 2);
// 	while (map[i])
// 	{
// 		counter = 0;
// 		while (map[i][counter])
// 		{
// 			process_map_character(map, i, counter, player, tmp, &rst);
// 			counter++;
// 		}
// 		i++;
// 	}
// 	if (rst != 1)
// 		ft_putstr_fd("Error: Invalid map\n", 2);
// 	return 0;
// }

int	check_player(char **map, t_cub3d *player, char *tmp)
{
	int	i;
	int	counter;
	int	rst;
	
	i = 6;
	rst = 0;
	player->p = malloc(sizeof(t_Player));
	if(!player->p)
		ft_putstr_fd("Error: Malloc failed\n", 2);
	while(map[i])
	{
		counter = 0;
		while(map[i][counter])
		{
			if(invalid_map_char(map, i, counter) )
				ft_putstr_fd("Error: Invalid map\n", 2);
			if (map[i][counter] == 'N' || map[i][counter] == 'S' \
				|| map[i][counter] == 'E' || map[i][counter] == 'W')
			{
				*tmp = map[i][counter];
				player->p->y = i * TILE_SIZE / 2;
				player->p->x = counter * TILE_SIZE / 2;
				store_directions(player->p, map[i][counter]);
				rst++;
			}
			counter++;
		}
		i++;
	}
	if (rst != 1)
		ft_putstr_fd("Error: Invalid map\n", 2);
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

int	*store_colors(char **var)
{
	int j;
	int *color;
	j = 0;
	color = malloc(sizeof(int) * 3);
	while (var[j])
	{
		color[j] = ft_atoi(var[j]);
		if (color[j] < 0 || color[j] > 255)
		{
			write(2, "Error: Invalid RGB\n", 19);
			exit(1);
		}
		j++;
	}
	if (j != 3)
	{
		write(2, "Error: Invalid RGB\n", 19);
		exit(1);
	}
	free_2darray(var);
	return (color);
}
void	store_fc(char **fsl, int i, t_cub3d *p, char **var)
{
	if (ft_strncmp(fsl[i], "F", 1) == 0)
		p->F = store_colors(var);
	else if (ft_strncmp(fsl[i], "C", 1) == 0)
		p->C = store_colors(var);
}

int	check_fcc(char **fsl, t_cub3d *p)
{
	int i;
	int index;
	char **var;
	char *str;

	i = 0;
	index = 0;
	while (fsl[i])
	{
		if(ft_strchr(fsl[i], ','))
		{
			str = ft_strchr(fsl[i], ' ');
			++str;
			if (fc_space(str, &index))
				return (1);
			if (index != 2)
				return (1);
			index = 0;
			var = ft_split(str, ',');
			store_fc(fsl, i, p, var);
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

void	check_limits(char **map, int i, int k)
{
	int j;
	
	j = 0;
	(void)i;
	while (map[6][j] != '\0')
	{
		if ((map[6][j] != '1' && map[6][j] != ' '))
		{
			write(2, "Error: Map is not closed\n", 25);
			exit(1);
		}
		j++;
	}
	j = 0;
	while (map[k - 1][j])
	{
		if((map[k - 1][j] != '1' && map[k - 1][j] != ' '))
		{
			write(2, "Error: Map is not closed\n", 25);
			exit(1);
		}
		j++;
	}
}
int is_surrounded(char **map, int i, int j, char p, int k)
{
    if (map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != p)
        return 1;
    if (map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != p)
        return 1;
    if (i + 1 != k - 1 && map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i + 1][j] != p)
        return 1;
    if (map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i - 1][j] != p)
        return 1;
    return 0;
}

int check_if_map_closed(char **map, int i, char c, char p)
{
    int k;
    int j;

    k = 0;
    while (map[k])
        k++;
    check_limits(map, i, k);
    while (map[++i])
    {
        j = -1;
        while (map[i][++j])
        {
            if (map[i][j] == c && i != 6 && i != k - 1)
            {
                if (is_surrounded(map, i, j, p, k))
                    return (1);
            }
        }
    }
    return (0);
}

// void	get_textures(char **fsl, t_cub3d *p)
// {
// 	int i;
// 	char *str;

// 	i = 0;
// 	while (fsl[i])
// 	{
// 		if(ft_strncmp(fsl[i], "NO", 2) == 0)
// 		{
// 			str = ft_strchr(fsl[i], ' ');
// 			++str;
// 			p->NO = ft_strdup(str);
// 		}
// 		else if(ft_strncmp(fsl[i], "SO", 2) == 0)
// 		{
// 			str = ft_strchr(fsl[i], ' ');
// 			++str;
// 			p->SO = ft_strdup(str);
// 		}
// 		else if(ft_strncmp(fsl[i], "WE", 2) == 0)
// 		{
// 			str = ft_strchr(fsl[i], ' ');
// 			++str;
// 			p->WE = ft_strdup(str);
// 		}
// 		else if(ft_strncmp(fsl[i], "EA", 2) == 0)
// 		{
// 			str = ft_strchr(fsl[i], ' ');
// 			++str;
// 			p->EA = ft_strdup(str);
// 		}
// 		i++;
// 	}
// }


// int ends_with_png(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//         i++;
//     while (str[i] == ' ' || str[i] == '\t')
//         i--;
    
//         return (1);
// 	else
// 		ft_putstr_fd("Error: Invalid texture\n", 2);
//     return (0);
// }

// int	check_texture(char *str)
// {
// 	int i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	while (str[i] == ' ' || str[i] == '\t')
// 		i--;
// 	if (str[i - 1] == 'g' && str[i - 2] == 'n' && str[i - 3] == 'p' && str[i - 4] == '.')
// 		return (1);
// 	else
// 		ft_putstr_fd("Error: Invalid texture\n", 2);
// 	return (0);
// }

// int	get_texture(char **fsl, t_cub3d *p)
// {
// 	int i;
// 	char *str;

// 	i = 0;
// 	while (fsl[i])
// 	{
// 		if(ft_strncmp(fsl[i], "NO", 2) == 0 && check_texture(fsl[i]))
// 		{
// 			str = ft_strchr2(fsl[i], ' ');
// 			p->NO = ft_strdup(str);
// 		}
// 		else if(ft_strncmp(fsl[i], "SO", 2) == 0 && check_texture(fsl[i]))
// 		{
// 			str = ft_strchr2(fsl[i], ' ');
// 			p->SO = ft_strdup(str);
// 		}
// 		else if(ft_strncmp(fsl[i], "WE", 2) == 0 && check_texture(fsl[i]))
// 		{
// 			str = ft_strchr2(fsl[i], ' ');
// 			p->WE = ft_strdup(str);
// 		}
// 		else if(ft_strncmp(fsl[i], "EA", 2) == 0 && check_texture(fsl[i]))
// 		{
// 			str = ft_strchr2(fsl[i], ' ');
// 			p->EA = ft_strdup(str);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

int map_handling(char **fsl, char **map, int file, t_cub3d *p)
{
	int i;
	(void)file;
	char tmp;

	i = 0;
	
	while (fsl[i] != NULL)
	{
		if(check_fsl(fsl[i] , p))
			ft_putstr_fd("Error: Invalid element\n", 2);
		i++;
	}
	if (check_fcc(fsl, p))
		ft_putstr_fd("Error: Invalid RGB\n", 2);
	else if(check_dupfsl(fsl))
		ft_putstr_fd("Error: Duplicate element\n", 2);
	else if(check_player(map, p, &tmp))
		exit(1);
	else if (check_if_map_closed(map, 5, '0', tmp))
		ft_putstr_fd("Error: Map is not closed\n", 2);
	else if (check_if_map_closed(map, 5, tmp, '0'))
		ft_putstr_fd("Error: Map is not closed\n", 2);
	// else if (get_texture(fsl, p))
	// 	ft_putstr_fd("Error: Invalid texture\n", 2);
	return(0);
}	
