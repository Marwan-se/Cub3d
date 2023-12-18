/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 17:31:11 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/18 17:34:44 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include "mlx.h"

#define BUFFER_SIZE 32

void    check_map_syntax(char *file);
char	**ft_split(char const *s, char c);
char	*ft_substr(char *s, unsigned int start, size_t len);
int	ft_strlen(char *str);
char	*ft_strchr(char *s, int i);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);



#endif