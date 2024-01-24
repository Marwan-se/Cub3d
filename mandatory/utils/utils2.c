/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:14 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/24 05:04:54 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../raycasting/cub3d.h"

char	*ft_substr2(char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		exit(1);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

size_t	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	if(!s)
		return (0);
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
char	*ft_strchr1(char *s, int i)
{
	while (*s)
	{
		if (*s == i)
			return ((char *)s);
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strchr2(char *s, int i)
{
	while (*s)
	{
		if (*s == i)
		{
			while (*s == i)
				s++;
			return ((char *)s);
		}
		s++;
	}
	if (i == '\0')
		return ((char *)s);
	return (0);
}

char	*ft_strdup2(char *s)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = ft_strlen2(s);
	if(s == NULL)
		return (NULL);
	str = (char *)malloc(sizeof(*str) * (j + 1));
	if (!str)
		exit(1);
	while (i < j)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

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



int ft_atoi2(const char *str)
{
    int x;
    int sign;
    int res;

	x = 0;
	sign = 1;
	res = 0;
    while (str[x] == ' ' || (str[x] >= '\t' && str[x] <= '\r'))
        x++;
    if (str[x] == '-')
    {
        sign = -1;
        x++;
    }
    else if (str[x] == '+')
        x++;
    while (str[x] >= '0' && str[x] <= '9')
    {
        if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[x] - '0') > INT_MAX % 10))
        {
            if (sign == -1)
                return INT_MIN;
            else
                return INT_MAX;
        }
        res = res * 10 + (str[x] - '0');
        x++;
    }
    return res * sign;
}