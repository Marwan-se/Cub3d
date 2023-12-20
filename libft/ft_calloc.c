/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:09:43 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/05 22:24:03 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*t;

	t = 0;
	if (count >= SIZE_MAX || size >= SIZE_MAX)
		return (0);
	t = malloc(count * size);
	if (!t)
		return (0);
	ft_bzero(t, count * size);
	return (t);
}
