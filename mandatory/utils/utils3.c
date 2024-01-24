/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 06:08:03 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/24 08:01:42 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../raycasting/cub3d.h"

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	j;

	if (s1 == NULL)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	len = ft_strlen2(s1)+ ft_strlen2(s2);
	str = (char *)malloc(len + 1 * sizeof(char));
	if (str == NULL)
		exit(1);
	len = -1;
	while (s1[++len])
		str[len] = s1[len];
	free(s1);
	j = 0;
	while (s2[j])
	{
		str[len++] = s2[j++];
	}
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
