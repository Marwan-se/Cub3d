/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:19:45 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:09:39 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	ld;
	size_t	ls;
	size_t	tl;

	if (!dstsize)
		return (ft_strlen(src));
	ls = ft_strlen(src);
	ld = ft_strlen(dst);
	tl = ld;
	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	while (dstsize - tl - 1 && *src)
	{
		*(dst + tl) = *src++;
		*(dst + tl + 1) = '\0';
		tl = ft_strlen(dst);
	}
	return (ls + ld);
}
