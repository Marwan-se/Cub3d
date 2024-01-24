/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 21:27:29 by mlahlafi          #+#    #+#             */
/*   Updated: 2024/01/24 10:09:05 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (dst == src)
		return (dst);
	if (!src && !dst)
		return (dst);
	if (dst < src)
	{
		while (i < len)
		{
			*(char *)(dst + i) = *(char *)(src + i);
			i++;
		}
	}
	i = len;
	if (dst > src)
	{
		while (i)
		{
			*(char *)(dst + i - 1) = *(char *)(src + i - 1);
			i--;
		}
	}
	return (dst);
}
/*int main()
{
    char str[100] = "Learningisfun";
    char *first, *second;
    first = str;
    second = str;
    printf("Original string :%s\n ", str);
      
    // when overlap happens then it just ignore it
	ft_memcpy(first + 8, first, 10);
	printf("memcpy overlap : %s\n ", str);
  
    // when overlap it start from first position
    //ft_memmove(second + 8, first, 10);
    //printf("memmove overlap : %s\n ", str);
  
    return 0;
}*/
