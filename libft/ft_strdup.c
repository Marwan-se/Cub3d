/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:58:38 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/04 00:02:15 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t			l;
	char			*t;
	char			*tm;

	l = ft_strlen(src);
	t = malloc(l + 1);
	tm = t;
	if (!t)
		return (0);
	while (*src)
		*t++ = *src++;
	*t = '\0';
	return (tm);
}
