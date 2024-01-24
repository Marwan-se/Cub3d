/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 14:02:44 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/10/13 16:33:56 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
