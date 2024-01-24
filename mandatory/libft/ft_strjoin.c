/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:57:46 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/04 00:03:03 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*t;
	char	*tm;
	size_t	s1l;
	size_t	s2l;

	if (!s1 || !s2)
		return (0);
	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	t = malloc(s1l + s2l + 1);
	if (!t)
		return (0);
	tm = t;
	while (s1l--)
		*tm++ = *s1++;
	while (s2l--)
		*tm++ = *s2++;
	*tm = '\0';
	return (t);
}
