/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 11:40:03 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/04 00:05:46 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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