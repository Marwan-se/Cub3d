/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 12:14:18 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/04 00:02:44 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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