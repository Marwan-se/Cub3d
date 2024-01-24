/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:40:03 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:10:08 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*sn;
	size_t			i;
	size_t			ls;

	if (!f || !s)
		return (0);
	ls = ft_strlen(s);
	sn = malloc(ls + 1);
	if (!sn)
		return (0);
	i = 0;
	while (*s)
	{
		*(sn + i) = f(i, *s);
		s++;
		i++;
	}
	*(sn + i) = '\0';
	return (sn);
}
/*int main (void)
{
	char S[] = "abcd";
	//char (*pf) (unsigned int, char) = f;
	printf("%s",ft_strmapi(S,f));
}*/