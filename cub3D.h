#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <math.h>
#include "gnl/get_next_line.h"
#include "mlx_linux/mlx.h"

#include <string.h>

#define PI 3.1415926535
#define S_WIDTH 1000
#define S_HEIGHT 1000
#define B_SIZE 100


typedef struct s_img
{
	void	*img;
	char	*addr;
	int	bpp;
	int	l_len;
	int	endian;
}		t_img;

typedef struct	s_text
{
	void	*img;
	char	*addr;
	int	img_width;
	int	img_height;
	int	bpp;
	int	l_len;
	int	endian;
}		t_text;

typedef struct	s_player
{
	float	x;
	float	y;
	double	hit1_x;
	double	hit1_y;
	double	hit2_x;
	double	hit2_y;
	char	dir;
	int	angle;
}		t_player;

typedef struct	s_map
{
	int	g_height;
	char	**grid;

}		t_map;

typedef struct	s_arg
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}		t_arg;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		buff01;
	t_img		buff02;
	t_text		text;
	t_player	player;
	t_map		map;
	t_arg		arg;
	int		frame;
}			t_mlx;
//.........................................................UTILS
char	*ft_strdup(char *str);
char	*ft_strndup(char *str, int n);
int	ft_check_file(char *file);
int	ft_args(int ac , char **av);
//.........................................................DRAW
void	my_pixel_put(t_img *img, int x, int y, int color);
void    ft_draw_line(t_img *buff, int x, int y);
void    ft_draw_block(t_img *buff, int x, int y);
void    ft_draw_map(t_mlx *mlx, t_img *buff);
void	ft_draw_col(t_img *buff, int x, int y, int len, int color);
void    ft_draw_lin(t_img *buff, int x, int y, int len, int color);
void	ft_draw_text(t_mlx *mlx, t_img *buff, int x, int y, int len);
void	ft_draw_grid(t_mlx *mlx, t_img *buff);
//...........................................................RAY
void	ft_vision(t_mlx *mlx, t_img *buff);
void    ft_raycast(t_mlx *mlx, t_img *buff, float angle);
int	ft_get_len(float cos, float sin);
void	ft_vector(t_mlx *mlx, t_img *buff);
int	ft_angle(int angle);
double	ft_ray_caster(t_mlx *mlx, double x, double y, double angle);
//...........................................................DIRECTION
double  ft_se(t_mlx *mlx, double x, double y, double angle);
double  ft_sw(t_mlx *mlx, double x, double y, double angle);
double  ft_nw(t_mlx *mlx, double x, double y, double angle);
double	ft_ne(t_mlx *mlx, double x, double y, double angle);
char	ft_check_hit(t_mlx *mlx, char hit, double x, double y);
//...........................................................FRAME
int	ft_next_frame(int keycode, t_mlx *mlx);
//...........................................................KEYCODE
void	ft_keycode(int keycode, t_mlx *mlx);
void	ft_turn(int keycode, t_mlx *mlx);
void	ft_move(int keycode, t_mlx *mlx);
//...........................................................DISPLAY
void	ft_display_map(t_mlx *mlx);
//...........................................................FILE INFOS (MAP)
int     ft_get_direction(char direction);
int     ft_get_position(t_mlx *mlx);
//int	ft_get_text(t_mlx *mlx, char *file);
//int	ft_get_map(t_mlx *mlx, char *file);
int	ft_get_infos(t_mlx *mlx, char *file);
//...........................................................PARSING
int	ft_parse_text(t_mlx *mlx);
int	ft_space(char *str);
int	ft_check_text(char *str, char *text);
char	*ft_text(char *str);
