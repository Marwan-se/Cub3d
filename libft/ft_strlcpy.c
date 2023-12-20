/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:12:44 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/04 00:04:44 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize != 0)
	{
		while (*(char *)(src + i) && i < dstsize - 1)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
		*(char *)(dst + i) = '\0';
	}
	return (ft_strlen(src));
}
