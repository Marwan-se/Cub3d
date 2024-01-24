/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:40:02 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:11:25 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_calc(int tn)
{
	int				i;

	i = 0;
	while (tn / 10)
	{
		i++;
		tn /= 10;
	}
	i++;
	if (tn < 0)
		i++;
	return (i);
}

char	*ft_itoa(int n)
{
	char			*s;
	int				tn;
	int				i;
	unsigned int	u;

	u = n;
	i = ft_calc(n);
	tn = 0;
	s = malloc(i + 1);
	if (!s)
		return (0);
	*(s + i) = '\0';
	i--;
	if (n < 0)
	{
		u = -n;
		*s = '-';
		tn = 1;
	}
	while (i >= tn)
	{
		*(s + i--) = u % 10 + '0';
		u /= 10;
	}
	return (s);
}
/*int	main(void)
{
	printf("%s", ft_itoa(-2147483647));
}*/
