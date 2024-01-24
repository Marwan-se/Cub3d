/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:21:28 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/05 23:01:54 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strcmp1(char *s1, char *set)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (*(s1 + j))
	{
		while (*(set + i))
		{
			if (*(s1 + j) == *(set + i))
				break ;
			i++;
		}
		if (i == ft_strlen(set))
			break ;
		j++;
		i = 0;
	}
	return (j);
}

static int	ft_strcmp2(char *s1, char *set)
{
	int		i;
	int		j;

	s1 = s1 + ft_strlen(s1) - 1;
	i = 0;
	j = 0;
	while (*(s1))
	{
		while (*(set + i))
		{
			if (*(s1) == *(set + i))
				break ;
			i++;
		}
		if (i == (int)ft_strlen(set))
			break ;
		s1--;
		j++;
		i = 0;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char		*trim1;
	size_t		s1len;
	size_t		l1;
	size_t		l2;

	trim1 = 0;
	l1 = 0;
	l2 = 0;
	if (!s1 || !set)
		return (0);
	s1len = ft_strlen(s1);
	l1 = ft_strcmp1((char *)s1, (char *) set);
	if (l1 != s1len)
		l2 = ft_strcmp2((char *)s1, (char *) set);
	trim1 = ft_substr((char *)s1, l1, s1len - l1 - l2);
	if (!trim1)
		return (0);
	return (trim1);
}
