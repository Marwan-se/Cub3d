/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:08:04 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:09:00 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	size_t			l;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	i = 0;
	l = n;
	tmp1 = (unsigned char *) s1;
	tmp2 = (unsigned char *) s2;
	if (!n)
		return (0);
	while (i < l)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		tmp1++;
		tmp2++;
		i++;
	}
	return (0);
}
