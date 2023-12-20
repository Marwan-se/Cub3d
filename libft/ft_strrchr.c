/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 10:33:55 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/04 00:09:26 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*t;
	size_t	l;

	t = 0;
	l = ft_strlen(s);
	if ((char) c == '\0')
		return ((char *) s + l);
	while (*s)
	{
		if (*(char *)s++ == (char) c)
			t = (char *)(s - 1);
	}
	return (t);
}
