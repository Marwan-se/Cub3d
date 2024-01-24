/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:48:44 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/04 00:08:48 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	l;
	int		nl;

	nl = ft_strlen(needle);
	if (!nl)
		return ((char *) haystack);
	if (len <= 0)
		return (0);
	l = len - nl + 1;
	while (*haystack && l > 0)
	{
		if (!ft_strncmp(haystack, needle, nl))
		{
			return ((char *)(haystack));
		}
		haystack++;
		l--;
	}
	return (0);
}

/*int	main(void)
{
	char S[20] = "hello world";
	char D[10] = "world";
	printf("%s\n",ft_strnstr('0', D, 3));
	printf("%s",strnstr(S, D, 3));
} */
