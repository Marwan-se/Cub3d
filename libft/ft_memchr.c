/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:44:18 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/01 20:36:08 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n)
	{
		if (*(unsigned char *)s == (unsigned char) c)
			return ((void *)(s));
		s++;
		n--;
	}
	return (0);
}
