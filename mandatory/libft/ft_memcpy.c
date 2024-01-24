/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 20:22:53 by mlahlafi          #+#    #+#             */
/*   Updated: 2022/11/07 22:52:02 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*tmp1;
	char			*tmp2;
	size_t			i;

	i = 0;
	if (!dst && !src)
		return (dst);
	tmp1 = (char *)dst;
	tmp2 = (char *)src;
	while (i < n)
	{
		*tmp1++ = *tmp2++;
		i++;
	}
	return (dst);
}

/*int main(void)
{
char str[100] = "Learningisfun";
    char *first, *second;
    first = str;
    second = str;
    //printf("Original string :%s\n ", str);
      
    // when overlap happens then it just ignore it
    memmove(first + 8, first, 10);
    printf("memcpy overlap : %s\n ", str);
  
    // when overlap it start from first position
    //memmove(second + 8, first, 10);
    //printf("memmove overlap : %s\n ", str);
  
    return 0;
}*/