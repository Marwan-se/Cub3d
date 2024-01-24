/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 13:16:09 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/04 00:00:59 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	ft_wordnbr(char *ts, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!ft_strlen(ts))
		return (0);
	while (*ts && *ts == c)
		ts++;
	while (*(ts + j))
	{
		if ((*(ts + j) == c && *(ts + j + 1) != c))
			i++;
		j++;
	}
	if (*(ts + j - 1) != c)
		i++;
	return (i);
}

static int	ft_toc(char c, char const *s)
{
	int	j;

	j = 0;
	while (*s && *s == c)
		s++;
	while (*(s + j) && *(s + j) != c)
		j++;
	return (j);
}

static int	ft_freeall(char **t)
{
	int	i;

	i = 0;
	while (t[i])
	{
		free(t[i]);
		t[i] = 0;
		i++;
	}
	free(t);
	return (1);
}

static int	ft_allocation(char **t, int i, char *s, char c)
{
	int	l;
	int	j;
	int	x;

	x = 0;
	while (i--)
	{
		l = ft_toc(c, s);
		t[x] = malloc(l + 1);
		if (!t[x] && ft_freeall(t))
			return (0);
		j = 0;
		while (l--)
		{
			while (*s && *s == c)
				s++;
			t[x][j] = s[j];
			j++;
		}
		s = s + j + 1;
		t[x][j] = '\0';
		x++;
	}
	t[x] = 0;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**t;
	int		i;

	if (!s)
		return (0);
	i = ft_wordnbr((char *)s, c);
	t = malloc((i + 1) * sizeof(char *));
	if (!t)
		return (0);
	if (!ft_allocation(t, i, (char *) s, c))
		return (NULL);
	return (t);
}

/*int	main(void)
{
	char S[] = "\0";
	char set = '\0';
	char ** t = ft_split(S, set);
	if(!t)
		printf("ohh yees");
	printf("%s", *t);
}*/