/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msekhsou <msekhsou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 10:27:19 by msekhsou          #+#    #+#             */
/*   Updated: 2024/01/26 21:12:56 by msekhsou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

# define TRUE 1
# define FALSE 0
# define TL_SZ 64
# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 768
# define FOV_ANGLE 1.396263
# define NUM_RAYS WINDOW_WIDTH
# define SACALE_FACTOR 0.5
# define TEXTURE_HIGHT 128
# define TEXTURE_WIDTH 128

typedef struct s_Player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
	int		turn_direction2;
	int		sidewalk_direction;

}	t_Player;

typedef struct s_info
{
	int		fc_dn;
	int		fc_rt;
	float	x_intercept;
	float	y_intercept;
	float	x_step;
	float	y_step;
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_data;
	float	next_x;
	float	next_y;
	float	x_check;
	float	y_check;
	int		fnd_wl_hit;
}	t_info;

typedef struct s_Ray
{
	float	ray_angle;
	float	wall_hit_x;
	float	wall_hit_y;
	float	distance;
	int		was_hit_vertical;
	int		was_hit_horz;
	int		isfc_dn;
	int		isfc_rt;
	int		wall_hit_content;
}	t_Rays;

typedef struct s_cub3d
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	t_Player		*p;
	t_Rays			rays[NUM_RAYS];
	mlx_texture_t	*txt[4];
	uint32_t		*choice;
	uint32_t		**tab;
	char			**map;
	char			**tmp_map;
	unsigned int	map_num_rows;
	unsigned int	map_num_cols;
	uint32_t		f;
	uint32_t		c;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
}	t_cub3d;

void		check_syntax(char *file, int ac);
void		free_struct_content(t_cub3d *p);
char		*ft_substr2(char *s, unsigned int start, size_t len);
char		*ft_strchr1(char *s, int i);
char		*ft_strdup2(char *s1);
char		*ft_strjoin2(char *src, char *dst);
int			parsing(char **map, int file, t_cub3d *player);
int			ft_strncmp2(char *s1, char *s2, size_t n);
int			check_fsl(char *str, t_cub3d *p);
int			map_handling(char **fsl, char **map, int file, t_cub3d *p);
int			check_fcc(char **fsl, t_cub3d *p);
int			check_player(char **map, t_cub3d *p, char *tmp);
int			fc_space(char *s, int *k);
size_t		ft_strlcpy2(char *dst, char *src, size_t dstsize);
size_t		ft_strlcat2(char *dst, char *src, size_t dstsize);
char		**ft_split2(char *s, char c);
size_t		ft_strlen2(char *str);
char		**read_map_file(int file);
int			ft_atoi2(const char *str);
void		free_2darray(char **array);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr2(char *s, int i, int j);
void		check_limits(char **map, int i, int k);
int			is_surrounded(char **map, int i, int j, char p);
int			check_if_map_closed(char **map, int i, char c, char p);
int			*store_colors(char **var);
void		store_fc(char **fsl, int i, t_cub3d *p, char **var);
int			check_fcc(char **fsl, t_cub3d *p);
int			fc_space(char *s, int *k);
void		fd_error(int fd);
void		map_error(char **map);
void		free_2darray(char **array);
void		free_map(char **map);
int			check_empty_line(char **map, int map_size);
int			is_dup(char **fsl);
void		replace_spaces_with_2(char **map);
void		copy_row(char **rectangle_map, char **map, int i, int max_length);
void		init_texture(t_cub3d *p, mlx_image_t **img);
char		**full_map(char **map, t_cub3d *p);
int			map_has_wall_at(t_cub3d *cub, float x, float y);
int			count_map_lines(char **map);
void		ft_horizental_intersection(float ray_angle, \
				t_info *info1, t_cub3d *cub);
void		ft_vertical_intersect(float ray_angle, t_info *info2, t_cub3d *cub);
void		ft_choose_small_dist(t_info info1, t_info info2, \
				int id, t_cub3d *cub);
void		ft_hook(void *param);
void		ft_update(void *param);
void		ft_render(void *param);
void		ft_my_keyhook(mlx_key_data_t keydata, void *param);
void		ft_render_map(t_cub3d *cub);
void		ft_render_player(t_cub3d *cube);
void		ft_move_player(t_cub3d *cub);
void		ft_cast_rays(t_cub3d *cub);
void		ft_generate_projection(t_cub3d *cub, uint32_t tile_color);
void		ft_dda(int *Tx, int *Ty, t_cub3d *cub);
void		norm_mlx_hk(mlx_t *mlx, t_cub3d *player);
uint32_t	ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a);

#endif