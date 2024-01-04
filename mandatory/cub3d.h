/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:19 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/04 21:18:12 by msekhsou         ###   ########.fr       */
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

typedef struct Player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turnDirection;
	int		walkDirection;
	float	rotationAngle;
	float	walkSpeed;
	float	turnSpeed;
} Player;

// typedef struct s_parse
// {
// 	char **map;
// 	char *str;
// 	char *no;
// 	char *so;
// 	char *we;
// 	char *ea;
// 	char **fsl;
// 	// char *s;
	
// } t_parse;

void	check_syntax(char *file, int ac);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(char *s, int i);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd, char **line);
int parsing(char **map, int file);
int	ft_strncmp(char *s1, char *s2, size_t n);
int check_fsl(char *str);
int map_handling(char **fsl, char **map, int file);
int check_space_nd_newline(char **map, char *str);
int check_xpm(char **fsl);
int	check_dupfsl(char **fsl);
int fc_space(char *s, int *k);
size_t	ft_strlcpy(char *dst,  char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, char *src, size_t dstsize);
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *str);
char	**read_map_file(int file);
int map_closed(char **map, int i, int j, char p);



#endif