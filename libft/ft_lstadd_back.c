/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:37:57 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/01 20:02:37 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*int	add(void * a)
{
	return ((* (int *)a)++);
}*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*t;

	if (new)
	{
		t = *lst;
		if (!*lst)
			*lst = new;
		else
		{
			while (t->next)
				t = t->next;
			t->next = new;
		}
	}
}

/*int	main(void)
{
	t_list	*tl;
	t_list	*t;
	int	i = 5;
	int j= 9;
	int (*p)(void *) = add;
	t = ft_lstnew(&j);
	printf("%d\n", *(int *)t->content);
	tl = ft_lstnew(&i);
	ft_lstadd_back(&tl, t);
	printf("%d\n", *(int *)tl->content);
	ft_lstiter(tl,p);
	printf("%d\n", *(int *)tl->content);
	tl = tl->next;
	printf("%d", *(int *)tl->content);
}*/