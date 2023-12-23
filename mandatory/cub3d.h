/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:19 by msekhsou          #+#    #+#             */
/*   Updated: 2023/12/20 12:07:21 by msekhsou         ###   ########.fr       */
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
char	*get_next_line(int fd, char **line);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	**read_map_file(char *file);
void	parse(char *file);
int	ft_strncmp(char *s1, char *s2, size_t n);
int	check_ffl(char *file);




#endif