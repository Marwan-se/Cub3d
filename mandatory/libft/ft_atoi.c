/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 10:16:18 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/03 22:17:34 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_space(char *str)
{
	if (*str == ' ' || *str == '\n' || *str == '\r')
		return (1);
	else if (*str == '\t' || *str == '\f' || *str == '\v')
		return (1);
	else
		return (0);
}

static int	ft_sign(char *str, int *sign)
{
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			*sign *= -1;
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	long		nb;
	int			sign;

	nb = 0;
	sign = 1;
	while (ft_space((char *)str))
		str++;
	if (ft_sign((char *)str, &sign))
		str++;
	while (*str >= 48 && *str <= 57)
	{
		nb = nb * 10 + *str % 48;
		if ((nb * 10) / 10 != nb)
		{
			if (sign == 1)
				return (-1);
			return (0);
		}
		str++;
	}
	return (sign * nb);
}
/*int main(void)
{
	char N[] = "-2121231";
	printf("%d \n",atoi(N));
	printf("%d \n",ft_atoi(N));
}*/