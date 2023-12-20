/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:19:45 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/03 15:46:46 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
