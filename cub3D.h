/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlaouedj <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 13:22:47 by mlaouedj          #+#    #+#             */
/*   Updated: 2021/11/05 13:22:51 by mlaouedj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "gnl/get_next_line.h"
# include "mlx_linux/mlx.h"
# include <string.h>
# define PI 3.1415926535
# define S_WIDTH 1000
# define S_HEIGHT 1000
# define B_SIZE 100

typedef struct s_color
{
	char	*str;
	char	*col1;
	char	*col2;
	char	*col3;
	long	color;
}		t_color;

typedef struct s_ray
{
	double	*hypo;
	double	dist;
	int		wall_height;
	int		f_wall_height;
	char	dir;
}			t_ray;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
}			t_img;

typedef struct s_text
{
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		bit_per_pixel;
	int		line_lenght;
	int		endian;
}			t_text;

typedef struct s_player
{
	double	x;
	double	y;
	double	hit1_x;
	double	hit1_y;
	double	hit2_x;
	double	hit2_y;
	double	f_hit_x;
	double	f_hit_y;
	char	dir;
	int		angle;
}			t_player;

typedef struct s_map
{
	int		g_height;
	int		g_width;
	char	**grid;

}			t_map;

typedef struct s_arg
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_color	f;
	t_color	c;
	int		nb_line;
	int		nb_empty;
}			t_arg;

typedef struct s_mlx
{
	void		*mlx;
	void		*win;
	t_img		buff01;
	t_img		buff02;
	t_text		text_e;
	t_text		text_w;
	t_text		text_n;
	t_text		text_s;
	t_player	player;
	t_ray		ray;
	t_map		map;
	t_arg		arg;
	int			frame;
}				t_mlx;

char			*ft_strdup(char *str);
char			*ft_strndup_1(char *str, int n);
int				ft_atoi(const char *str);
int				ft_check_file(char *file);
int				ft_args(int ac, char **av);
void			my_pixel_put(t_img *img, int x, int y, int color);
void			ft_draw_col_c(t_img *buff, int x, int len, int color);
void			ft_draw_col_f(t_img *buff, int x, int len, int color);
void			ft_draw_t_col(t_mlx *mlx, t_img *buff, int x, int y);
double			ft_move_angle(double angle, double move);
void			ft_vector_1(t_mlx *mlx, t_img *buff);
void			ft_vector_2(t_mlx *mlx, double angle, double tmp);
int				ft_angle(double angle);
double			ft_ray_caster(t_mlx *mlx, double x, double y, double angle);
double			ft_east(t_mlx *mlx);
double			ft_west(t_mlx *mlx);
double			ft_south(t_mlx *mlx);
double			ft_north(t_mlx *mlx);
double			ft_se(t_mlx *mlx, double x, double y, double angle);
double			ft_se_1(t_mlx *mlx, double x, double y, double angle);
double			ft_se_2(t_mlx *mlx, double x, double y, double angle);
double			*ft_se_x(t_mlx *mlx, double x, double y, double angle);
double			ft_se_x_1(t_mlx *mlx, double x, double y, double angle);
double			*ft_se_y(t_mlx *mlx, double x, double y, double angle);
double			ft_se_y_1(t_mlx *mlx, double x, double y, double angle);
double			ft_sw(t_mlx *mlx, double x, double y, double angle);
double			ft_sw_1(t_mlx *mlx, double x, double y, double angle);
double			ft_sw_2(t_mlx *mlx, double x, double y, double angle);
double			*ft_sw_x(t_mlx *mlx, double x, double y, double angle);
double			ft_sw_x_1(t_mlx *mlx, double x, double y, double angle);
double			*ft_sw_y(t_mlx *mlx, double x, double y, double angle);
double			ft_sw_y_1(t_mlx *mlx, double x, double y, double angle);
double			ft_nw(t_mlx *mlx, double x, double y, double angle);
double			ft_nw_1(t_mlx *mlx, double x, double y, double angle);
double			ft_nw_2(t_mlx *mlx, double x, double y, double angle);
double			*ft_nw_x(t_mlx *mlx, double x, double y, double angle);
double			ft_nw_x_1(t_mlx *mlx, double x, double y, double angle);
double			*ft_nw_y(t_mlx *mlx, double x, double y, double angle);
double			ft_nw_y_1(t_mlx *mlx, double x, double y, double angle);
double			ft_ne(t_mlx *mlx, double x, double y, double angle);
double			ft_ne_1(t_mlx *mlx, double x, double y, double angle);
double			ft_ne_2(t_mlx *mlx, double x, double y, double angle);
double			*ft_ne_x(t_mlx *mlx, double x, double y, double angle);
double			ft_ne_x_1(t_mlx *mlx, double x, double y, double angle);
double			*ft_ne_y(t_mlx *mlx, double x, double y, double angle);
double			ft_ne_y_1(t_mlx *mlx, double x, double y, double angle);
char			ft_check_hit(t_mlx *mlx, char hit, double x, double y);
int				ft_init_texture(t_mlx *mlx);
void			ft_init_texture_2(t_mlx *mlx);
double			ft_hit(t_mlx *mlx);
unsigned int	ft_get_pixel(t_mlx *mlx, t_text *text,
					int w_pix, int w_size);
t_text			*ft_choose_text(t_mlx *mlx);
int				ft_next_frame(int keycode, t_mlx *mlx);
void			ft_keycode(int keycode, t_mlx *mlx);
void			ft_turn(int keycode, t_mlx *mlx);
void			ft_move(int keycode, t_mlx *mlx);
void			ft_display_map(t_mlx *mlx);
int				ft_get_direction(char direction);
int				ft_get_position_1(t_mlx *mlx);
int				ft_get_position_2(t_mlx *mlx, int i, int j, int *res);
int				ft_get_opt(t_mlx *mlx, char *file);
int				ft_get_text(t_mlx *mlx, char *line, int *res);
int				ft_get_color(t_mlx *mlx, char *line, int *res);
void			ft_get_g_dim(t_mlx *mlx, char *file);
int				ft_get_infos(t_mlx *mlx, char *file);
int				ft_parse_text(t_mlx *mlx);
int				ft_space(char *str);
int				ft_check_text(char *str, char *text);
char			*ft_text(char *str);
int				ft_is_opt(char *opt, char *line);
int				ft_empty_line(char *str);
int				ft_is_line(char *str);
int				ft_count_lines(t_mlx *mlx, char *file);
void			ft_replace_dir(t_mlx *mlx);
char			*ft_fill_line(t_mlx *mlx, char *str);
void			ft_replace_spaces(char *str);
void			ft_fill_grid(t_mlx *mlx);
int				ft_check_map_sides_1(t_mlx *mlx);
int				ft_check_map_sides_2(t_mlx *mlx);
int				ft_check_inside_grid_1(t_mlx *mlx);
int				ft_check_inside_grid_2(t_mlx *mlx, int i, int j);
int				ft_parse_map(t_mlx *mlx);
int				ft_is_num(char c);
char			*ft_get_colors(char *str);
int				ft_check_color_str(char *str);
int				ft_check_colors_1(t_color *color);
int				ft_check_colors_2(t_color *color, int i, int j);
int				ft_parse_colors(t_mlx *mlx);
char			*ft_int_to_hex(unsigned long nb);
long			ft_hexa_to_int(char *str);
int				ft_convert_rgb_1(t_color *color);
char			*ft_convert_rgb_2(char *res, char *s1, char *s2, char *s3);
void			ft_init_data(t_mlx *mlx);
void			ft_free_grid(t_map *map);
void			ft_free_text(t_arg *arg);
void			ft_free_colors(t_arg *arg);
void			ft_free_data(t_mlx *mlx);
int				ft_exit(t_mlx *mlx);
int				ft_checking(t_mlx *mlx, int ac, char **av);

#endif
