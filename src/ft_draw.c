#include "../cub3D.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if ((x >= 0 && x <= S_WIDTH) && (y >= 0 && y <= S_HEIGHT))
	{
		dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_draw_col_c(t_img *buff, int x, int len, int color)
{
	int	i;

	i = 0;
	while (i < len)
	{
		my_pixel_put(buff, x, 0 + i, color);
		i++;
	}
}

void	ft_draw_col_f(t_img *buff, int x, int len, int color)
{
	int	i;

	i = 0;
	while (i < len)
	{
		my_pixel_put(buff, x, (S_HEIGHT / 2) + i, color);
		i++;
	}
}

void	ft_draw_t_col(t_mlx *mlx, t_img *buff, int x, int y)
{
	int				i;
	t_text			*texture;
	unsigned int	color;

	i = 0;
	texture = ft_choose_text(mlx);
	while (i < mlx->ray.f_wall_height)
	{
		color = ft_get_pixel(mlx, texture, i, mlx->ray.f_wall_height);
		my_pixel_put(buff, x, y + i, color);
		i++;
	}
}
