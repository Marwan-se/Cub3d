/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:55:57 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/04 00:08:21 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) != '\0' && *(s2 + i) != '\0' && i < n)
	{
		if (*(s1 + i) == *(s2 + i))
			i++;
		else
			return ((unsigned char) *(s1 + i) - (unsigned char) *(s2 + i));
	}
	if (i >= n)
		return (0);
	return ((unsigned char) *(s1 + i) - (unsigned char) *(s2 + i));
}
