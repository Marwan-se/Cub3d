/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:30:12 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/03 16:08:28 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_xpm(char **fsl)
{
	int i;
	int j;
	char *s;
	int fd;

	i = 0;
	j = 0;
	fd = open(fsl[i], O_RDWR);
	s = ft_strchr(fsl[i], ' ');
	while (fsl[i])
	{
		if (!strchr(fsl[i], ','))
		{
			if (s[j] == ' ')
			{
				while (s[j] == ' ')
					++s;
			}
			if (fd == -1 || strcmp(strrchr(s, '.'), ".xpm") != 0)
			{
				close(fd);
				return (1);
			}
			close(fd);
		}
		i++;
	}
	return (0);
}

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


// int	check_player(char **map, int i, int *k, char *p)
// {
// 	int	j;

// 	i = 6;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			if (map[i][j] != '1' && map[i][j] != '0' \
// 				&& map[i][j] != 'N' && map[i][j] != 'S' \
// 				&& map[i][j] != 'E' && map[i][j] != 'W' && map[i][j] != ' ')
// 				return (printf("Invalid Character!\n"));
// 			if (map[i][j] == 'N' || map[i][j] == 'S' \
// 				|| map[i][j] == 'E' || map[i][j] == 'W')
// 			{
// 				*p = map[i][j];
// 				(*k)++;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (0);
// }

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
		printf("Error: Player is not in the map\n");
		return (1);
	}
	return (0);
}

int	check_fcc(char **fsl)
{
	int i;
	int j;
	int k;
	char **var;
	char *str;

	i = 0;
	j = 0;
	k = 0;
	while (fsl[i])
	{
		if(ft_strchr(fsl[i], ','))
		{
			str = ft_strchr(fsl[i], ' ');
			++str;
			if (fc_space(str, &k))
				return (1);
			if (k != 2)
				return (1);
			k = 0;
			var = ft_split(str, ',');
			j = 0;
			while (var[j])
			{
				if (atoi(var[j]) > 255 || atoi(var[j]) < 0)
					return (1);
				j++;
			}
			if (j != 3)
				return (1);
		}
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
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

int map_closed(char **map, int i, int j, char player)
{
    if (map[i][j + 1] != '1' && map[i][j + 1] != '0' \
		&& map[i][j + 1] != player)
		return (1);
	if (map[i][j - 1] != '1' && map[i][j - 1] != '0' \
		&& map[i][j - 1] != player)
		return (1);
	if (map[i + 1][j] != '1' && map[i + 1][j] != '0' \
		&& map[i + 1][j] != player)
		return (1);
	if (map[i - 1][j] != '1' && map[i - 1][j] != '0' \
		&& map[i - 1][j] != player)
		return (1);
	else
		return (0);
}

// int	map_isclosed(char **map, int i, char c, char p)
// {
// 	int	k;
// 	int	j;

// 	k = 0;
// 	while (map[k])
// 		k++;
// 	while (map[++i])
// 	{
// 		j = -1;
// 		while (map[i][++j])
// 		{
// 			if (map[i][0] == c || \
// 				(map[6][j] != '1' && map[6][j] != ' ' && i == 6) \
// 				|| (map[k - 1][j] != '1' && map[k - 1][j] != ' ' && i == k - 1))
// 				return (1);
// 			if (map[i][j] == c && i != 6 && i != k - 1)
// 				if (map_closed(map, i, j, p))
// 					return (1);
// 		}
// 	}
// 	return (0);
// }

int	is_the_map_closed(char **map, char mpchr, char player)
{
	int i;
	int j;
	int index;
	
	index = 0;
	while (map[index])
		index++;
	i = 5;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == mpchr)
			{
				if (i == 5 || i == index - 1)
					return (1);
				if (map[i][j + 1] != mpchr && map[i][j + 1] != '1' && map[i][j + 1] != '0' && map[i][j + 1] != player)
					return (1);
				if (map[i][j - 1] != mpchr && map[i][j - 1] != '1' && map[i][j - 1] != '0' && map[i][j - 1] != player)
					return (1);
				if (map[i + 1][j] != mpchr && map[i + 1][j] != '1' && map[i + 1][j] != '0' && map[i + 1][j] != player)
					return (1);
				if (map[i - 1][j] != mpchr && map[i - 1][j] != '1' && map[i - 1][j] != '0' && map[i - 1][j] != player)
					return (1);
			}
			j++;
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
	
	while (fsl[i])
	{
		if(check_fsl(fsl[i++]))
		{
			i++;
			printf("error in the first six line\n");
			return(1);
		}
	}
	// if (check_xpm(fsl))
	// {
	// 	printf("not the right texture\n");
	// 	return(1);
	// }
	if (check_fcc(fsl))
	{
		printf("not the right color\n");
		return(1);
	}
	else if(check_dupfsl(fsl))
	{
		printf("duplicate elements\n");
		return(1);
	}
	else if(check_player(map, &player))
		return(1);
	// else if (map_isclosed(map, 5, '0', player))
	// {
	// 	printf("map is not closed\n");
	// 	return(1);
	// }
	// else if (map_isclosed(map, 5, player, '0'))
	// {
	// 	printf("map is not closed\n");
	// 	return(1);
	// }
	else if (is_the_map_closed(map, '0', player))
	{
		printf("map is not closed\n");
		return(1);
	}
	else if (is_the_map_closed(map, player, '0'))
	{
		printf("map is not closed\n");
		return(1);
	}

	return(0);
}