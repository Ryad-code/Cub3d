#include "../cub3D.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;

	if ((x >= 0 && x <= 1000) && (y >= 0 && y <= 1000))
	{
		dst = img->addr + (y * img->l_len + x * (img->bpp / 8));
		*(unsigned int*)dst = color;
	}
}

void	ft_draw_line(t_img *buff, int x, int y)
{
	int	i;

	i = 0;
	while (i < B_SIZE)
	{
		my_pixel_put(buff, x, y + i, 0x0000FF);
		i++;
	}
}

void    ft_draw_block(t_img *buff, int x, int y)
{
	int	i;

	i = 0;
	while (i < B_SIZE)
	{
		ft_draw_line(buff, x + i, y);
		i++;
	}
}

void	ft_draw_map(t_mlx *mlx, t_img *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < mlx->map.g_height)
	{
		while (mlx->map.grid[i][j])
		{
			if (mlx->map.grid[i][j] == '1')
				ft_draw_block(buff, j * B_SIZE, i * B_SIZE);
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_draw_col(t_img *buff, int x, int y, int len, int color)
{
	int i;

	i = 0;
	while (i < len)
	{
		my_pixel_put(buff, x, y + i, color);
		i++;
	}
}

void    ft_draw_lin(t_img *buff, int x, int y, int len, int color)
{
	int i;

	i = 0;
	while (i < len)
	{
		my_pixel_put(buff, x + i, y, color);
		i++;
	}
}

unsigned int	ft_get_pixel(t_mlx *mlx, int x, int y)
{
	return (*(unsigned int*)(mlx->text.addr + (y * mlx->text.l_len + x * (mlx->text.bpp / 8))));
}

void	ft_draw_text(t_mlx *mlx, t_img *buff, int x, int y, int len)
{
	int		i;
	unsigned int	color;

	i = 0;
	while (i < len)
	{
		color = ft_get_pixel(mlx, x, y);
		my_pixel_put(buff, x, y + i, color);
		i++;
	}
}

void	ft_draw_grid(t_mlx *mlx, t_img *buff)
{
	int i;
	int j;

	i = 0;
	j = 0;
	(void)mlx;
	while (i < 10)
	{
		ft_draw_col(buff, j, 0, 1000, 0xFFFFFF);
		ft_draw_lin(buff, 0, j, 1000, 0xFFFFFF);
		i++;
		j += 100;
	}
}
