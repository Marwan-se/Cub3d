/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:05:31 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/02 00:37:44 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*s;

	if (lst && del)
	{
		while (*lst)
		{
			del((*lst)->content);
			s = *lst;
			*lst = (*lst)->next;
			free(s);
		}
	}
}
