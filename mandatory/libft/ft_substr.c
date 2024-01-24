/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:43:05 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:11:42 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char					*t;
	size_t					l;
	size_t					i;

	i = 0;
	if (s == 0)
		return (0);
	l = ft_strlen(s);
	if (start >= l)
		len = 0;
	else if (l < len + start)
		len = l - start;
	t = malloc(len + 1);
	if (t == 0)
		return (0);
	while (i < len)
	{
		*(t + i) = *(s + i + start);
		i++;
	}
	*(t + i) = '\0';
	return (t);
}
