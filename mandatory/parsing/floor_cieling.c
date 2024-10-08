/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_cieling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 22:52:39 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/26 21:45:00 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

int	*store_colors(char **var)
{
	int	j;
	int	*color;

	j = 0;
	color = malloc(sizeof(int) * 3);
	if (!color)
		ft_putstr_fd("Error: Malloc failed\n", 2);
	while (var[j])
	{
		color[j] = ft_atoi2(var[j]);
		if (color[j] < 0 || color[j] > 255)
			ft_putstr_fd("Error: Invalid RGB\n", 2);
		j++;
	}
	if (j != 3)
		ft_putstr_fd("Error: Invalid RGB\n", 2);
	free_2darray(var);
	return (color);
}

uint32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	store_fc(char **fsl, int i, t_cub3d *p, char **var)
{
	int	*color;

	color = store_colors(var);
	if (ft_strchr1(fsl[i], 'F'))
		p->f = ft_pixel(color[0], color[1], color[2], 255);
	if (ft_strchr1(fsl[i], 'C'))
		p->c = ft_pixel(color[0], color[1], color[2], 255);
	free(color);
}

int	check_fcc(char **fsl, t_cub3d *p)
{
	int		i;
	int		index;
	char	**var;
	char	*str;

	i = 0;
	index = 0;
	while (fsl[i])
	{
		if (ft_strchr1(fsl[i], ','))
		{
			str = ft_strchr2(fsl[i], 'F', 'C');
			str++;
			if (fc_space(str, &index))
				return (1);
			if (index != 2)
				return (1);
			index = 0;
			var = ft_split2(str, ',');
			store_fc(fsl, i, p, var);
		}
		i++;
	}
	return (0);
}

int	fc_space(char *s, int *k)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i] == 32)
		i++;
	while (s[i])
	{
		if (s[i] != 44 && (!(s[i] >= 48 && s[i] <= 57)) && s[i] != 32)
			return (1);
		if (s[i] >= 48 && s[i] <= 57)
			n++;
		while ((s[i] >= 48 && s[i] <= 57) && s[i])
			i++;
		if (s[i] == 44)
			(*k)++;
		if (s[i])
			i++;
	}
	if (n != 3)
		return (1);
	return (0);
}
