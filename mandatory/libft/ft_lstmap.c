/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 13:12:12 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/03 23:36:50 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*void free_all(t_list **lst, void (*del)(void *))
{
	t_list  **tmp;

	tmp = lst;
	while (*lst)
	{
		free((*lst)->content);
		*lst = (*lst)->next;
	}
	ft_lstclear(tmp, del);
}*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*h;
	t_list	*t;

	t = 0;
	h = t;
	if (lst && f && del)
	{
		while (lst)
		{
			t = ft_lstnew(NULL);
			if (!t)
			{
				ft_lstclear(&h, del);
				h = 0;
				break ;
			}
			t->content = f(lst->content);
			ft_lstadd_back(&h, t);
			lst = lst->next;
		}
		return (h);
	}
	return (0);
}

/*int	main(void)
{
	t_list	*a;
	t_list	*b;
	t_list	*c;

	int e = 128;
	a = ft_lstnew(&e);
	b = ft_lstnew("eee");
	c = ft_lstnew("fff");
	ft_lstadd_back(&a, b);
	ft_lstadd_back(&a, c);
	printf("%d\n",*(a->content));
	printf("%d\n",*(b->content));
	printf("%d\n",*(c->content));
}*/
