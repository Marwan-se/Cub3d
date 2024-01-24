/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:14:18 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:09:27 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	i = 0;
	if (s && f)
	{
		while (*(s + i))
		{
			f(i, s + i);
			i++;
		}
	}
}
/*int main (void)
{
	char S[] = "abcd";
	//char (*pf) (unsigned int, char) = f;
	ft_striteri(S, f);
	printf("%s",S);
}*/