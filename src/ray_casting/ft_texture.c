#include "../../cub3D.h"

double	ft_texture(t_mlx *mlx, char dir)
{
	double hit;

	if (dir == 'e')
		hit = mlx->player.f_hit_y - (int)mlx->player.f_hit_y;
	else if (dir == 's')
		hit = mlx->player.f_hit_x - (int)mlx->player.f_hit_x;
	else if (dir == 'w')
		hit = (int)mlx->player.f_hit_y + 1 - mlx->player.f_hit_y;
	else if (dir == 'n')
		hit = (int)mlx->player.f_hit_x + 1 - mlx->player.f_hit_x;
	return (hit);	
}

unsigned int	ft_get_pixel(t_text *text, int w_pix, int w_size, double hit)
{
	int	x;
	int	y;
	x = (int)nearbyint(hit * (double)text->img_width);
	y = (int)nearbyint(((double)w_pix / (double)w_size) * text->img_height);
	return *(unsigned int*)(text->addr + (y * text->line_lenght + x * (text->bit_per_pixel / 8)));
}

void	ft_draw_t_col(t_mlx *mlx, t_img *buff, int x, int y, int w_size, double hit, t_text *text)
{
	int		i;
	unsigned int	color;

	i = 0;
	(void)mlx;
	while (i < w_size)
	{
		color = ft_get_pixel(text, i, w_size, hit);
		my_pixel_put(buff, x, y + i, color);
		i++;
	}
}
