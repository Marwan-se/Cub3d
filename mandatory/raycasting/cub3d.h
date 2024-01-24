/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlahlafi <mlahlafi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:19 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/24 04:55:54 by mlahlafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
#define CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#include <math.h>
#include <string.h>
#include "../libft/libft.h"
#include "../MLX42/include/MLX42/MLX42.h"

#define TRUE 1
#define FALSE 0
#define tile_size 64
#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 768
#define FOV_ANGLE (80 * M_PI / 180)
#define NUM_RAYS WINDOW_WIDTH
#define SACALE_FACTOR 0.5
#define texture_hight 64
#define texture_width 64



typedef struct s_Player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turnDirection;
	int		walkDirection;
	float	rotation_angle;
	float	walkSpeed;
	float	turnSpeed;
    int     turnDirection2;
    int     sideWalkDirection;
	
} t_Player;

typedef struct info
{
    int		facingDown;
	int		facingRight;
	float	xIntercept;
	float	yIntercept;
	float	xStep;
	float	yStep;
	float	wallHitX;
	float	wallHitY;
	int		wallContent;
	float	nextX;
	float	nextY;
	float	xCheck;
	float	yCheck;
	int		foundWallHit;
} info;


typedef struct s_Ray
{
    float   rayAngle;
    float   wallHitX;
    float   wallHitY;
    float   distance;
    int     wasHitVertical;
    int     wasHitHorz;
    int     isFacingUp;
    int     isFacingDown;
    int     isFacingLeft;
    int     isFacingRight;
    int     wallHitContent;
} t_Rays;

typedef struct s_cub3d
{
    mlx_t			*mlx;
    mlx_image_t		*image;
    t_Player			*p;
    t_Rays			rays[NUM_RAYS];
    mlx_texture_t   *texture[4];
    uint32_t		*choice;
    uint32_t		**tab;
    char			**map;
    unsigned int    map_num_rows;
    unsigned int   	map_num_cols;
	uint32_t		F;
	uint32_t		C;
    char *NO;
    char *SO;
    char *WE;
    char *EA;
} t_cub3d;





void	check_syntax(char *file, int ac);
char	*ft_substr2(char *s, unsigned int start, size_t len);
char	*ft_strchr1(char *s, int i);
char	*ft_strdup2(char *s1);
char	*ft_strjoin2(char *s1, char *s2);
int		parsing(char **map, int file, t_cub3d *player);
int		ft_strncmp2(char *s1, char *s2, size_t n);
int		check_fsl(char *str, t_cub3d *p);
int		map_handling(char **fsl, char **map, int file, t_cub3d *p);
int		check_fcc(char **fsl, t_cub3d *p); 
int		check_player(char **map, t_cub3d *p, char *tmp);
int		fc_space(char *s, int *k);
size_t	ft_strlcpy2(char *dst,  char *src, size_t dstsize);
size_t	ft_strlcat2(char *dst, char *src, size_t dstsize);
char	**ft_split2(char *s, char c);
size_t	ft_strlen2(char *str);
char	**read_map_file(int file);
int		ft_atoi2(const char *str);
void	free_2darray(char **array);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strchr2(char *s, int i);
void	check_limits(char **map, int i, int k);
int     
is_surrounded(char **map, int i, int j, char p);
int		check_if_map_closed(char **map, int i, char c, char p);
int		*store_colors(char **var);
void	store_fc(char **fsl, int i, t_cub3d *p, char **var);
int		check_fcc(char **fsl, t_cub3d *p);
int		fc_space(char *s, int *k);
void	free_2darray(char **array);
int 	check_empty_line(char **map, int map_size);
int		duplicate_elemnts_checker(char **fsl);
void	replace_spaces_with_2(char **map);
int		get_max_length(char **map);
void	copy_row(char **rectangle_map, char **map, int i, int max_length);
int		calculate_max_length(char **map);
char	**full_map(char **map, t_cub3d *p);
int			map_has_wall_at(t_cub3d *cub,float x, float y);
void		ft_horizentalIntersection(float rayAngle, int id, info * info1, t_cub3d *cub);
void		ft_verticalIntersection(float rayAngle, int id, info * info2, t_cub3d *cub);
void		ft_chooseSmallestDistance(info info1, info info2, int id, float rayAngle, t_cub3d *cub);
void    	ft_hook(void* param);
void    	ft_my_keyhook(mlx_key_data_t keydata, void *param);
void		ft_render_map(t_cub3d *cub);
void		ft_render_player(t_cub3d *cube);
void		ft_move_player(t_cub3d *cub);
void		ft_cast_rays(t_cub3d *cub);
void		ft_generate_projection(t_cub3d *cub, uint32_t tile_color);
void		ft_DDA(int X0, int Y0, int X1, int Y1, t_cub3d *cub);
uint32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);





#endif