/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:02:44 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:09:59 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	u;

	u = n;
	if (n < 0)
	{
		u = -n;
		ft_putchar_fd ('-', fd);
	}
	if (u / 10)
		ft_putnbr_fd (u / 10, fd);
	ft_putchar_fd (u % 10 + '0', fd);
}
