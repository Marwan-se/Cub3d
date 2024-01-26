/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:08:03 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/26 02:25:53 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

char	*ft_strjoin2(char *src, char *dst)
{
	char	*str;
	size_t	len;
	size_t	j;

	if (src == NULL)
	{
		src = (char *)malloc(1 * sizeof(char));
		src[0] = '\0';
	}
	len = ft_strlen2(src)+ ft_strlen2(dst);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
		exit(1);
	len = 0;
	while (src[len])
	{
		str[len] = src[len];
		len++;
	}
	free(src);
	j = 0;
	while (dst[j])
		str[len++] = dst[j++];
	str[len] = '\0';
	return (str);
}

int	handle_sign(const char *str, int *x, int *sign)
{
	if (str[*x] == '-')
	{
		*sign = -1;
		(*x)++;
	}
	else if (str[*x] == '+')
		(*x)++;
	return (*sign);
}

int	ft_atoi2(const char *str)
{
	int	x;
	int	sign;
	int	res;

	x = 0;
	sign = 1;
	res = 0;
	while (str[x] == ' ' || (str[x] >= '\t' && str[x] <= '\r'))
		x++;
	handle_sign(str, &x, &sign);
	while (str[x] >= '0' && str[x] <= '9')
	{
		if (res > INT_MAX / 10 || (res == INT_MAX / 10 && \
			(str[x] - '0') > INT_MAX % 10))
		{
			if (sign == -1)
				return (INT_MIN);
			else
				return (INT_MAX);
		}
		res = res * 10 + (str[x] - '0');
		x++;
	}
	return (res * sign);
}

int	count_map_lines(char **map)
{
	int	count;

	count = 0;
	while (map[count] != NULL)
		count++;
	return (count);
}
