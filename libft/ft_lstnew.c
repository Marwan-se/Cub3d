/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 11:49:54 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/10/19 15:25:02 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = malloc(sizeof(*t));
	if (!t)
		return (0);
	t->content = content;
	t->next = 0;
	return (t);
}
